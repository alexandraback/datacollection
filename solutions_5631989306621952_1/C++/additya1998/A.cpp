#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("A-large.in","r",stdin);
	freopen("output.out","w",stdout);

	int t;
	cin >> t;
	int c = 0;
	while(t--){
		string s;
		cin >> s;
		string temp;
		char ff = s[0], ss=s[0];
		temp = s[0];
		for(int i=1; i<s.size(); ++i){
			char x = s[i];
			if(x>=ff){
				ff = x;
				temp = x + temp;
			}
			else{
				ss = x;
				temp = temp + x;
			}
		}
		cout << "Case #" << ++c <<": " << temp << endl;
	}
}
