#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

int main(){
	int t, tc, i;
	double d, n, a, ti[100], xi[100], ai[100];
	cin >> t;
	REP(tc,t){
		cin >> d >> n >> a;
		REP(i,n)cin >> ti[i] >> xi[i];
		REP(i,a)cin >> ai[i];
		printf("Case #%d:",tc+1);
		puts("");
		double ret, time, dis, vel, x;
		REP(i,a){
			ret=sqrt(2.*d/ai[i]);
			if(n==2){
				time=ti[1]-ti[0];
				dis=xi[1]-xi[0];
				vel=dis/time;
				x=(d-xi[0])/vel;
				if(ret<x)ret=x;
			}
			printf("%.7f",ret);
			puts("");
		}

	}
	return 0;
}

