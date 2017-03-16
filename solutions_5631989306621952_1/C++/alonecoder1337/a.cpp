#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int ti=1;ti<=t;++ti){
		deque<char> ans;
		string str;
		cin >> str;
		for(int i=0;i<str.length();++i){
			if(ans.empty()==true){
				ans.push_back(str[i]);
			}
			else{
				//cout << ans.front() << "\t" << str[i] << endl;
				if(ans.front()<=str[i]){
					ans.push_front(str[i]);
				}
				else{
					ans.push_back(str[i]);
				}
			}
		}
		cout << "Case #"<<ti << ": " ;
		for(int i=0;i<ans.size();++i){
			cout << ans[i];
		}
		cout << endl;
	}
}
