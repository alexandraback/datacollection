#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int main(){
	int T;
	cin >> T;
	REP(testCase, T){
		int A, B, K;
		cin >> A >> B >> K;
		int res = 0;
		REP(a, A)REP(b, B){
			if ((a&b) < K){
				res++;
			}
		}
		cout << "Case #" << testCase + 1 << ": " << res << endl;
	}
}