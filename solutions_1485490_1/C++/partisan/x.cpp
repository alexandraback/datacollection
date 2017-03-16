#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i(a), _b(b); i >= _b; --i)
#define sz(a) (int)((a).size())
#define X first
#define Y second
#define all(a) (a).begin(),(a).end()
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;
typedef vector<pii> vpii;

#define N 111

int n,m;
ll a[N],b[N];
int ta[N],tb[N];
ll f[N][N];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	scanf("%d",&test);
	REP(t,test)
	{
		std::cerr << t << "\n";
		scanf("%d%d",&n,&m);
		REP(i,n)
			cin >> a[i] >> ta[i];
		REP(i,m)
			cin >> b[i] >> tb[i];
		memset(f,0,sizeof(f));
		FORD(i,n-1,0)
			FORD(j,m-1,0)
			{
				f[i][j] = f[i+1][j];
				int ii = i;
				int jj = j-1;
				ll cur = 0;
				ll ci = a[ii];
				ll cj = 0;
				int ct = ta[i];
				while(ii < n && jj < m)
				{
					if(cj == 0)
					{
						f[i][j] = max(f[i][j], f[ii+1][jj+1] + cur);
						++jj;
						while(jj < m && tb[jj] != ct) ++jj;
						if(jj < m) 
							cj = b[jj];
					}
					if(ci == 0)
					{
						f[i][j] = max(f[i][j], f[ii+1][jj+1] + cur);
						++ii;
						while(ii < n && ta[ii] != ct) ++ii;
						if(ii < n)
							ci = a[ii];
					}
					if(ii < n && jj < m)
					{
						ll d = min(ci, cj); 
						cur += d;
						ci -= d;
						cj -= d;
					}
				}
				f[i][j] = max(f[i][j], cur);
			}
		cout << "Case #" << t+1 << ": " << f[0][0] << "\n";
	}
	return 0;
}