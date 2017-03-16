#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 105

int i, j, k, n, s, p, test, h, res;
int t[N], sc[N][3];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	FILE *fp1 = fopen("B-small-attempt0.in", "r");
	//FILE *fp1 = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "w");
	
	fscanf(fp1, "%d", &test);
	for(h = 1; h <= test; h++)
	{
		fscanf(fp1, "%d %d %d", &n, &s, &p);
		for(i = 1; i <= n; i++)
			fscanf(fp1, "%d", &t[i]);

		sort(t+1, t+1+n, cmp);
		for(i = 1; i <= n; i++)
		{
			if(t[i] % 3 == 0)
			{
				sc[i][0] = sc[i][1] = sc[i][2] = t[i] / 3;
			}
			else if(t[i] % 3 == 1)
			{
				sc[i][0] = t[i] / 3 + 1;
				sc[i][1] = sc[i][2] = t[i] / 3;
			}
			else
			{
				sc[i][0] = sc[i][1] = t[i] / 3 + 1;
				sc[i][2] = t[i] / 3;
			}
		}

		//if(h == 4){
		//for(i = 1; i <= n; i++)
		//	printf("%d %d %d\n", sc[i][0], sc[i][1], sc[i][2]);}

		for(i = 1; i <= n; i++)
		{
			if(s > 0 && sc[i][0] < p && 2 <= t[i] && t[i] <= 28)
			{
				if(t[i] % 3 == 0)
				{
					sc[i][0]++; sc[i][2]--;
				}
				else if(t[i] % 3 == 1)
				{
					sc[i][1]++; sc[i][2]--;
				}
				else
				{
					sc[i][0]++; sc[i][1]--;
				}
				s--;
			}
		}

		// output
		res = 0;
		for(i = 1; i <= n; i++)
		{
			if(sc[i][0] >= p)
				res++;
		}

		fprintf(fp2, "Case #%d: %d\n", h, res);
	}


	fcloseall();
	return 0;
}