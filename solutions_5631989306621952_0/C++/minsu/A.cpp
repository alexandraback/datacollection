#include <bits/stdc++.h>
using namespace std;

deque<char> dq;
string s,a;
int main(){
	int T;
	cin>>T;
	for(int t=1; t<=T; t++){
		cin>>s;
		a.clear();
		dq.clear();
		for(auto it : s){
			if( dq.empty() ) dq.push_back(it);
			else{
				if( dq.front() <= it ){
					dq.push_front(it);
				}else{
					dq.push_back(it);
				}
			}
		}
		for(auto it : dq )
			a.push_back(it);
		cout<<"Case #"<<t<<": "<<a<<"\n";
	}
	return 0;
}
