#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define EPS 1E-12
const int INF = (int)1E9;

double C,F,X;
int main(){
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		cin >> C >> F >> X;
		double S = 2;
		double t = 0;
		while(1){
			if(X*(1.0-S/(S+F)) > C){
				t += C/S;
				S += F;
			}else{
				t += X/S;
				break;
			}
		}
		printf("Case #%d: %.7f\n", csn, t);
	}
	return 0;
}