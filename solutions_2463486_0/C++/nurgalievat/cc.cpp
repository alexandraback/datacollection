#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<set>
#include<deque>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<sstream>
#include<cstring>
#include<functional>
using namespace std;

#pragma comment(linker, "/STACK:64000000")
#define ALL(X) (X).begin(),(X).end()
#define sqr(X) ((X)*(X))

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef long long LLL;
typedef unsigned long long HL;
const double EPS = 1e-8;
const int INF = 1e9;
const LLL LINF = 1e18;

LLL a[20];

inline bool ispal(LLL x)
{
	int pos = 0;
	while(x)
	{
		a[pos++] = x%10LL;
		x/=10LL;
	}
	int p2 = pos>>1;
	for(int i=0;i<=p2;i++)
		if(a[i]!=a[pos-i-1])
			return false;
	return true;
}

vector<LLL> sq;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    for(LLL i=0LL;i<=40LL;i++)
	{
		if(ispal(i) && ispal(i*i))
			sq.push_back(i*i);
	}
	int t;
	LLL a, b;
	cin>>t;
	for(int T = 1;T<=t;T++)
	{
		cout<<"Case #"<<T<<": ";
		cin>>a>>b;
		cout<<(upper_bound(sq.begin(), sq.end(), b) - lower_bound(sq.begin(), sq.end(), a))<<endl;
	}

    return 0;
}