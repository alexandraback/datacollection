#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 2111111111;

const double pi = acos(-1);
double r,t;
double gao(double n)
{
	//long long x = 2*n*r;
	//cout<<2*n*r+(2*n-1)*n<<endl;
	return 2*n*r+(2*n-1)*n;
}
int main()
{
   freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	long long ans;
	double ret;
	int left,right;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		ans = 0;
		cin>>r>>t;
		left = 1; right = inf;
		while(left<=right)
		{
			int m = (left+right)/2;
			ret = gao(m);
			if(ret<=t) left = m+1,ans = m;
			else right = m-1;
		}
		cout<<"Case #"<<ca<<": ";
		cout<<ans<<"\n";
	}

    return 0;
}


