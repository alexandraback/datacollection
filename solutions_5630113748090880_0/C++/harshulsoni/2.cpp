#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("input2small.in", "r", stdin);
	freopen("output2small.in", "w", stdout);
	int t, arr[2505], i, j, k, n,x,l;
	cin>>t;
	l=1;
	while(t--){
		memset(arr, 0, sizeof(arr));
		cin>>n;
		k=2*n-1;
		for(i=0;i<k;i++){
			for(j=0;j<n;j++){
				cin>>x;
				arr[x]++;
			}
		}
		cout<<"Case #"<<l<<":";
		l++;
		for(i=0;i<2505;i++){
			if(arr[i]%2!=0){
				cout<<" "<<i;
			}
		}
		cout<<endl;
	}
	return 0;
}