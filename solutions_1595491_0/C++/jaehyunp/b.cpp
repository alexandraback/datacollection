#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	
	int i, j, k;
	int m0[40]={0, }, m1[40]={0, };
	for(i=0;i<=10;i++)
	{
		for(j=i;j<=10;j++)
		{
			for(k=j;k<=10 && k<=i+2;k++)
			{
				if(k-i==2) m1[i+j+k]=max(m1[i+j+k], k);
				else m0[i+j+k]=max(m0[i+j+k], k);
			}
		}
	}

	int t, tc;
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		int n, m, r;
		fscanf(fp, "%d%d%d", &n, &m, &r);
		int a[128];
		int d[128][128]={0, };
		for(i=1;i<=n;i++) fscanf(fp, "%d", &a[i]);
		for(i=1;i<=n;i++)
		{
			d[i][0]=d[i-1][0]+(m0[a[i]]>=r);
			for(j=1;j<=m;j++)
				d[i][j]=max(d[i-1][j]+(m0[a[i]]>=r), d[i-1][j-1]+(m1[a[i]]>=r));
		}
		fprintf(ofp, "Case #%d: %d\n", t, d[n][m]);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
