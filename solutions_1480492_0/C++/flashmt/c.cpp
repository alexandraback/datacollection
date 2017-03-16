#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

struct car
{
	int lane,v,x;
	
	void input()
	{
		string s;
		cin >> s >> v >> x;
		lane=(s=="R");
	}
} a[55];

int n,b[6000],c[6000],isMeet[6000],active[55];
double t[6000];

int main()
{
	freopen("csmall.in","r",stdin); freopen("csmall.out","w",stdout);
	int test;
	cin >> test;
	fr(it,1,test)
	{
		cin >> n;
		fr(i,1,n) a[i].input();
		fr(i,1,n) active[i]=0;
		fr(i,1,n)
			fr(j,i+1,n)
				if (a[i].v>a[j].v)
					swap(a[i],a[j]);
		
		int m=0;
		fr(i,1,n)
			fr(j,i+1,n)
				if (a[i].x>=a[j].x)
				{
					if (a[j].v==a[i].v) t[m]=1e15;
					else t[m]=1.0*(a[i].x-a[j].x+5)/(a[j].v-a[i].v);
					isMeet[m]=0; b[m]=i; c[m++]=j;
					if (a[j].v==a[i].v) t[m]=-1e15;
					else t[m]=1.0*(a[i].x-a[j].x-5)/(a[j].v-a[i].v);
					isMeet[m]=1; b[m]=i; c[m++]=j;
				}	
				
		rep(i,m)
			fr(j,i+1,m-1)
				if (t[i]>t[j] || (t[i]==t[j] && isMeet[i]>isMeet[j]))
				{
					swap(isMeet[i],isMeet[j]);
					swap(b[i],b[j]);
					swap(c[i],c[j]);
					swap(t[i],t[j]);
				}
		
		//fr(i,1,n) cout << a[i].v << ' ' << a[i].x << endl;
		double ans=-1;
		rep(i,m)
		{
			int x=b[i],y=c[i];
			//cout << t[i] << ' ' << b[i] << ' ' << c[i] << ' ' << isMeet[i] << endl;
			if (isMeet[i])
			{
				fr(z,1,n)
					if (active[x] && active[y])
					{
						ans=t[i]; break;
					}
				if (ans>=0) break;
				active[x]++; active[y]++;
			}
			else active[x]--, active[y]--;
			
			//cout << "lane: "; fr(i,1,n) cout << a[i].lane << ' '; puts("");
		}
		
		printf("Case #%d: ",it);
		if (ans<0) puts("Possible");
		else printf("%.9lf\n",ans);
	}
}
