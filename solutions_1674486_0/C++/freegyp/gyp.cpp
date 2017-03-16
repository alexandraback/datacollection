#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
typedef set<int> sint;
typedef set<int>::iterator sinti;
struct board
{
	int route[51][51],max;
	board(int n)
	{
		max=n;
		for(int i=0;i<51;i++)
		{
			for(int j=0;j<51;j++)
			{
				route[i][j]=0;
			}
		}
	}
	int find()
	{
		for(int i=1;i<=max;i++)
		{
			sint processed,toprocess;
			for(int j=1;j<=max;j++)
			{
				if(route[i][j]==1)toprocess.insert(j);
			}
			while(!(toprocess.empty()))
			{
				sint processing;
				processing.insert(toprocess.begin(),toprocess.end());
				toprocess.clear();
				for(sinti si=processing.begin();si!=processing.end();si++)
				{
					for(int j=1;j<=max;j++)
					{
						if(route[(*si)][j]!=0)
						{
							if((processed.find(j)!=processed.end())||(toprocess.find(j)!=toprocess.end())||(processing.find(j)!=processing.end()))
							{
								return 1;
							}
							else
							{
								toprocess.insert(j);
							}
						}
					}
					processed.insert((*si));
				}
			}
		}
		return 0;
	}
};
int main()
{
	ifstream gin("A-small-attempt2.in");
	ofstream gout("gypAsmall.out");
	int T,N,M;
	gin>>T;
	for(int i=0;i<T;i++)
	{
		gin>>N;
		board nn(N);
		for(int j=0;j<N;j++)
		{
			gin>>M;
			for(int k=0;k<M;k++)
			{
				int temp;gin>>temp;
				nn.route[j+1][temp]++;
			}
		}
		int yes=nn.find();
		if(yes)gout<<"Case #"<<i+1<<": Yes"<<endl;
		else gout<<"Case #"<<i+1<<": No"<<endl;
	}
	gout.close();
	gin.close();
	return 0;
}
