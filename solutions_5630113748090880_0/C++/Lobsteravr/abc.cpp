#include<bits/stdc++.h>
using namespace std;

int main()
{	freopen("inp.txt","r",stdin);
	freopen("outs.txt","w",stdout);

	int z;
	cin>>z;
	for(int t=1;t<=z;t++)
	{
	
	int n;
	cin>>n;
	cout<<"Case #"<<t<<": ";
	int arr[100][100];
	int count[2505]={0};
	for(int i=0;i<2*n-1;i++)
		for(int j=0;j<n;j++)
			{cin>>arr[i][j]; count[arr[i][j]]++;}
	for(int i=1;i<=2500;i++)
	    if(count[i]%2==1)
	        cout<<i<<" ";
    cout<<endl;
	}
return 0;
}