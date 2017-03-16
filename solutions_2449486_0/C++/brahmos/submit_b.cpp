#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{

int n,m,t,k,i,j,a,b;
cin>>t;
for(k=1;k<=t;k++)
{
	cin>>n>>m;
	
	int arr[100][100];
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	cin>>arr[i][j];
	int row_max[100]={0};
	int col_max[100]={0};
	int maxi;
	for(i=0;i<n;i++)
	{
	maxi=arr[i][0];
	for(j=0;j<m;j++)
	{
		if(arr[i][j]>maxi)
		maxi=arr[i][j];
	}
	row_max[i]=maxi;
	}
	
	for(i=0;i<m;i++)
	{
	maxi=0;
	for(j=0;j<n;j++)
	{
		if(arr[j][i]>maxi)
		maxi=arr[j][i];
	}
	col_max[i]=maxi;
	}
	
	bool flag=true;
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
		if(arr[i][j]>=row_max[i] || arr[i][j]>=col_max[j])
		flag=true;
		else
		{
		flag=false;
		break;
		}
	}
	if(flag==false)
	break;
	}
	
	if(flag==false)
	cout<<"Case #"<<k<<": NO\n";
	else
	cout<<"Case #"<<k<<": YES\n";
	}
return 0;
}
