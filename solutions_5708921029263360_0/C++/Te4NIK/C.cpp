#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define sz size()
#define x first
#define y second
#define forn(i, n) for(int i=0; i<(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;

int T,a,b,c,K;
int ans=0;

set <int> st;
set <int>::iterator it;
int kp[9][9];
vector <int> vans;
vector <int> v;

int next()
{
	int mmin=999999;
	int t,ia,ib,ic;
	forn(i,a)
		forn(j,b)
			forn(k,c)
			{
				int aa=i;
				int bb=3+j;
				int cc=6+k;
				
				if(st.find(aa+10*bb+100*cc)==st.end() && kp[aa][bb]<K && kp[aa][cc]<K && kp[bb][cc]<K)
				{
					t=kp[aa][bb]+kp[aa][cc]+kp[bb][cc];
					if(t<mmin)
					{
						ia=aa,ib=bb,ic=cc;
						mmin=t;
					}
				}
			}
	if(mmin>1000)
		return -1;
	return ia+10*ib+100*ic;
}

int solve()
{
	for(int i=0; ;i++)
	{
		int c=next();
		if(c==-1)
			return i;

	    st.insert(c);
		v.pb(c);
		int aa=c%10;
		c/=10;
		int bb=c%10;
		c/=10;
		int cc=c;

		kp[aa][bb]++;
		kp[aa][cc]++;
		kp[bb][cc]++;
	}
}

int d[10100];

void dfs(int kol)
{
	if(kol>ans)
	{
		cerr <<kol<<endl;
		d[kol]=ans;
		ans=kol;
		vans.clear();
		for(it=st.begin(); it!=st.end(); it++)
			vans.pb(*it);
	}

	forn(i,a)
		forn(j,b)
			forn(k,c)
			{
				int aa=i;
				int bb=3+j;
				int cc=6+k;
				int tt=aa+10*bb+100*cc;

				if((st.size()==0 || tt>(*st.rbegin())) && (st.find(tt)==st.end()) && d[tt]<=ans)
				{
					bool ok=1;

					kp[aa][bb]++;
					if(kp[aa][bb]>K)
						ok=0;
					
					kp[aa][cc]++;
					if(kp[aa][cc]>K)
						ok=0;
					
					kp[bb][cc]++;
					if(kp[bb][cc]>K)
						ok=0;
					
					st.insert(tt);
					
					if(ok)
					{
						dfs(kol+1);
					}

					st.erase(st.find(tt));
					kp[aa][bb]--;
					kp[aa][cc]--;
					kp[bb][cc]--;
				}
			}
}

int main()
{
	freopen("z.in", "rt", stdin);
	freopen("z.out", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >>T;
	forn(I,T)
	{
		cerr <<"I "<<I<<endl;
		cin >>a>>b>>c>>K;
		forn(i,9)
			forn(j,9)
				kp[i][j]=0;
		ans=0;
		st.clear();
		vans.clear();

		if(a==3 && b==3 && c==3 && K>2)
			ans=27;
		else
		if(a==2 && b==3 && c==3 && K>2)
			ans=18;
		else
			dfs(0);
		cout <<"Case #"<<I+1<<": "<<ans<<endl;
		forn(i,vans.size())
        {
        	cout <<vans[i]%10+1<<' ';
        	vans[i]/=10;
        	cout <<vans[i]%10-2<<' ';
        	vans[i]/=10;
        	cout <<vans[i]%10-5<<endl;
		}
	}
	return 0;
}
