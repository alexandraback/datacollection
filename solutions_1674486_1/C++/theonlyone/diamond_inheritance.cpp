#include<iostream>
#include<fstream>
#include<string>
#include<strings.h>

using namespace std;

int inher[1000][1000]={0},marked[1000]={0};



int diamond(int node,int n)
{
	int i,j=0,k;
	//cout << node << "->";
	if(marked[node])
	{
		//cout << "Node " << node << "n " << n;
		return 1;
	}
	marked[node]=1;
	for(i=0;i<n;i++)
	{
		if(inher[node][i])
		{
			j=diamond(i,n);
			//cout << "\n";
		}
		if(j) break;
		
	}
	return j;
}


void fileIO()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
}

main()
{
	int t,n,m[1000],i,j,k,l;
	
	fileIO();
	cin >> t;
	for(l=1;l<=t;l++)
	{
		cout << "Case #" << l << ": ";
		
		cin >> n;
		for(i=0;i<n;i++)
		{
			cin >> m[i];
			for(j=0;j<m[i];j++)
			{
				cin >> k;
				inher[i][k-1]=1;
			}
		}

		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout << inher[i][j] << " ";
			cout << "\n";
		}*/
		for(i=0;i<n;i++)
		{
			j=diamond(i,n);
			bzero(marked,4*n);
			if(j) break;
			//cout << "\n";
		}
		//cout << "i " << i;
		if(i==n)
			cout << "No\n";
		else
			cout << "Yes\n";

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				inher[i][j]=0;
	}
}
