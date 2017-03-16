#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

#define maxn 110
//#define maxm 1000
//const double expp=1e-7;
//#define maxnumber 10000000

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int a[maxn],f[maxn];


int main()
{
	freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d: ",TT);
		int w,n;
		cin>>w>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		if (w==1)
		{
			cout<<n<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		f[0]=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]<w)
			{
				w+=a[i];
				f[i]=f[i-1];
			}
			else
			{
				int temp=0;
				do
				{
					w+=w-1;
					temp++;
				}while(a[i]>=w);
				w+=a[i];
				f[i]=f[i-1]+temp;
			}
		}
		int ans=n+1;
		for (int i=0;i<=n;i++)
			ans=min(ans,f[i]+n-i);
		cout<<ans<<endl;
	}
	
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
