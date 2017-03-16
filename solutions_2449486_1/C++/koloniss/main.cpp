#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int mas[105][105];
int n,m;

int prog()
{
	memset(mas,0,sizeof(mas));
		cin>>n>>m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j<m;j++)
			{
				cin>>mas[i][j];
			}
		for (int k = 1; k <= 101;k++)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j< m;j++)
				{
					if (mas[i][j]==k)
					{
						bool allk = true;
						for (int z = 0; z < n;z++)
							if (mas[z][j]!=k && mas[z][j]!=0) allk = false;
						if (allk)
							for (int z = 0;z<n;z++) 
								mas[z][j]=0;
						bool allk1 = true;
						for (int z = 0; z < m;z++)
							if (mas[i][z]!=k && mas[i][z]!=0) allk1 = false;
						if (allk1)
							for (int z = 0;z<m;z++) 
								mas[i][z]=0;
						if (!allk1 && !allk) {
							cout<<"NO"<<endl;
							return 0;
						}
					}
				}
		}
		cout<<"YES"<<endl;	
		return 0;
}


int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for (int t = 0;t < T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		prog();
	}
	return 0;
}