#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

string N;
string M;

string add(string s){
	string t=s;
	for(int i=s.size()-1; i >= 0; --i){
		if(s[i] == '9'){
			t[i]='0';
		}
		else{
			++t[i];
			return t;
		}
	}
	t="1" + t;
	return t;
}

string rev(string s){
	string t;
	bool nonzero=0;
	for(int i=s.size()-1; i >= 0; --i){
		if(s[i] == '0' && !nonzero)
			continue;
		nonzero=1;
		t.push_back(s[i]);
	}
	return t;
}

queue<string> q;
map<string, int> dis;
map<string, bool> vis;

void solve(){
	cin >> N;
	printf("%d\n", dis[N]+1);
}

int main(){
	vis["1"]=1;
	dis["1"]=0;
	q.push("1");
	while(!q.empty()){
		string s;
		s=q.front();
		if(s.size() > 6)
			break;
		q.pop();
		string t=add(s);
		if(!vis[t]){
			vis[t]=1;
			dis[t]=dis[s]+1;
			q.push(t);
		}
		t=rev(s);
		if(!vis[t]){
			vis[t]=1;
			dis[t]=dis[s]+1;
			q.push(t);
		}
	}
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
