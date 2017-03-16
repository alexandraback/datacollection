#include<cstdio>

int n,m;
//In min[][] -> min[0][] == row , min[1][] == col 

//Find Max
void findMax(int maps[110][110] , int maxs[][110])
{
	for(int i=0;i<n;i++)
	{
		int mini = 0;
		for(int j=0;j<m;j++)
		{
			if(maps[i][j]>mini)
				mini = maps[i][j];
		}
		maxs[0][i] = mini;
	}
	for(int i=0;i<m;i++)
	{
		int mini = 0;
		for(int j=0;j<n;j++)
		{
			if(maps[j][i]>mini)
				mini = maps[j][i];
		}
		maxs[1][i] = mini;
	}
}

//Search to Cut the grass
bool search(int maps[110][110],int maxs[][110])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!(maps[i][j]>=maxs[0][i]||maps[i][j]>=maxs[1][j]))
			{
				return false;
			}
		}
	}
	return true;
}

// Cut it!!
void cutter(int rnc,int num,int h)
{
	if(rnc==0) //Cut in row
	{
		for(int i=0;i<m;i++)
		{
			//int max
		}
	}
}

int main() 
{
	int tt=1;
	int testcase;
	
	scanf("%d",&testcase);
	while(tt<=testcase)
	{
		int map[110][110];    // Input lawn
		//int resmap[110][110]; // Calculate lawn
		int maxs[2][110];
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				//int cc = j;
				scanf("%d",&map[i][j]);
				//resmap[i][j] = 100;
			}
		}
		findMax(map,maxs);
		if(search(map,maxs))
		{
			printf("Case #%d: YES\n",tt);
		}
		else
		{
			printf("Case #%d: NO\n",tt);
		}
		tt++;
	}
	return 0;
}