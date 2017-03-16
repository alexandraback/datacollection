#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#include <set>	
#include <cstring>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ii, int>	iii;
typedef vector<ii>		vii;
typedef vector<iii>		viii;
typedef vector<int>		vi;
typedef vector<char>	vc;
typedef vector<vc>		vvc;
typedef vector<string>	vs;
typedef unsigned long long	ull;
typedef vector<ull>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265


int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {

		int N;
		cin >> N;
		vd naomi, ken;
		for (int i=0; i<N; i++) {
			double a;
			cin >> a;
			naomi.push_back(a);
		}
		for (int i=0; i<N; i++) {
			double a;
			cin >> a;
			ken.push_back(a);
		}
		
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		
		// Normal war: lowest to highest
		int normal_war_score = N;
		int ken_i = 0;
		for (int i=0; i<N; i++) {
			// take the smallest > naomi[i] for ken
			while (ken_i < N && ken[ken_i] < naomi[i]) {
				ken_i++;
			}
			if (ken_i >= N) {
				// out of range : naomi wins rest
				break;
			} else {
				normal_war_score --; 
			}
			ken_i ++;
		}

		// Deceitful war: lowest to highest
		int deceitful_war_score = 0;
		int ken_max = N-1;
		ken_i = 0;
		for (int i=0; i<N; i++) {

			// if naomi would lose anyway, take highest from ken
			if (naomi[i] < ken[ken_i]) {
			} else {
				ken_i ++;
				deceitful_war_score ++; 
			}
		}


		cout << "Case #"<< t<< ": " << deceitful_war_score << " " << normal_war_score << endl;
	}



	return EXIT_SUCCESS;
}