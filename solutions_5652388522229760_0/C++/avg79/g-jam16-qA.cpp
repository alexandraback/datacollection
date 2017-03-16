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
		int n;
		fscanf(fin,"%d", &n);
		if (n==0)
		{
			fprintf(fout,"Case #%d: INSOMNIA\n", ti+1);
		} 
		else
		{
			int dwas[10];
			for (int i=0; i<10; i++)
			{
				dwas[i] = 0;
			}

			long long lastnum = 0;
			int ndig = 0;
			for (long long m=1; m<1000000; m++ )
			{
				long long cnum = m * n;
				lastnum = cnum;
				while(cnum>0)
				{
					long long div = cnum/10;
					long long rest = cnum - div*10;
					if (dwas[rest] == 0)
					{
						ndig++;
						dwas[rest]++;
					}
					cnum = div;
				}
				if (ndig ==10)
				{
					break;
				}
			}
			fprintf(fout,"Case #%d: %lld\n", ti+1, lastnum);

		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}