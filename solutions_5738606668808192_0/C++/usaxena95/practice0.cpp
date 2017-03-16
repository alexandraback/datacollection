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
vector<int>V;
LL pow(LL base, LL exponent,LL modulus)
{
	LL result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int N,p;
bool divisible(int b,int x){
	int a = 0;
	for(int i=0;i<N;++i){
		if(V[i]==1)
			a = (a + pow(b,i,x))%x;
	}
	return (a==0);
}
int check(int b){
	LL p = 0;
	for(int i=0;i<N;++i){
		p += V[i]*pow(b,i,1000000000000000000LL);
	}

	for(int i=2;i<=10;++i){
		if(divisible(b,i))
		{
			assert(p%i==0);
			return i;
		}
	}
	return 0;
}
map<vector<int>,int >mp;
void func(int M){
	rep(i,1,N)V.push_back(0);

	vector<int>P;
	V[0] = V[N-1] = 1;
	while(M){
		P.clear();
		for(int i=1;i<N-1;++i){
			V[i] = rand()%2;
		}
		int ok = 1;
		for(int b=2;b<=10 and ok;++b){
			int x = check(b);
			if(x==0){
				ok = 0;
			}
			else{
				P.push_back(x);
			}
		}
		if(ok and mp[V]==0){
			mp[V] = 1;
			cerr<<M<<endl;
			--M;
			rep(i,0,N-1)
				cout<<V[i];
			rep(i,0,8)cout<<' '<<P[i];
			cout<<endl;
		}
	}
}
int main(){
	fre;
	int M;
	cin>>N>>M;
	cout<<"Case #1:\n";
	func(M);
}
