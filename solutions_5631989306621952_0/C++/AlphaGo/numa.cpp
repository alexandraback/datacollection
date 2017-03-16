#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <vector>
#include <ctime>
#include <cctype>
#include <stack>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <utility> 
using namespace std;
#define ll long long 
#define m0(a) memset(a, 0, sizeof(a))
#define m1(a) memset(a, -1, sizeof(a))
#define C1(x)  cout<<x<<endl;
#define C2(x,y)  cout<<x<<" "<<y<<endl;
#define C3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl;
struct stu
{
	int x,y,z;
	bool operator < (const stu &b) const
	{
		return x<b.x;	
	}
};
const int inf = 0x3f3f3f3f; 
const double eps = 1e-15;
const double pi = acos((double)-1) ;
const int maxn = 1010;
const ll M = 1e9+7;
ll i,j,k,l,m,n,x,y,z,ans,num;
char s[maxn]={0};
char a[2020]={0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main () 
{
	#ifdef ONLINE_JUDGE
	
	#else
	
	    freopen("A-small-attempt0.in","r",stdin);
	    freopen("in.out","w",stdout);
	
	#endif
	int cas;
	scanf("%d",&cas);getchar();
	for (int casi=1;casi<=cas;casi++)
	{
		printf("Case #%d: ",casi);
		int l=1000;int r=1000;
		gets(s) ;
		a[l]=s[0];
		for (int i=1;i<strlen(s);i++)
		{
			if (s[i]<a[l])
			{
				r++;a[r]=s[i];
				continue;
			}
			if (s[i]>a[l])
			{
				l--;a[l]=s[i];
				continue;
			}
			x=l+1;
			while (x<=r && s[i]==a[x])x++;
			if (x>r || s[i]>a[x])
			{
				l--;a[l]=s[i];
				continue;
			}
			else 
			{
				r++;a[r]=s[i];
				continue;
			}
			
		}
		
		for (int i=l;i<=r;i++) printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
