#include<iostream>
#include<cmath>

using namespace std;

string s1[20], s2[20];
int n, T, ans, m;

void check(int x) {
	int k = 0;
	bool b = true;
	bool b1, b2;
	for(int i=0; i<n; i++) 
		if((x&(1<<i))>0) {
			k++;
			b1 = b2 = false;
			for(int j=0; j<n; j++) 
				if((x&(1<<j))==0) {
					if(s1[i]==s1[j]) b1 = true;
					if(s2[i]==s2[j]) b2 = true;
				}
			if(!(b1 && b2))	{
				b = false;
				break;
			}
		}
	if (b) ans = max(k,ans);
}

int main() {
	cin>>T;
	for(int t=1; t<=T; t++) {
		cin>>n;
		m = 1;
		for(int i=0; i<n; i++) cin>>s1[i]>>s2[i], m*=2;
		ans = 0;
		for(int i=0; i<m; i++) check(i);
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}