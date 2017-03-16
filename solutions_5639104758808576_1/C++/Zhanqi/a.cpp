#include <iostream>

using namespace std;

int T,n;
string s;

int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>n;
		cin>>s;
		int sum=int(s[0]-'0');
		int ans=0;
		for (int i=1; i<=n; i++) {
			int a=int(s[i]-'0');
			if (sum<i) {
				ans+=i-sum;
				sum=i;
			}
			sum+=a;
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}