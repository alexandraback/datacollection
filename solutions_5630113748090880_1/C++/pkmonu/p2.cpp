#include<iostream>
#include <string.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1; t<=T; t++) {
        	int n;
		cin>>n;
		int arr[2501] = {0};
		// memset(arr, 0, 2501*sizeof(int));
		for(int i=0; i<2*n-1; i++)
		{
			for(int j=0; j<n; j++) {
				int x;
				cin>>x;
				arr[x]++;
			}
		}
		
	cout<<"Case #"<<t<<": ";
		int d=0;
		for(int p=1; p<=2501; p++)
		{
			if(d==n)
			break;
			if(arr[p]%2!=0){
				cout<<p<<" ";
				d++;
			}
		}
	cout<<endl;
	}
}
