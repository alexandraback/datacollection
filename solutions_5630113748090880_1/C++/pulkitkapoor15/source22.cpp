#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("codejam11.txt","r",stdin);
	freopen("output_file_name.txt","w",stdout);
	int totalCounts,testCases,num1,n,j,subm;
	cin>>totalCounts;
	for(testCases=1;testCases<=totalCounts;testCases++)
	{
		int arrs[3001];
		for(num1=0;num1<=3000;num1++)
		{
			arrs[num1]=0;
		}
		cin>>n;
		for(num1=0;num1<(2*n-1);num1++)
		{
			for(j=0;j<n;j++)
			{
				cin>>subm;
				arrs[subm]++;
			}
		}
		cout<<"Case #"<<testCases<<": ";
		for(num1=0;num1<=3000;num1++)
		{
			if(arrs[num1]%2==1)
			{
				cout<<num1<<" ";
			}

		}
		cout<<endl;
	}

}
