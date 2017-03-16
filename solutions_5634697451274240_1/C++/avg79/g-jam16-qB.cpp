#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>


int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	if (argc > 1)
	{
		char tname[200];
		fin = fopen(argv[1],"r");
		strncpy (tname,argv[1],200);
		strncpy(strstr (tname,".in"),".out",4);
		fout = fopen(tname,"w");
	} else {
		fin = fopen("A.in","r");
		fout = fopen("A.out","w");
	}


	int t;
	fscanf(fin,"%d",&t);
	char pks[104];
	fgets(pks,10,fin);
	for (int ti=0; ti<t; ti++)
	{
		fgets(pks,102,fin);
		int ln = strlen(pks)-1;
		char sign = 0;
		int answ = -1;
		for (int i=0; i<ln; i++)
		{
			if (pks[i] != sign)
			{
				answ++;
				sign = pks[i];
			}
		}
		if (sign == '-')
		{
			answ++;
		}
		fprintf(fout,"Case #%d: %d\n", ti+1, answ);

	}
	fclose(fin);
	fclose(fout);
	return 0;
}