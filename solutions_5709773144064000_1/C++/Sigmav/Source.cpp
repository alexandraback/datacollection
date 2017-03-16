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

		double C,F,X;
		double cps = 2.0;
		cin >> C >> F >> X;

		// 0 farms
		double best_time = X / cps;

		
		double time_used = 0;

		while (1) {
			time_used += C / cps;
			cps += F;
			if (time_used + X/cps < best_time) {
				best_time = time_used + X/cps;
			} else break;
		}

		
		cout.precision(7);
		cout << "Case #"<< t<< ": " << fixed << best_time << endl;
	}



	return EXIT_SUCCESS;
}