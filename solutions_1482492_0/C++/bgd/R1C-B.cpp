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
typedef vector<ll> vi;
typedef vector<vi> vvi;

#define FOR(i, a, b) for(int i(a); i<b; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
#define CLEAR(a, b) memset(x, b, sizeof(x))

#define mp make_pair
#define pb push_back

void solve();

int T;

int main()
{
	freopen("R1C-B.in", "r", stdin);
	freopen("R1C-B.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	
	cin>>T;
	REP(t, T)
	{
		cout<<"Case #"<<t+1<<":\n";
		solve();
		//cout<<endl;
	}

	fclose(stdout);
}

double D;
int N, A;
double x[2000];
double t[2000];
double a[250];

void solve()
{
	cin>>D>>N>>A;
	REP(i, N)
	{
		cin>>t[i]>>x[i];
	}
	REP(i, A)
	{
		cin>>a[i];
	}

	REP(i, A)
	{
		double ans;
		if(N==1 || x[0]>=D)
		{

			/*double sp=x[0]/t[0];
			double t2fin=D/sp;
			if(2*sp/a[i] > t2fin)*/ ans=sqrt(2*D/a[i]);
			/*else ans=t2fin;*/
		}

		else 
		{
			/*double sp1=x[0]/t[0];
			double sp2=(x[1]-x[0])/(t[1]-t[0]);
			double t1c=sp1*x[0];
			double t2c=sp2*(D-x[0]);
			double t1me=sqrt(2*x[0]/a[i]);
			ans=max(t1c, t1me);
			if(t1c<t1me) t2c-=t1me-t1c;
			t2c=max(t2c, 0.);
			double vme=x[0]*t1me;
			if(vme*t2c+a[i]*t2c*t2c/2<=D-x[0]) 
			{
				double Dsk=vme*vme+2*a[i]*(D-x[0]);
				ans+=(-vme+sqrt(Dsk))/a[i];
			}
			else ans+=t2c;*/
			double spc=(x[1]-x[0])/t[1];
			ans=max(sqrt(2*D/a[i]), (D-x[0])/spc);
		}

		cout.precision(8);
		cout<<fixed<<ans<<endl;
	}
}