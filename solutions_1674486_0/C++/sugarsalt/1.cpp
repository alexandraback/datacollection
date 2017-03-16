#include <iostream>
#include <cstring>
using namespace std;

int m[10];
int mn;
int n;
bool g[1001][1001];

int npath(int i,int j)
{
	if (i==j) return 1;
	int count=0;
	for(int k=1;k<=n;k++)
		if(g[i][k]) count+=npath(k,j);
	return count;
}

int run(int casenr)
{
	memset(g,0,sizeof(g));
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>mn;
		int mi;
		for(int j=0;j<mn;j++) 
		{
			cin>>mi; g[i][mi]=true;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (npath(i,j)>=2)
			{
				cout<<"Case #"<<casenr<<": Yes"<<endl;
				return 0;
			}

	cout<<"Case #"<<casenr<<": No"<<endl;
	return 0;
}

int main()
{
	int tn;cin>>tn;
	for (int i=1;i<=tn;i++) run(i);
	return 0;
}
