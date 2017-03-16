#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
	int tc; cin >> tc;
	for(int t=1;t<=tc;t++){
		cout << "Case #" << t << ": ";
		string s; cin >> s;
		int nextchartoclear = s.size()-1;
		int nextchartoleave = nextchartoclear;
		queue<char> front;
		stack<char> behind;
		for(char c='Z';c>='A';c--){
			nextchartoleave = nextchartoclear;
			for(int i=nextchartoclear;i>=0;i--){
				if(s[i]==c){
					nextchartoleave = i-1;
				}
			}
			for(int i=nextchartoclear;i>nextchartoleave;i--){
				if(s[i]==c){
					front.push(s[i]);
				} else {
					behind.push(s[i]);
				}
			}
			nextchartoclear = nextchartoleave;
		}
		while(!front.empty()){
			cout << front.front();front.pop();
		}
		while(!behind.empty()){
			cout << behind.top();behind.pop();
		}
		cout << endl;
	}
}