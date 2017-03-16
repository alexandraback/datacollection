#include<iostream>
#include <string.h>
#include <queue>
#include <fstream>
using namespace std;
int main()
{
	int t;
	int n;
	int mi;
	int her;
	int matrix[100][100];
	int isuse[100];
	bool end;
	queue<int> search;
	ofstream out("ans.out");
	cin>>t;
	{

		for (int i = 0 ;i<t;i++)
		{
			end = false;
			memset(matrix , 0, sizeof(matrix));
			cin>>n;
			for (int j = 0;j<n;j++)
			{
				cin>>mi;
				for (int k = 0;k<mi;k++)
				{
					cin>>her;
					matrix[j][her-1] = 1;
				}
			}
			//信息保存在matrix中

			for (int j = 0;j<n;j++)
			{
				memset(isuse , 0 ,sizeof(isuse));
				if (!search.empty())
				{
					search.pop();
				}
				search.push(j);
				isuse[j]++;
				while (!search.empty())
				{
					int temp = search.front();
					search.pop();
					for (int k = 0;k<n;k++)
					{
						if (matrix[temp][k] == 1)
						{
							if (isuse[k] == 1)
							{
								end = true;
								break;								
							}
							search.push(k);
							isuse[k]++;
						}
					}
					if (end)
					{
						break;
					}
				}
				if (end)
				{
					break;
				}
			}

			if (end)
			{
				out<<"Case #"<<i+1<<": Yes"<<endl;
			}
			else
				out<<"Case #"<<i+1<<": No"<<endl;
		}
	}
} 