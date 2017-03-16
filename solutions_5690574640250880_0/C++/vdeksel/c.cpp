#include <vector>
#include <algorithm>
#include <fstream>
#include <list>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;
int r,c,m;
int s[60][60];
	
bool findsol()
{
	int i;
	int k = r*c-m;
	int zr,zc;
	for (zr=1;zr<=r;zr++)
	{
		for (zc=1;zc<=c;zc++)
		{
			s[zr][zc]=0;			// 1 = free, 0 = mine
		}
	}

	if (k==1)
	{
		s[1][1]=1;
		return true;
	}
	if (c==1)
	{
		for (i=1;i<=k;i++)
			s[i][c]=1;
		return true;
	}
	if (r==1)
	{
		for (i=1;i<=k;i++)
			s[r][i]=1;
		return true;
	}
	if (c==2)
	{
		if ((k % 2 == 1) || (k==2))
			return false;
		for (i=1;i<=k/2;i++)
		{
			s[i][1]=1;
			s[i][2]=1;
		}
		return true;
	}
	if (r==2)
	{
		if ((k % 2 == 1) || (k==2))
			return false;
		for (i=1;i<=k/2;i++)
		{
			s[1][i]=1;
			s[2][i]=1;
		}
		return true;
	}
	if (k==2 || k==3 || k==5 || k==7)
		return false;
	int fr = k;
	int frrow = 0;
	for (zr=1;zr<=r;zr++)
	{
		if (k>=2*c+2)
		{
			if (fr != c+1)
				frrow = min(fr, c);
			else
				frrow = c-1;
		}
		else
		{
			if (k % 2 == 0)			
				frrow = min(fr, k/2);
			else
				frrow = min(fr, (k-3)/2);
		}
		fr -= frrow;
		for (zc=1;zc<=frrow;zc++)
			s[zr][zc]=1;
	}
}

void start()
{
	fprintf(aus, "Case #%d: \n", TestCase);	
	// read test case
	ein >> r >> c >> m;	
	if (!findsol())
	{
		fprintf(aus,"Impossible\n");
		return;
	}
	else
	{
		for (int zr=1;zr<=r;zr++)
		{
			for (int zc=1;zc<=c;zc++)
			{
				if (zr==1 && zc==1)
					fprintf(aus,"c");
				else
				{
					if (s[zr][zc]==1)
						fprintf(aus,".");
					else
						fprintf(aus,"*");
				}					
			}
			fprintf(aus,"\n");
		}
		
		// check if ok
		int chk[60][60];
		for (int zr=1;zr<=r;zr++)
		{
			for (int zc=1;zc<=c;zc++)
			{
				chk[zr][zc]=0;
			}
		}

		int tes =0;
		list<pair<int,int>> wl;
		wl.push_back(make_pair(1,1));
		while (!wl.empty())
		{
			pair<int,int> p;
			p = *wl.begin();
			wl.pop_front();
			if (chk[p.first][p.second]==0)
			{
				chk[p.first][p.second] = 1;
				tes++;
				// count mine-neighbours
				int emp = 0;
				int minzr = max(p.first-1,1);
				int maxzr = min(p.first+1,r);
				int minzc = max(p.second-1,1);
				int maxzc = min(p.second+1,c);
				for (int zr=minzr; zr<=maxzr;zr++)
				{
					for (int zc=minzc;zc<=maxzc;zc++)
					{
						if (zr != p.first || zc != p.second)
							emp += (1-s[zr][zc]);
					}
				}
				if (emp==0)
				{
					for (int zr=max(p.first-1,1);zr<=min(p.first+1,r);zr++)
						for (int zc=max(p.second-1,1);zc<=min(p.second+1,c);zc++)					
							wl.push_back(make_pair(zr,zc));
				}
			}
		}
		if (tes != r*c-m)
		{
			printf("error testcase %d", TestCase);
			getchar();
			exit;
		}		
	}	
}

void main()
{
	int NumTestCases;	
	ein.open("C-small-attempt3.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
