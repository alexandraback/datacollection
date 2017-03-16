#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T,D,P;
	int arr[2000],cost[2000];
	cin>>T;
	int i,j,k,max;
	for(int t=0;t<T;t++)
	{
		cin>>D;
		max = 0;
		for(i=0;i<D;i++) 
		{
			cin>>arr[i];
			if(arr[i]>max) max = arr[i];
		}
		for(k=1;k<=max;k++)
		{
			int cut=0;
			for(i=0;i<D;i++)
			{
				if(arr[i]<=k) continue;
				cut+= (arr[i]/k)-1;
				if(arr[i]%k!=0) cut++;
			}
			cost[k]=k+cut;
		}
		int min=10000;
		for(k=1;k<=max;k++)
			if(cost[k]<min) min=cost[k];
		cout<<"Case #"<<t+1<<": "<<min<<endl;
			
	}

	return 0;

}
