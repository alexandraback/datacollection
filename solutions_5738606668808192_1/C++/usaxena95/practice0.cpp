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
bool divisible(int b,LL x){
	LL a = 0;
	for(int i=0;i<N;++i){
		if(V[i]==1)
			a = (a + pow(b,i,x))%x;
	}
	return (a%x==0);
}
int check(int b){
	for(int i=2;i<=100;++i){
		if(divisible(b,i)){
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
			for(int i=V.size()-1;i>=0;i--)
				cout<<V[i];
			rep(i,0,8)assert(divisible(i+2,P[i])==1),cout<<' '<<P[i];
			cout<<endl;
		}
	}
}
int main(){
	fre;
	srand(time(NULL));
	int M;
	cin>>N>>M;
	cout<<"Case #1:\n";
	func(M);
}
