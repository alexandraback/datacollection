#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int test, i, j, k, a, b, h, t, tt, s, ss, temp, n, res;
int c[10], kk, cnt, check;

int main()
{
	//FILE *fp1 = fopen("input.txt", "r");
	FILE *fp1 = fopen("C-small-attempt0.in", "r");
	FILE *fp2 = fopen("output.txt", "w");

	fscanf(fp1, "%d", &test);
	for(h = 1; h <= test; h++)
	{
		fscanf(fp1, "%d %d", &a, &b);
		
		res = 0;
		for(i = a; i < b; i++)
		{
			cnt = 0;
			t = i;
			tt = 1;
			for(s = 1; ; s++)
			{
				t /= 10;
				if(t == 0)
					break;
				tt *= 10;
			}
			// s == n자리
			//printf("자리수 = %d\n", s);
			//printf("%d => ", i);
			t = i;
			temp = 10;
			for(ss = 1; ss < s; ss++)
			//for(temp = 10; ; temp*=10)
			{
				j = t / temp;
				k = t % temp;
				//for(tt = 1; tt < s; tt*=10);
				//s--;
				n = k*tt + j;
				//printf("%d ", n);
				check = -1;
				for(kk = 0; kk < cnt; kk++)
				{
					if(c[kk] == n)
						break;
				}
				if(kk == cnt)
				{
					check = 1;
					c[cnt++] = n;
				}
				if(i < n && n <= b && check == 1)
				{
					res++;
					//fprintf(fp2, "%d  %d\n", i, n);
				}
				temp *= 10;
				tt /= 10;
			}
			//printf("\n");
		}

		fprintf(fp2, "Case #%d: %d\n", h, res);
	}

	fcloseall();
	return 0;
}