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

char cmap[]="yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	char filename[32];
	char infile[32], outfile[32];

	scanf("%s", filename);
	strcpy(infile, filename); strcpy(outfile, filename);
	strcat(infile, ".in"); strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");

	int t, tc;
	fscanf(fp, "%d\n", &tc);
	char a[130];
	for(t=1;t<=tc;t++)
	{
		fgets(a, 120, fp);
		fprintf(ofp, "Case #%d: ", t);
		for(int i=0;a[i];i++)
		{
			if('a'<=a[i] && a[i]<='z') fprintf(ofp, "%c", cmap[a[i]-'a']);
			else fprintf(ofp, "%c", a[i]);
		}
	}

	fclose(fp);
	fclose(ofp);
	char cmd[128];
	strcpy(cmd, "type ");
	strcat(cmd, outfile);
	system(cmd);
	return 0;
}
