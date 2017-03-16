#include <bits/stdc++.h>
#include <ext/numeric>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;

#define oo			1e9
#define OO			1e18
#define EPS			1e-7
#define f			first
#define s			second
#define pi 			acos(-1.0)
#define ll			long long
#define ld			long double
#define ull			unsigned long long
#define sz(x)		(int)x.size()
#define all(x)		x.begin(),x.end()
#define rall(x)		x.rbegin(),x.rend()
#define popCnt(x)   __builtin_popcount(x)

int T;
string str;

bool done(){
	return (count(all(str),'+')==sz(str));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%d",&T);
	for(int C=1;C<=T;C++){
		cin>>str;
		int stp=0,idx;
		while(!done()){
			stp++;
			for(idx=0;idx<sz(str);idx++)
				if(str[idx]!=str[0])break;
			for(int i=0;i<idx;i++)
				str[i]=(str[i]=='+'?'-':'+');
		}
		printf("Case #%d: %d\n",C,stp);
	}
}
