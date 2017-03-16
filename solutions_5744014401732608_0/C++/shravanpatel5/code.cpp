#include<cmath>
#include <iostream>
using namespace std;
int main() 
{
	long long int t,i1,b,m,arr[100],flag,max,i,mat[100][100],j;
	cin>>t;
	for(i1=0;i1<t;i1++)
	{
		cout<<"Case #"<<i1+1<<": ";
		cin>>b>>m;
		for(i=1;i<=b;i++)
		{
			arr[i]=0;
		}
		max=pow(2,b-2);
		if(max<m)
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}cout<<"POSSIBLE"<<endl;
		arr[b]=1;
		arr[b-1]=1;
		flag=0;
		for(i=b-2;i>0;i--)
		{
			if(flag==0){
			if(m<=pow(2,b-i-1))
			{
				arr[i]=m;
				flag=1;
			}
			else
			{
				arr[i]=pow(2,b-i-1);
			}
			
			}
			else
			{
				arr[i]=arr[i+1];
			}
		}
		//for(i=1;i<=b;i++)
		//	cout<<arr[i]<<endl;
		for(i=1;i<=b;i++)
		{
			for(j=1;j<=b;j++)
			{
				mat[j][i]=0;
			}
		//	mat[b][i]=0;
		}
		mat[b-1][b]=1;
		for(i=b-2;i>0;i--)
		{
			
			if(arr[i]==pow(2,b-i-1))
			{
				for(j=i+1;j<=b;j++)
					mat[i][j]=1;
			}
			else
			{
			//	if(i==1)
			//		cout<<arr[1]<<endl;
				for(j=b;j>i;j--)
				{
					//cout<<
					if(j==b-1)
						continue;
					mat[i][j]=arr[i]%2;
					arr[i]=arr[i]/2;
				}
			}
		}
		for(i=1;i<=b;i++)
		{
			for(j=1;j<=b;j++)
			{
				cout<<mat[i][j];
			}cout<<endl;
		//	mat[b][i]=0;
		}
	}
	return 0;
}
