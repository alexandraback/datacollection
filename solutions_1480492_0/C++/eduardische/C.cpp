#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 8

using namespace std;

struct node
{
	char lane, immune;
	long double pos, V;

	bool operator<(const node& e) const
    {
        return ((lane < e.lane) || ((lane == e.lane) && (pos < e.pos)));
    }
};

long double Module (long double a)
{
	if (a < 0) return -1.0 * a;
	else return a;
}

int N;

long double Try (struct node a[MAXN], long double T)
{
	int i, j;
	char flag;
	struct node a2[MAXN];
	sort(&(a[0]),&(a[N]));
	int newN = 0;
	while ((newN < N) && (a[newN].lane == 'L')) newN++;
	//Changing all crashing cars in this moment to R
	long double result, restemp;
	i = 0;
	result = T;
	char isChanged = 0;
	while (i < newN)
	{
		j = i+1;
		while ((j < newN) && (Module(a[j].pos - a[j-1].pos - 5.0) <= 1E-9) && ((a[j].V + 1E-9) < (a[j-1].V))) j++;
		int k, q;
		if ((j - i) > 1)
		{
			isChanged = 1;
			char nowl, isOK;

			nowl = 'L';
			isOK = 1;
			for (k = j-1; k >= i; k--)
			{
				if (nowl == 'R')
				{
					for (q = newN; q < N; q++)
					{
						if (((a[q].pos + 1E-9) < (a[k].pos + 5.0)) && ((a[q].pos + 5.0 - 1E-9) > (a[k].pos)))
						{
							isOK = 0;
							break;
						}
					}
					nowl = 'L';
				}
				else nowl = 'R';
				if (!isOK) break;
			}
			if (isOK)
			{
				nowl = 'L';
				memcpy(a2,a,sizeof(a2));
				for (k = j-1; k >= i; k--)
				{
					if (nowl == 'R')
					{
						a[k].lane = 'R';
						a[k].immune = 1;
						nowl = 'L';
					}
					else nowl = 'R';
				}
				restemp = Try(a,T);
				memcpy(a,a2,sizeof(a2));
				if (restemp > result) result = restemp;
			}

			nowl = 'R';
			isOK = 1;
			for (k = j-1; k >= i; k--)
			{
				if (nowl == 'R')
				{
					for (q = newN; q < N; q++)
					{
						if (((a[q].pos + 1E-9) < (a[k].pos + 5.0)) && ((a[q].pos + 5.0 - 1E-9) > (a[k].pos)))
						{
							isOK = 0;
							break;
						}
					}
					nowl = 'L';
				}
				else nowl = 'R';
				if (!isOK) break;
			}
			if (isOK)
			{
				nowl = 'R';
				memcpy(a2,a,sizeof(a));
				for (k = j-1; k >= i; k--)
				{
					if (nowl == 'R')
					{
						a[k].lane = 'R';
						a[k].immune = 1;
						nowl = 'L';
					}
					else nowl = 'R';
				}
				restemp = Try(a,T);
				memcpy(a,a2,sizeof(a2));
				if (restemp > result) result = restemp;
			}
		}
		i = j;
	}
	if (isChanged) return result;

	for (i = 0; i < N; i++)
	{
		if (a[i].lane == 'R')
		{
			if (a[i].immune == 0)
			{
				flag = 1;
				for (j = 0; j < N; j++)
				{
					if ((a[j].lane == 'L') && ((a[j].pos + 1E-9) < (a[i].pos + 5.0)) && ((a[j].pos + 5.0 - 1E-9) > (a[i].pos)))
					{
						flag = 0;
						break;
					}
				}
				if (flag) a[i].lane = 'L';
			}
			else a[i].immune = 0;
		}
	}
	//Finding out the next event
	long double next = 1E9;
	long double temp;
	for (i = 0; i < N; i++)
	{
		if (a[i].lane == 'L')
		{
			for (j = 0; j < N; j++)
			{
				if ((a[j].lane == 'L') && ((a[j].pos - 1E-9) > a[i].pos) && ((a[i].V - 1E-9) > a[j].V))
				{
					temp = (a[j].pos - a[i].pos - 5.0) / (a[i].V - a[j].V);
					if ((temp - 1E-9) < next) next = temp;
				}
			}
		}
		else
		{
			for (j = 0; j < N; j++)
			{
				if ((a[j].lane == 'L') && (a[j].pos > a[i].pos))
				{
					if ((a[i].V - 1E-9) > a[j].V)
					{
						temp = (a[j].pos + 5.0 - a[i].pos) / (a[i].V - a[j].V);
						if ((temp - 1E-9) < next) next = temp;
					}
					else if (((a[j].pos + 1E-9) < (a[i].pos + 5.0)) && ((a[i].V + 1E-9) < a[j].V))
					{
						temp = (a[i].pos + 5.0 - a[j].pos) / (a[j].V - a[i].V);
						if ((temp - 1E-9) < next) next = temp;
					}
				}
			}
		}
	}
	//printf("next = %.9lf\n",(double)(next));
	//Checking if infinity
	sort(&(a[0]),&(a[N]));
	newN = 0;
	while ((newN < N) && (a[newN].lane == 'L')) newN++;
	if (next >= (1E9 - 1E-9))
	{
		char toinfinityandbeyond = 1;
		for (i = newN; i < (N-1); i++)
		{
			if ((a[i+1].V + 1E-9) < a[i].V) toinfinityandbeyond = 0;
		}
		if (toinfinityandbeyond) return 1E9;
		else return T;
	}
	//Checking if anything will collide on R
	char collide = 0;
	for (i = 0; i < N; i++)
	{
		if (a[i].lane == 'R')
		{
			for (j = 0; j < N; j++)
			{
				if ((a[j].lane == 'R') && (a[j].pos > a[i].pos) && ((a[i].V - 1E-9) > a[j].V))
				{
					temp = (a[j].pos - a[i].pos - 5.0) / (a[i].V - a[j].V);
					if ((temp - 1E-9) < next)
					{
						next = temp;
						collide = 1;
					}
				}
			}
		}
	}
	T += next;
	if (collide)
	{
		return T;
	}
	//Moving cars
	for (i = 0; i < N; i++)
	{
		a[i].pos += next * a[i].V;
	}

	return Try(a,T);
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static struct node a[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		scanf("%d\n",&N);
		int i;
		for (i = 0; i < N; i++)
		{
			int pos, V;
			scanf("%c %d %d\n",&(a[i].lane),&V,&pos);
			a[i].pos = (long double)(pos);
			a[i].V = (long double)(V);
			a[i].immune = 0;
		}
		long double T = Try(a,0.0);

		printf("Case #%d: ",iT+1);
		if (T >= (1E9 - 1E-9)) printf("Possible\n");
		else printf("%.9lf\n",(double)(T));
	}
	return 0;
}
