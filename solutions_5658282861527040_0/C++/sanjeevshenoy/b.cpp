#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <limits>
#include <cassert>
#include <sstream>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii ;
typedef pair<pii,int> ppi ;

const int max_n=100010;

int n,T;
//ll dp[33][2][2][2];
//bool B[33][2][2][2];


map<ppi,ll> dp;
map<ppi,bool> B;

int f(int p, int a)
{
	return a&(1<<p)?(1<<p)-1:a;
}

ll rec(int p, int a, int b, int k)
{
	if(p==-1)
		return 1;

	/*bool b1=(a==(1<<p)-1);
	bool b2=(b==(1<<p)-1);
	bool b3=(k==(1<<p)-1);*/

	//if(B[p][b1][b2][b3])
		//return dp[p][b1][b2][b3];

	ppi P=ppi(pii(a,b),k);
	if(B[P])
		return dp[P];

	//0 0
	ll res=0ll;
	res+=rec(p-1,f(p,a),f(p,b),f(p,k));

	//0,1
	if(b&(1<<p))
		res+=rec(p-1,f(p,a),b-(1<<p),f(p,k));
	//1,0
	if(a&(1<<p))
		res+=rec(p-1,a-(1<<p),f(p,b),f(p,k));

	//1,1
	if(a&(1<<p) and b&(1<<p) and k&(1<<p))
		res+=rec(p-1,a-(1<<p),b-(1<<p),k-(1<<p));

	//B[p][b1][b2][b3]=1;

	//cout<<p<<" "<<a<<" "<<b<<" "<<k<<" "<<res<<endl;

	B[P]=1;
	//return dp[p][b1][b2][b3]=res;
	return dp[P]=res;
}

int main()
{
	scanf("%d",&T);

	for(int z=0; z<T; z++)
	{
		int a,b,k;
		cin>>a>>b>>k;
		a--;b--;k--;
		//memset(B,0,sizeof(B));
		B.clear();

		printf("Case #%d: ",z+1);
		cout<<rec(30,a,b,k)<<"\n";
	}

	return 0;
}