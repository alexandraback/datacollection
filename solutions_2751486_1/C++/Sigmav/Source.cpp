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


bool isCons(char c) {
	return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
}


int main(int argc, char *argv[]){
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		string name;
		int nameL = 0;
		int n;
		cin >> name;
		cin >> n;
		nameL = name.size();
		int total = 0;

		int consecutive = 0;
		int prevStart = -1;

		for (int i=0; i<nameL; i++) {
			
			if (isCons(name[i])) {
				consecutive ++;
			}
			else {
				consecutive = 0;
			}

			if (consecutive >= n) {
				total += ((i-n+2) * (nameL-i));
				if (prevStart!=-1) {
					total -= (prevStart * (nameL-i));
				}
				prevStart = (i-n+2);
			}
		}

		cout << "Case #"<< t << ": " << total << endl;

	}



	return EXIT_SUCCESS;
}