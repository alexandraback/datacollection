#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef pair<int, ll> Pil;
typedef pair<string,string> Pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
string C,J;
int mx;
void dfs(string a,string b,int depth){
	if(depth == a.size()){
		int ret = abs(atoi(a.c_str())-atoi(b.c_str()));
		if(ret < mx){
			C = a;
			J = b;
			mx = ret;
		}
		return ;
	}
	if(a[depth] == '?' && b[depth] != '?'){
		rep(i,10){
			a[depth] = i+'0';
			dfs(a,b,depth+1);
			a[depth] = '?';
		}
	}
	if(a[depth] != '?' && b[depth] == '?'){
		rep(i,10){
			b[depth] = i+'0';
			dfs(a,b,depth+1);
			b[depth] = '?';
		}
	}
	if(a[depth] == '?' && b[depth] == '?'){
		rep(i,10){
			rep(j,10){
				a[depth] = i+'0';
				b[depth] = j+'0';
				dfs(a,b,depth+1);
				a[depth] = b[depth] = '?';
			}
		}
	}
	if(a[depth] != '?' && b[depth] != '?'){
		dfs(a,b,depth+1);
	}
	return ;
}
Pss solve(string str1,string str2){
	mx = INF;
	C = "";
	J = "";
	dfs(str1,str2,0);
	Pss ans;
	ans.fr = C;
	ans.sc = J;
	return ans;
}
int main(){
	int Q;
	scanf("%d",&Q);
	rep(q,Q){
		string str1,str2;
		cin >> str1 >> str2;
		Pss ans = solve(str1,str2);
		printf("Case #%d: %s %s\n",q+1,ans.fr.c_str(),ans.sc.c_str());
	}
	return 0;
}
