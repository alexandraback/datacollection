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

const int MAXN = 110;
int a[MAXN][MAXN];
int maxv[MAXN], maxh[MAXN];
int n,m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cout<<"Case #"<<T<<": ";
		cin>>n>>m;
		//init
		for(int i=0;i<MAXN;i++)
		{	
			maxv[i] = -1;
			maxh[i] = -1;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				maxv[j] = max(maxv[j], a[i][j]);
				maxh[i] = max(maxh[i], a[i][j]);
			}
		bool OK = true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maxh[i]>a[i][j] && maxv[j]>a[i][j])
				{
					OK = false;
					break;
				}
			}
			if(!OK)
				break;
		}
		if(OK)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}

    return 0;
}