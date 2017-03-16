#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
string solve(){
	string s;
	cin >> s;
	string ans;
	for(int i=0;i<s.size();i++){
		if(sz(ans)==0)ans += s.substr(i,1);
		else{
			if(ans[0]>s[i])ans = ans+s.substr(i,1);
			else ans = s.substr(i,1)+ans;
		}
	}
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		printf("Case #%d: ",i+1);
		cout << solve() << endl;
	}
}
