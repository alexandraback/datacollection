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
typedef long long ll;

const double eps=1e-8;

struct car
{
	int l, s, p;
	const bool operator < (const car &o) const
	{
		if(p!=o.p) return p<o.p;
		return s>o.s;
	}
};
struct event
{
	int i, j;
	bool type;
	double t;
	event() {}
	event(int i, int j, bool type, double t): i(i), j(j), type(type), t(t) {}
	const bool operator < (const event &o) const {return t<o.t;}
	const bool operator > (const event &o) const {return t>o.t;}
	const bool operator == (const event &o) const {return t==o.t;}
};
car a[64]; int n;
event b[200]; int m;

bool pos[64];
bool conf[8][8];

void add_event(int i, int j, bool type, double t){if(t>=0) b[++m]=event(i, j, type, t);}
inline bool bit(int mask, int k){return (mask>>(k-1))&1;}

void populate()
{
	//clean up
	int i, j, mask;
	for(mask=0;mask<(1<<n);mask++)
	{
		if(!pos[mask]) continue;
		for(i=1;i<=n && pos[mask];i++)
		{
			for(j=i+1;j<=n && pos[mask];j++)
			{
				if(conf[i][j] && bit(mask, i)==bit(mask, j))
					pos[mask]=false;
			}
		}
	}
	bool v[64]={false, };
	while(true)
	{
		bool changed=false;
		for(mask=0;mask<(1<<n);mask++)
		{
			if(!pos[mask] || v[mask]) continue;
			v[mask]=true;
			for(i=1;i<=n;i++)
			{
				bool flag=false;
				for(j=1;j<=n;j++)
				{
					if(conf[i][j] && bit(mask, i)!=bit(mask, j))
					{
						flag=true; break;
					}
				}
				if(flag) continue;
				int nxt=mask^(1<<(i-1));
				if(!pos[nxt]){changed=true; pos[nxt]=true;}
			}
		}
		if(!changed) break;
	}
}
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
	int i, j, k;
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d", &n);
		char buf[4];
		for(i=1;i<=n;i++)
		{
			fscanf(fp, "%s%d%d", buf, &a[i].s, &a[i].p);
			a[i].l=(buf[0]=='L');
		}
		sort(&a[1], &a[n+1]);
		
		memset(conf, false, sizeof(conf));
		m=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(a[j].p-a[i].p>-5 && a[j].p-a[i].p<5) conf[i][j]=conf[j][i]=true;
				if(a[i].s<=a[j].s) continue;
				double t1=(double)(a[j].p-a[i].p-5)/(double)(a[i].s-a[j].s)+eps;
				double t2=(double)(a[j].p-a[i].p+5)/(double)(a[i].s-a[j].s)-eps;
				add_event(i, j, true, t1);
				add_event(i, j, false, t2);
			}
		}
		sort(&b[1], &b[m+1]);

		memset(pos, false, sizeof(pos));
		int mask=0;
		for(i=1;i<=n;i++) mask+=a[i].l*(1<<(i-1));
		pos[mask]=true;
		populate();
		
		double ans=0.0;
		for(i=1;i<=m;i=k)
		{
			bool flag=false;
			for(k=0;k<(1<<n);k++)
			{
				if(pos[k]){flag=true; break;}
			}
			if(!flag) break;
			ans=b[i].t;
			for(k=i;k<=m && b[i]==b[k];k++) conf[b[k].i][b[k].j]=conf[b[k].j][b[k].i]=b[k].type;
			populate();
		}
		bool flag=false;
		for(k=0;k<(1<<n);k++)
		{
			if(pos[k]){flag=true; break;}
		}
		fprintf(ofp, "Case #%d: ", t);
		if(flag) fprintf(ofp, "Possible\n");
		else fprintf(ofp, "%.7lf\n", ans);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
