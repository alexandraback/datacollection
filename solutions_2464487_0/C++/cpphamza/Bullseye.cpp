//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<cstring>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big unsigned long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main(){

	//freopen("1.in", "rt", stdin);
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);

	int TT; cin >> TT;
	for(int t = 1 ; t <= TT ; t++){
		big R, T; cin >> R >> T;

		big low = 1, high = 2000000000, best = -1;

		while(low <= high){
			big i = (low+high)/2;
			big cur = 2*R*i+2*i*i-i;

			if(cur <= T){
				best = i;
				low = i+1;
			}else
				high = i-1;
		}

		cout << "Case #" << t << ": " << best << endl;
	}

	return 0;
}
