#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define ps system("pause")
#define message printf("*\n")
#define pb push_back
#define X first
#define Y second
#define PII pair<int,int>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)

typedef long long ll;

using namespace std;

ll p,q;
int n;

ll gcd(ll a,ll b){
	if	(b==0)	return	a;
	return	gcd(b,a%b);
}

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%I64d/%I64d",&p,&q);
		while	(gcd(p,q)!=1){
			ll g=gcd(p,q);
			p/=g;q/=g;
		}
		int a,b,f=0;
		for	(a=0;q>1;){
			a++;
			if	(q%2)	f=1;
			q/=2;
		}
		for	(b=0;p>1;p/=2)	b++;
		printf("Case #%d: ",i);
		if	(f)	printf("impossible\n");	else	printf("%d\n",a-b);
	}
}


