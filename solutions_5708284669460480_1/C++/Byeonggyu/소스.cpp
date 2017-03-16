#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>	
#include<math.h>
int t,a,b,c;
int findmax(char x[])
{
	int check = 0;
	for (int i = 1; i < b; i++)
	{
		if (x[i] == x[0])
		{
			check = 0;
			for (int j = i + 1; j < b; j++)
			{
				if (x[j] != x[j - i])
					check = 1;
			}
			if(check==0)
				return i;
		}
	}
	return b;
}

int main(){
	int ma,num=0,p;
	int abc[200];
	double ans;
	char k[200], l[200];
	FILE *f = fopen("B-large.in", "r");
	FILE *fo = fopen("out.txt", "w+");
	fscanf(f, "%d", &t);
	for (int i = 1; i <= t; i++)
	{
		for (int j = 60; j <= 90; j++)
		{
			abc[j] = 0;
		}
		fscanf(f, "%d %d %d", &a,&b,&c);
		fscanf(f, "%s", k);
		fscanf(f, "%s", l);
		ma = (c - b) / findmax(l) + 1;
		for (int j = 0; j < a; j++)
		{
			abc[k[j]] += 1;
		}
		num = 0;
		for (int j = 64; j <= 90; j++)
		{
			if(abc[j]!=1)
			num += 1;
		}
		p = 1;
		for (int j = 0; j < b; j++)
		{
			p *= abc[l[j]];
		}
		if (p == 0)
		{
			ma = 0;
			ans = 0;
		}
		else{
			ans = p*(c - b + 1) / pow((double)a, (double)b);
		}
		fprintf(fo, "Case #%d: %lf\n", i, ma - ans);
	}

}