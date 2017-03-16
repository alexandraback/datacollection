#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>

#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define SIZE(v) ((int)(v).size())
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
typedef long long ll;
using namespace std;

string s;
int n;
set<char> setv;
void solve(){
	cin>>s;
	cin>>n;
	int sum=0;
	FOR(i,0,s.length())
		FOR(j,i+n-1,s.length()){
			if (j>=s.length())	break;
			bool ok=false;
			int maxlen=0;
			FOE(k,i,j){
				if (setv.find(s[k]) != setv.end()){
					maxlen=0;
				}
				else{
					maxlen++;
					if (maxlen>=n){
						ok=true;
						break;
					}
				}
			}
			if (ok)	sum++;
		}

	cout<<sum<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	setv.insert('a');
	setv.insert('e');
	setv.insert('i');
	setv.insert('o');
	setv.insert('u');
	int t;
	cin>>t;
	FOR(i,0,t){
		cout<<"Case #"<<i+1<<": ";
		solve();
	}
	return 0;
}
