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

vector<int> G[2*100000+5];
int dig(int x){
	int ans = 0;
	while(x>0){
		int r = x%10;
		x /= 10;
		ans |= (1<<r);
	}
	return ans;
}
int main(){
	fre;
	int T;
	cin>>T;
	rep(t,1,T){
		printf("Case #%d: ",t);
		int N;
		cin>>N;
		int till = 0;
		int last = -1;
		for(int i=1;N>0;++i){
			till |= dig(i*N);
			if(till==1023){
				last = i*N;
				break;
			}
		}
		if(last==-1)
			cout<<"INSOMNIA\n";
		else{
			cout<<last<<'\n';
		}
	}
}
