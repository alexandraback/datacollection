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

	for (int ti=0; ti<t; ti++)
	{
		int k,c,s;
		fscanf(fin,"%d", &k);
		fscanf(fin,"%d", &c);
		fscanf(fin,"%d", &s);
		if (c==1)
		{
			if (s<k)
			{
				fprintf(fout,"Case #%d: IMPOSSIBLE\n", ti+1);
			} 
			else
			{
				fprintf(fout,"Case #%d:", ti+1);
				for (int i=0; i<k; i++)
				{
					fprintf(fout," %d", i+1);
				}
				fprintf(fout,"\n");
			}
		} 
		else
		{
			if (s<(k+c-1)/c)
			{
				fprintf(fout,"Case #%d: IMPOSSIBLE\n", ti+1);
			} 
			else
			{
				fprintf(fout,"Case #%d:", ti+1);
				int nlev = (k + c - 1)/c;

				for (int i=0; i<nlev; i++)
				{
					long long posl = i*c;
					for (int lev = 1; lev<c; lev++)
					{
						long long ip = i*c + lev;
						if(ip>k-1) ip = k-1;
						posl = posl*k + ip;
					}
					fprintf(fout," %lld", posl+1);
				}
				fprintf(fout,"\n");
			}
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}