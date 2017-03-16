#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

//#define _INFILE		"A.in"
//#define _OUTFILE	"A.out"

#define _INFILE		"A-small-attempt0.in"
#define _OUTFILE	"A-small.out"

//#define _INFILE		"A-large.in"
//#define _OUTFILE	"A-large.out"


typedef long long ll;

void solve()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	vector<double> vv;

	int sum = 0;

	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d",&t);
		v.push_back(t);
		vv.push_back(-1.0);
		sum += t;
	}

	while(true)
	{
		double sum1 = 0;
		int cnt = 0;
		for(int i=0; i<n; i++)
		{
			if (vv[i] < 0.0)
			{
				sum1 += v[i];
				cnt++;
			}
		}
		double avg = (sum + sum1) / cnt;
		bool flag = false;
		for(int i=0; i<n; i++)
		{
			if (vv[i] < 0.0 && v[i] >= avg)
			{
				vv[i] = 0.0;
				flag = true;
			}
		}

		if (!flag) 
		{
			for(int i=0; i<n; i++)
			{
				if (vv[i] < 0.0)
				{
					vv[i] = (avg - v[i]) / sum * 100;
				}
			}
			break;
		}
	}

	for(int i=0; i<n; i++)
	{
		printf(" %lf", vv[i]);
	}

	printf("\n");
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d:", i+1);
		solve();
	}
	return 0;
}

