#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.txt","w",stdout);
	int t;
	string str;
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans = 0;
		cin>>str;
		int j = 0;
		while(j<(int)str.size()){
			while(j<(int)str.size()-1 && str[j] == str[j+1]) j++;
			j++;
			ans++;
		}
		if(str[0] == '+' && ans%2 == 1)
			ans--;
		else if(str[0] == '-' && ans%2 == 0)
			ans--;
		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}
	return 0;
}