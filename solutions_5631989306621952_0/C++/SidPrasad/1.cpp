#include <bits/stdc++.h>
using namespace std;


vector<char> word;
vector<char>::iterator it;
long l, T;
string S;
int main(){

	cin>>T;
	for(int t=0; t<T; t++) {
		word.clear();
		cin>>S;

		l = S.length();
		word.push_back(S[0]);
		for(int i=1; i<l; i++) {
			if(S[i] >= word[0]) {
				it = word.begin();
				it = word.insert ( it , S[i] );
			}
			else {
				word.push_back(S[i]);
			}
		}
		cout<<"Case #"<<t+1<<": ";
		for(int i=0; i<l; i++) {
			cout<<word[i];
		}
		cout<<endl;
	}


  return 0;
}