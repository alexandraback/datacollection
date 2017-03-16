#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <math.h>

#define REP(i,a,b) for(int i=a;i<=b;i++)
#define sf scanf
#define pf printf
#define ll long long 

using namespace std;
const int MAXN = 1005;

ll p,q;
int ans;

int main(){

	int t; sf("%d",&t);
	REP(it,1,t){
		sf("%lld/%lld",&p,&q);
		
		int d = 0;ans = -1; bool flag = false;
		while ( d<=41&&!flag ){
			while ( p<q ){
				p<<=1; d++;
			}
			p -= q;
			if ( ans==-1 ) ans = d;
//			cout<<p <<' '<<q<<endl;
			if ( p==0 ) flag = true;
		}
		pf("Case #%d: ",it);
		if (!flag) pf("Impossible\n");
		else pf("%d\n" ,ans);
	}

	return 0;
}