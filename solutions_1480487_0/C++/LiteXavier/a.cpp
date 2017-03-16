#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-10;
const int maxn = 300;

int n, X;
int score[maxn];
double g[maxn][maxn];
double ans[maxn];

double getans ( int i )
{
	double l = 0, r = 1.0;
	while ( l + eps < r )
	{
		double m = (r+l)*.5;
		double f = score[i] + X * m;
		double res = 1-m;
		bool flag = true;
		for(int j = 0; j < n; j ++ ) if( j != i )
		{
			double t = ( f - score[j] ) / X;
			t = max(t, 0.0);
			res -= t;
			if( res < -eps )
			{
				flag = false;
				break;
			}
		}
		
		if( flag )
			l = m;
		else
			r = m;
			
//		fprintf(stderr,"[%.4lf,%.4lf](%.4lf)\n", l,r,m);
	}
	return l;
}

int main ()
{
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	scanf("%d",&T);	
	for(int t = 1; t <= T; t ++ )
	{
		scanf("%d",&n);
		X = 0;
		for(int i = 0; i < n; i ++ ) scanf("%d", score+i);
		for(int i = 0; i < n; i ++ ) X += score[i];
/*		for(int i = 0; i < n; i ++ )
			for(int j = 0; j < n; j ++ ) if( i != j )
				g[i][j] = (double)((double)score[i] - score[j]) / (double)X;
		
		for(int i = 0; i < n; i ++ )
		{
			for(int j = 0; j < n; j ++ )
				printf(" %.2lf", g[i][j]);
			puts("");
		}		
		
		for(int i = 0; i < n; i ++ )
		{
			ans[i] = 0;
			for(int j = 0; j < n; j ++ )
				if( j != i )
					ans[i] = max(ans[i], (1.0-g[i][j])*.5);
		}*/
		
		for(int i = 0; i < n; i ++ )
		{
			ans[i] = getans(i);
		}
		
		printf("Case #%d:", t);
		for(int i = 0; i < n; i ++ )
			printf(" %.7lf", ans[i]*100);
		puts("");
	}
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
