#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define pb push_back
#define mp make_pair
#define ST begin()
#define ED end()
#define XX first
#define YY second
#define elif else if 
#define foreach(i,x) for (__typeof((x).ST) i=(x).ST;i!=(x).ED;++i) 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef pair<int,int> PII;

const int N = 105;

int n, m;
int a[N];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	int task;
	scanf("%d", &task);
	for (int _i=1;_i<=task;++_i)
	{
		scanf("%d%d", &m, &n);
		for (int i=1;i<=n;++i)
			scanf("%d", &a[i]);
		sort(a+1,a+n+1);

		int ans=n;

		if (m>1)
		{

		int t=0;
		for (int i=1;i<=n;++i)
		{
			ans=min(ans,t+n-i+1);
			while (m<=a[i]) ++t,m+=m-1;
			m+=a[i];
		}
		ans=min(ans,t);

		}

		cout<<"Case #"<<_i<<": "<<ans<<endl;
	}

	return 0;
}
