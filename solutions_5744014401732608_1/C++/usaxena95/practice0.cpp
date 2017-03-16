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

int G[654][655];
LL W[654];
int main(){
	fre;
	W[1] = 1;
	W[2] = 1;
	for(int i=3;i<=50;++i){
		W[i] = W[i-1] * 2;
	}
	int T,B;
	LL M;
	cin>>T;
	for(int t=1;t<=T;++t){
		printf("Case #%d:",t);
		cin>>B>>M;
		rep(i,1,B)rep(j,1,B)G[i][j] = 0;

		rep(i,1,B-1){
			rep(j,i+1,B-1){
				G[i][j] = 1;
			}
		}
		for(int i=B-1;i>=1;i--){
			if(M >= W[i]){
				G[i][B] = 1;
				M -= W[i];
			}
		}
		if(M > 0){
			cout<<" IMPOSSIBLE\n";
		}
		else{
			cout<<" POSSIBLE\n";
			rep(i,1,B){
				rep(j,1,B){
					cout<<G[i][j];
				}
				cout<<endl;
			}
		}
	}
}
