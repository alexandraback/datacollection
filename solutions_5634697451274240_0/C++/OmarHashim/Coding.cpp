#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

char x[110];
int t;
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	sc(t);
	lop(C,t){
		scanf(" %s",&x);
		int n=strlen(x),out=0;
		lop(i,n-1){
			out+=(x[i]!=x[i+1]);
		}
		printf("Case #%d: %d\n",C+1,out+(x[n-1]=='-'));
	}
}
