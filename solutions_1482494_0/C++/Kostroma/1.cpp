#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef double ld;
typedef pair <int, int> pi;
int timer=1;
void solve();
int main ()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int t;
	cin>>t;
	while (t--)
		solve(), timer++;
	return 0;
}
//#define int li

int n;
pair <int, int> a[1005];

int done[1005];
pair <int, int> f[1005];
pair <int, int> s[1005];

set < pair <int, int> > firsts;

void solve()
{
	cout<<"Case #"<<timer<<": ";
	
	for (int i=0; i<1005; i++)
		done[i]=0;
	firsts.clear();
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>a[i].first>>a[i].second;
		f[i]=mp(a[i].first, i);
		s[i]=mp(a[i].second, i);
		firsts.insert(mp(a[i].first, i));
	}
	int ans=100500;
	for (int mask=0; mask<(1<<n); mask++)
	{
		vector <pair<int,int> > aa;
		int cnt=0;
		for (int z=0; z<n; z++)
		{
			if ( mask & (1<<z) )
				cnt++, aa.pb(mp(a[z].first,1)), aa.pb(mp(a[z].second,1));
			else
				aa.pb(mp(a[z].second,2));
		}
		sort (aa.begin(), aa.end());
		int curr=0;
		bool f=true;
		for (int i=0; i<aa.size(); i++)
		{
			if (curr>=aa[i].first)
				curr+=aa[i].second;
			else
			{
				f=false;
				break;
			}
		}
		if (f)
			ans=min(ans, cnt+n);
	}

	if (ans==100500)
		cout<<"Too Bad";
	else

	if (ans>0)
		cout<<ans;
	cout<<endl;
}
