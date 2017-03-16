#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d\n",&n);
	for(int i = 0; i < n; i++){
		cin >> s;
		deque<char> word;
		for(auto i : s){
			if(word.empty()) word.push_back(i);
			else if(word.front() <= i) word.push_front(i);
			else word.push_back(i);
		}
		string res;
		for(auto i : word){
			res += i;
		}
		cout << "Case #" << i+1 << ": " << res << endl;
	}
}