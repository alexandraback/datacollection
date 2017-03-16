#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
	int t; cin >> t;
	string s;
	for (int tc = 1; tc <= t; tc++){
		cin >> s;
		list<char> ans;
		ans.push_back(s[0]);
		for (int i = 1; i < s.size(); i++){
			if (s[i] >= (*ans.begin())){
				ans.push_front(s[i]);
			}
			else ans.push_back(s[i]);
		}
		string x = "";
		for (auto it = ans.begin(); it != ans.end(); it++)x += *it;
	//	printf("Case #%i: %s\n", tc, x);
		cout<<"Case #"<<tc<<": " << x << "\n";
	}
}