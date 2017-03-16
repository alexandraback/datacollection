#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <Windows.h>

#define FORST(X,S,T) for(int X=S; X<=T; X++)  
#define RFORST(X,S,T) for(int X=S; X>=T; X--)  
#define FOR(X,XB) for(int X=0; X<XB; X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) (((X)+(Y))/2)
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)  
#define FILE_W(X) freopen(X, "w", stdout)  
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define SZ(X) sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
using namespace std;

bool checksq(long long p){
	double px = sqrt((double)p);
	if(px != (long long)px) return false;
	return true;
}

bool checkp(long long p){
	int b[20];
	int t = 0;
	while(p){
		b[t++] = p%10;
		p/=10;
	}
	FOR(i, t/2){
		if(b[i]!=b[t-1-i]) return false;
	}
	return true;
}

long long A, B;
int main(){
	int cs;

	FILE_W("output");
	set<long long> pset;
	for(long long x=1; x<=10000000; x++){
		if(checkp(x)){
			if(checkp(SQR(x))){
				pset.insert(SQR(x));
			}
		}
	}

	cin>>cs;
	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);
		cin >> A >> B;
		long long ans = 0;
		set<long long>::iterator r;
		FORSTL(r, pset){
			if(*r>=A && *r<=B){
				ans ++;
			}
		}
		cout << ans << endl;

	}
	return 0;
}