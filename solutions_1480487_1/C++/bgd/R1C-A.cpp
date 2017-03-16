#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define FOR(i, a, b) for(int i(a); i<b; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
#define CLEAR(a, b) memset(x, b, sizeof(x))

#define mp make_pair
#define pb push_back

int T;
int N, X;

int main()
{
	freopen("R1AL.in", "r", stdin);
	freopen("R1AL.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	
	cin>>T;
	REP(t, T)
	{
		cout<<"Case #"<<t+1<<": ";
		cin>>N;
		X=0;
		vi s(N);
		REP(i, N) {cin>>s[i]; X+=s[i];}
		vi ss=s;
		sort(ALL(ss));
		double t=ss[0];
		int rX=X;
		cout.precision(6);
		FOR(i, 1, N)
		{
			if (i*(ss[i]-t)<=rX) 
			{
				rX-=i*(ss[i]-t);
				t=ss[i];
			}
			else {t+=(double)rX/i; rX=0; break;}
		}
		if (rX) t+=(double)rX/N;

		REP(i, N)
		{
			if(s[i]>=t) cout<<0<<' ';
			else cout<<fixed<<(t-s[i])/X*100.<<' ';
		}
		cout<<endl;
	}

	fclose(stdout);
}
