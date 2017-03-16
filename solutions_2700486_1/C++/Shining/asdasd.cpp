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

long double res,cur;
vector<long double> s[2];
const long double eps=1e60;
ll cnt=0;
int T,n,x,y,k,Cur;

int main(){
	freopen("1.in","r",stdin);
	freopen("K.out","w",stdout);
	scanf("%d",&T);
	rep(vv,1,T){
		scanf("%d%d%d",&n,&x,&y);
		x=abs(x);
		for	(int i=0;i<x+y;i+=2)	n-=i*2+1;
		k=(x+y)*2+1;
		if (n<0) 			printf("Case #%d: %.10lf\n",vv,0.0);
		else	if (n>k)	printf("Case #%d: %.10lf\n",vv,1.0);
		else	if	(!x)	printf("Case #%d: %.10lf\n",vv,(n==k)?(1.0):(0.0));
		else{
			cur=1;cnt=0;
			rep(i,1,n){
				cur/=2;
				if	(cur<1/eps){
					cnt--;
					cur*=eps;
				}
			}
			s[0].clear();s[1].clear();res=0;Cur=0;
			rep(i,0,n){
				if	(i)	cur=cur*(n-i+1)/i;
				if	(max(n-x-y,i)>y)	res+=cur;
				if	(res>eps){
					s[Cur].pb(res/eps);
					res=0;
				}
			}
			if	(cnt<0)	res/=eps;
			s[Cur].pb(res);cnt++;
			while	(cnt<0){
				s[1-Cur].clear();
				int all=s[Cur].size()-1;
				res=0;
				rep(i,0,all){
					res+=s[Cur][i];
					if	(res>eps){
						s[1-Cur].pb(res/eps);
						res=0;
					}
				}
				s[1-Cur].pb(res/eps);
				Cur=1-Cur;cnt++;
			}
			printf("Case #%d: %.10lf\n",vv,double(s[Cur][0]));
		}
	}
}


