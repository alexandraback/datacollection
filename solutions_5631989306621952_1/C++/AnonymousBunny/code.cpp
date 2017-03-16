#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector <int> V, p1, p2, cur;
int uu;
int main() {
	// your code goes here
	int t;
	cin>>t;
	string qq= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (uu=1; uu<=t; uu++){
		string s;
		cin>>s;
		V.clear();
		cur.clear();
		for (int i=0; i<s.length(); i++) V.push_back(s[i]-'A');
		cur.push_back(V[0]);
		for (int i=1; i<V.size(); i++){
			p1.clear();
			p2.clear();
			p2.push_back(V[i]);
			for (int j=0; j<cur.size(); j++) {
				p1.push_back(cur[j]);
				p2.push_back(cur[j]);
			}
			p1.push_back(V[i]);
			bool ok=0;
			for (int j=0; j<p1.size(); j++){
				if (p1[j]==p2[j]) continue;
				if (p1[j]<p2[j]){
					ok=1;
					break;
				}
				ok=0;
				break;
			}
			if (ok){
				cur.clear();
				for (int j=0; j<p2.size(); j++) cur.push_back(p2[j]);
			}
			else{
				cur.clear();
				for (int j=0; j<p1.size(); j++) cur.push_back(p1[j]);
			}
		}
		cout<<"Case #"<<uu<<": ";
		for (int i=0; i<cur.size(); i++) cout<<qq[cur[i]];
		cout<<endl;
	}
	return 0;
}
