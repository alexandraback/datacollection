#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const double INF = numeric_limits<double>::infinity();

const bool DEBUG = false;
const int kmax = 15, nmax = 15, maxsets = 125+5;
int prod[kmax];
int sets[maxsets][nmax];
double prob[maxsets];

int R,n,m,K;

void gensets(int i, int j, int* set, int& setidx)
{
	if(i == n)
	{
		for(int j=0;j<n;j++)
			sets[setidx][j] = set[j];
		setidx++;
		return;
	}
	for(int x = j; x <= m; x++)
	{
		set[i] = x;
		gensets(i+1, x, set, setidx);
	}
}

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		printf("Case #%d:\n", test_case);
		scanf("%d%d%d%d", &R, &n, &m, &K);
		
		int set[n];
		int setidx = 0;
		gensets(0, 2, set, setidx);
		/*
		for(int i=0;i<setidx;i++)
		{
			for(int j=0;j<n;j++)
				printf("%d ", sets[i][j]);
			printf("\n");
		}
		*/
		int S = setidx;
				 
		for(int r=0;r<R;r++)
		{
			for(int k=0;k<K;k++)
				scanf("%d", prod+k);
			
			for(int s=0;s<S;s++)
			{
				prob[s] = 0;
				for(int k=0;k<K;k++)
				{
					int count = 0;
					for(int b = 0; b < (1 << n); b++)
					{
						int bprod = 1;
						for(int i=0;i<n;i++)
							if((b >> i) & 1)
								bprod *= sets[s][i];
						if(bprod == prod[k])
							count++;
					}
					prob[s] += log((double)count);
				}
				if(DEBUG)
				{
					if(prob[s] > -INF)
					{
						for(int i=0;i<n;i++)
							printf("%d ", sets[s][i]);
						printf("%lf\n", prob[s]);
					}
				}
			}

			int best = 0;
			double bestprob = -INF;
			for(int s=0;s<S;s++)
				if(prob[s] > bestprob)
				{
					best = s;
					bestprob = prob[s];
				}
			for(int i=0;i<n;i++)
				printf("%d", sets[best][i]);
			printf("\n");
		}
	}
	return 0;
}
