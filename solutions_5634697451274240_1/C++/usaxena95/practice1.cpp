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


int main(){
	fre;
	int T;
	cin>>T;
	string S;
	rep(t,1,T){
		printf("Case #%d: ",t);
		cin>>S;
		int ans = 0;
		if(S[0]=='-'){
			++ans;
			for(int i=0;i<S.size() and S[i]=='-';++i)S[i]='+';
		}
		for(int i=0;i<S.size();++i){
			if(S[i]=='+' and S[i+1]=='-')
				ans += 2;
		}
		cout<<ans<<'\n';
	}
}
