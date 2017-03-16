//TC Accretia Code Template
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>
#include <string>

#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define FILL(arr,n) memset(arr,n,sizeof(arr))
#define FORUP(i,m,n) for(int i=(m); i<(n); i++)
#define FORDOWN(i,m,n) for(int i=(m)-1; i>=(n); i--)

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define INF 2000000000
#define EPS 1e-6
#define PI acos(-1.0)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;

vector<double> binSearch(double lb,double ub,vector<double> angka,double mini, double maxi,double jum)
{
	bool yes;
	double mb;
	vector<double> ans;
	while(lb <= ub)
	{
		ans.clear();
		mb = (lb + ub) / 2.0;
		double equi = mini + (jum * mb/100.0);

		double percentage = 0.0;
		yes = true;
		for(int i = 0;i < angka.size();i++)
		{
			if(equi < angka[i])
			{
				ans.PB(0.0);
				continue;
			}
			double pcnt = (equi - angka[i]) / jum * 100.0;
			percentage += pcnt;
			if(100.0 - percentage >=  EPS)ans.PB(pcnt);
			else
			{
				yes = false;
				break;
			}
		}
		if(yes)
		{

			if((100.0 - percentage) <= 1e-5)
			{
				return ans;
			}
			else
			{
				lb = mb + EPS;
			}
		}
		else
		{
			ub = mb - EPS;
		}
	}
	ans.clear();
	ans.PB(-1.0);
	return ans;
}

int
main()
{
	int N;
	double jum;
	double mini, maxi;
	vector<double> ang;
	vector<double> angka;
	vector<double> ans;
		
	int T;
	scanf("%d", &T);
	for(int tc = 1;tc <= T;tc++)
	{
		scanf("%d", &N);
		angka.clear();
		ang.clear();
		jum = 0;
		mini = INF;
		maxi = -1;

		for(int i = 0;i < N;i++)
		{
			double tmp;
			scanf("%lf", &tmp);
			jum += tmp;
			angka.PB(tmp);
			ang.PB(tmp);
		}
		sort(ang.begin(), ang.end());
		
		while(1)
		{
			maxi = ang[ang.size()-1];
			mini = ang[0];
			double ub = 100.0;
			double lb = (maxi - mini)/jum * 100.0;
			ans.clear();
			if(lb <= EPS)
			{
				int jummini = 0;
				for(int i = 0;i < angka.size();i++)
				{
					if(angka[i] - mini <= EPS)jummini++;
				}
				for(int i = 0;i < angka.size();i++)
				{
					if(angka[i] - mini <= EPS)
					{
						double hasil = 100.0/jummini;
						ans.PB(hasil);
					}
					else
					{
						ans.PB(0.0);
					}
				}
				break;
			}
			ans = binSearch(lb,ub,angka,mini,maxi,jum);
			if(ans[0] > 0.0)
			{
				break;
			}
			else
			{
				while(maxi - ang[ang.size()-1] <= EPS)ang.pop_back();
			}
		}
		printf("Case #%d:",tc);
		for(int i = 0;i < N;i++)
		{
			printf(" %.6f",ans[i]);
		}
		printf("\n");
	}
return 0;
}