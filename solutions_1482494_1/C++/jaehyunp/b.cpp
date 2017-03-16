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

int n;
pair<int, int> a[1024];
bool v[1024][3];

int main()
{
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	
	int t, tc;
	fscanf(fp, "%d", &tc);
	int i;
	int tot, cnt;
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d", &n);
		for(i=1;i<=n;i++) fscanf(fp, "%d%d", &a[i].second, &a[i].first);
		sort(&a[1], &a[n+1]);
		for(i=1;i<=n;i++) swap(a[i].first, a[i].second);
		memset(v, false, sizeof(v));
		tot=cnt=0;
		while(tot<2*n)
		{
			bool flag=false;
			for(i=n;i>=1;i--)
			{
				if(!v[i][2] && a[i].second<=tot)
				{
					if(v[i][1]) tot++;
					else tot+=2;
					cnt++;
					v[i][1]=v[i][2]=true;
					flag=true; break;
				}
			}
			if(flag) continue;
			for(i=n;i>=1;i--)
			{
				if(!v[i][1] && a[i].first<=tot)
				{
					tot++; cnt++;
					v[i][1]=true;
					flag=true; break;
				}
			}
			if(!flag) break;
		}
		fprintf(ofp, "Case #%d: ", t);
		if(tot!=2*n) fprintf(ofp, "Too Bad\n");
		else fprintf(ofp, "%d\n", cnt);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
