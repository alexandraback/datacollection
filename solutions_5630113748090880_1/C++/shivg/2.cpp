#include<iostream>

using namespace std;



int main()
{
	int t;
	cin>>t;
	int icase = 1;
	
	while(t--)
	{
		int n;
		int arr[3000] = {0};
		cin>>n;
		int in;

		for(int i=0;i<2*n-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>in;
				arr[in] = arr[in]+1;
			}
		}
		cout<<"Case #"<<icase++<<": ";
		for(int i=1;i<2501;i++)
			if(arr[i]%2)
			{
				cout<<i<<" ";
			}				
		cout<<endl;
	}

	return 0;
}