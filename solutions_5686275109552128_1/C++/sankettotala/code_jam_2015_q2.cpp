#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#define debug 1

int main(){
	int t;
	cin>>t;
	for(int iiii = 1; iiii<=t; iiii++){
		int n;
		cin>>n;
		int arr[n];
		int max = 0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			max = max>arr[i]?max:arr[i];
		}
		int ans = max;
		for(int i=1; i<max; i++){
			int divt = 0, eatt = 0;
			for(int j=0; j<n; j++){
				int nogr = (arr[j]+i-1)/i;
				int greatt = (arr[j]+nogr-1)/nogr;
				//cout<<i<<" "<<j<<" "<<nogr<<" "<<greatt<<endl;
				eatt = eatt>greatt?eatt:greatt;
				divt += (nogr-1);
			}
			ans = ans<divt+eatt?ans:divt+eatt;
		}
		cout<<"Case #"<<iiii<<": "<<ans<<endl;
	}
}
