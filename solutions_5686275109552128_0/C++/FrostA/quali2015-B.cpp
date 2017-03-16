// #include <bits/stdc++.h>
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "math.h"
#include "queue"
#include "map"
#include "set"
#include "stack"
#include "fstream"
#include "cstring"
#include "string"
#define L(x) (x<<1+1)
#define R(x) (x<<1+2)
#define REP(a,b) for(int a=0;a<b;a++)
#define REP1(a,b) for(int a=1;a<=b;a++)
#define RREP(a,b) for(int a=b-1;a>=0;a--)
#define RREP1(a,b) for(int a=b;a>0;a--)
#define ITR(a,b) for(;a!=b;a++)
using namespace std;
#define P 1000000007LL
#define MAXN 100
#define E7 10000000LL
typedef long long ll;

int a[1000];
int main(){
	int T;
	cin>>T;
	REP(cs,T){
		memset(a,0,sizeof(a));
		int d;
		cin>>d;
		int m=0;
		REP(i,d){
			int t;
			cin>>t;
			a[t]++;
			m=max(m,t);
		}
		int ans=m;
		REP1(i,m){
			int c=0;
			REP1(j,m){
				if(j>i)c+=(j/i+(j%i?1:0)-1)*a[j];
				// cout<<i<<' '<<j<<' '<<c<<endl;
			}
			ans=min(ans,i+c);
		}
		// int ans=m;
		// int t=0;
		// RREP1(i,m){
		// 	if(a[i]!=0){
		// 		ans=min(ans,t+i);
		// 	}
		// 	t+=a[i];
		// 	a[i/2]+=a[i];
		// 	a[(i+1)/2]+=a[i];
		// 	a[i]=0;
		// }
		cout<<"Case #"<<(cs+1)<<": "<<ans<<endl;
	}
	return 0;
}
