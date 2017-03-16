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

bool v[2000100];
int nxtn[2000100];

void pre()
{
	int i, j, len;
	int s;
	for(len=1, s=1;len<=7;len++, s*=10)
	{
		for(i=s;i<s*10 && i<=2000000;i++)
		{
			if(v[i]) continue;
			v[i]=true;
			if(i==1112)
				i=i;
			int lst=i, cur=i, nxt;
			for(j=1;j<len;j++, cur=nxt)
			{
				nxt=(cur/10)+((cur%10)*s);
				if(nxt<s || nxt>2000000) continue;
				if(v[nxt]) break;
				nxtn[lst]=nxt; v[lst]=true; lst=nxt;
			}
			nxtn[lst]=i; v[lst]=true;
		}
	}
}

int main()
{
	pre();

	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int t, tc;
	fscanf(fp, "%d", &tc);
	for(t=1;t<=tc;t++)
	{
		int s, e;
		fscanf(fp, "%d%d", &s, &e);
		memset(v, false, sizeof(v));
		int i, j;
		int ans=0;
		for(i=s;i<=e;i++)
		{
			if(v[i]) continue;
			int cnt=0;
			for(j=i;!v[j];j=nxtn[j])
			{
				if(s<=j && j<=e) cnt++;
				v[j]=true;
			}
			ans+=cnt*(cnt-1)/2;
		}
		fprintf(ofp, "Case #%d: %d\n", t, ans);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
