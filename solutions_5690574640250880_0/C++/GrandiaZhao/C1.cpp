#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define real int

int M,R,C,H;
int maxDepth;
vector<vector<int>> matrix;

bool determine()
{
}

void createMatrix(int num=0)
{
	matrix.clear();
	vector<int> line;
	line.resize(C,num);
	matrix.resize(R,line);
}

void printMatrix()
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(matrix[i][j]==0) printf(".");
			else if(matrix[i][j]==2) printf("c");
			else printf("*");
		}
		printf("\n");
	}
}

void getMatrix()
{
	H=R*C-M;

	if(R==1||C==1)
	{
		if(H==0)
		{
			printf("Impossible\n");
			
			return;
		}
		else
		{
			createMatrix();
			int count=0;
			matrix[0][0]=2;
			for(int i=0;i<R;i++)
			{
				for(int j=0;j<C;j++)
				{
					if(count<H)
					{

					}
					else
					{
						matrix[i][j]=1;
					}
					count++;
				}
			}
			printMatrix();
			return;
		}
	}
	else if(R==2||C==2)
	{
		if(H==1)
		{
			createMatrix(1);
			matrix[0][0]=2;
			printMatrix();
			return;
		}
		else if(H%2==1||H<4)
		{
			printf("Impossible\n");
			
			return;
		}
		else
		{
			createMatrix();
			int count=0;
			
			if(R==2)
			{
				for(int i=0;i<C;i++)
				{
					for(int j=0;j<R;j++)
					{
						if(count<H)
						{

						}
						else
						{
							matrix[j][i]=1;
						}
						count++;
					}
				}
			}
			else
			{
				for(int i=0;i<R;i++)
				{
					for(int j=0;j<C;j++)
					{
						if(count<H)
						{

						}
						else
						{
							matrix[i][j]=1;
						}
						count++;
					}
				}
			}
			matrix[0][0]=2;
			printMatrix();
			return;
		}
	}
	else
	{
		if(H==1)
		{
			createMatrix(1);
			matrix[0][0]=2;
			printMatrix();
			return;
		}
		else if(H%2==0)
		{
			if(H<4)
			{
				printf("Impossible\n");
				
				return;
			}
			else
			{
				createMatrix(1);
				int left=H;
				int count=0;
				bool exit=false;
				for(int j=0;j<C;j++)
				{
					for(int i=0;i<2;i++)
					{
						matrix[i][j]=0;
						count++;
						if(count==left)
						{
							exit=true;
							break;
						}
					}
					if(exit) break;
				}

				if(count<left)
				{
					exit=false;
					for(int i=2;i<R;i++)
					{
						for(int j=0;j<2;j++)
						{
							matrix[i][j]=0;
							count++;
							if(count==left)
							{
								exit=true;
								break;
							}
						}
						if(exit) break;
					}
				}

				if(count<left)
				{
					exit=false;
					for(int i=2;i<R;i++)
					{
						for(int j=2;j<C;j++)
						{
							matrix[i][j]=0;
							count++;
							if(count==left)
							{
								exit=true;
								break;
							}
						}
						if(exit) break;
					}
				}

				matrix[0][0]=2;
				printMatrix();
				return;
			}
			
		}
		else  //even
		{
			if(H<9)
			{
				printf("Impossible\n");
				
				return;
			}
			else
			{
				createMatrix(1);
				int left=H;
				int count=0;
				bool exit=false;
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						matrix[i][j]=0;

				count=9;

				if(count<left)
				{
					exit=false;
					for(int j=3;j<C;j++)
					{
						for(int i=0;i<2;i++)
						{
							matrix[i][j]=0;
							count++;
							if(count==left)
							{
								exit=true;
								break;
							}
						}
						if(exit) break;
					}
				}
				

				if(count<left)
				{
					exit=false;
					for(int i=3;i<R;i++)
					{
						for(int j=0;j<2;j++)
						{
							matrix[i][j]=0;
							count++;
							if(count==left)
							{
								exit=true;
								break;
							}
						}
						if(exit) break;
					}
				}

				if(count<left)
				{
					exit=false;
					count--;
					for(int i=2;i<R;i++)
					{
						for(int j=2;j<C;j++)
						{
							matrix[i][j]=0;
							count++;
							if(count==left)
							{
								exit=true;
								break;
							}
						}
						if(exit) break;
					}
				}

				matrix[0][0]=2;
				printMatrix();
				return;
			}
		}
	}
}

void main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);

	int times;
	scanf("%d",&times);
	for(int time=1;time<=times;time++)
	{
		scanf("%d %d %d",&R,&C,&M);
		printf("Case #%d:\n",time); 
		
		getMatrix();
		//printf("%d %d %d %d\n",R,C,H,M);
	}
}