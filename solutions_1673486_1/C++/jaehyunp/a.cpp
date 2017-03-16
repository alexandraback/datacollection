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

int a, b;
double p[100100];
double ans;

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
	for(t=1;t<=tc;t++)
	{
		fscanf(fp, "%d%d", &a, &b);
		for(i=1;i<=a;i++) fscanf(fp, "%lf", &p[i]);
		ans=min(b+2, a+b+1);
		double P=1.0;
		for(i=1;i<=a;i++)
		{
			P*=p[i];
			ans=min(ans, (a+b-2*i+1)+(1-P)*(b+1));
		}
		fprintf(ofp, "Case #%d: %.8lf\n", t, ans);
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
