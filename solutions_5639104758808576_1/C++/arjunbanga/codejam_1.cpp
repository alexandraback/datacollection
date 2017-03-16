#include<bits/stdc++.h>
using namespace std;
int arr[10009];
int main()
{
	freopen("inp.in","r",stdin);

	freopen("outp.out","w",stdout);
	int t;	
	cin>>t;	
	for(int ca = 1; ca <= t; ca++) {
		int smax;
		cin>>smax;
		string s;
		cin>>s;
		for(int i = 0; i <= smax; i++) {
			arr[i] = s[i] -'0';
		}
		int sum = arr[0];
		long long ans = 0;
		for(int i = 1; i <= smax; i++) {
			if(i - sum > 0) {
				ans += i - sum;
				sum+= i-sum;
			}
			sum+=arr[i];
		}	
		cout<<"Case #"<<ca<<": "<<ans<<endl;
	}
	return 0;
}
