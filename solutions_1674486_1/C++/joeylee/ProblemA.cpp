#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("A-large.in");
	FILE* fout;
	fout=fopen("Aans.txt","w");
	int T;
	int N;
	int father;
	fin>>T;
	char** inheri=new char*[1001];
	char** connect=new char*[1001];
	for (int i=0;i<=1000;i++)
	{
		inheri[i]=new char[1001];
		connect[i]=new char[1001];
		for (int j=0;j<=1000;j++)
		{
			inheri[i][j]=0;
			connect[i][j]=0;
		}
	}

	int M[1001];
	vector<int> queue;
	bool finish;
	for (int i=1;i<=T;i++)
	{
		fin>>N;
		for (int p=0;p<=1000;p++)
		{
			for (int q=0;q<=1000;q++)
			{
				inheri[p][q]=0;
				connect[p][q]=0;
			}
		}
		finish=false;
		queue.clear();

		for (int j=1;j<=N;j++)
		{
			fin>>M[j];
			for (int k=0;k<M[j];k++)
			{
				fin>>father;
				inheri[j][father]=1;
			}
		}
		
		for (int j=1;j<=N;j++)
		{
			for (int k=1;k<=N;k++)
			{
				if (inheri[j][k]==1)
				{
					queue.push_back(k);
				}
			}
			while (queue.size()!=0)
			{
				if (connect[j][queue[0]]==1)
				{
					finish=true;
					break;
				}
				else
				{
					connect[j][queue[0]]=1;
					for (int k=1;k<=N;k++)
					{
						if (inheri[queue[0]][k]==1)
						{
							queue.push_back(k);
						}
					}
					for (int k=0;k<(int)queue.size()-1;k++)
					{
						queue[k]=queue[k+1];
					}
					queue.pop_back();
				}
			}
			if (finish==true)
			{
				break;
			}
		}
		if (finish==true)
		{
			fprintf(fout,"Case #%d: Yes\n",i);
		}
		else
		{
			fprintf(fout,"Case #%d: No\n",i);
		}

	}





		
	fin.close();
	fclose(fout);
	return 0;
}