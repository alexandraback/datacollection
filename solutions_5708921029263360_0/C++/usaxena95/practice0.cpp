/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define LL signed long long int
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
#define pii pair<int,int>
int A,B,C,K;
struct st{
	int a,b,c;
	st(){}
	st(int x,int y,int z){
		a=x;
		b=y;
		c=z;
	}
};
vector<st>ans,V;
int ab[654];
int bc[6555];
int ca[6555];

int heuristic(st x){
	int a,b,c;
	a = K - ab[x.a*10+x.b];
	b = K - bc[x.b*10+x.c];
	c = K - ca[x.c*10+x.a];
	if(x.a==0 or x.b==0 or x.c==0 or a==0 or b==0 or c==0)
		return -MOD;
	return a+b+c;
}
int main(){
	fre;
	int T;
	cin>>T;
	for(int t=1;t<=T;++t){
		ans.clear();
		V.clear();
		cin>>A>>B>>C>>K;
		rep(i,0,300)ab[i] = bc[i] = ca[i] = 0;

		rep(i,1,A)rep(j,1,B)rep(k,1,C){
			V.push_back(st(i,j,k));
		}
		while(1){
			int best = 0;
			for(int i=0;i<V.size();++i){
				if(heuristic(V[i]) >= heuristic(V[best])){
					best = i;
				}
			}
			st x = V[best];
			if(heuristic(x)==-MOD)
				break;

			ans.push_back(V[best]);
			ab[x.a*10+x.b]++;
			bc[x.b*10+x.c]++;
			ca[x.c*10+x.a]++;

			V[best].a = V[best].b = V[best].c = 0;
		}
		printf("Case #%d: %d\n",t,ans.size());
		rep(i,0,ans.size()-1){
			cout<<ans[i].a<<' '<<ans[i].b<<' '<<ans[i].c<<endl;
		}
	}
}
