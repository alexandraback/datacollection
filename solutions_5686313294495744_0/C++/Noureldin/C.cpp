#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define vi vector<int>
#define ll long long
#define pi pair<int,int>
#define point pair<double,double>
#define pl pair<ll,ll>
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

string I[20][2];
int N;

int solve(){
	int ans = 0;
	loop(mask,1 << N){
		set<string> F,S;
		loop(i,N){
			if(mask & (1 << i)){
				F.insert(I[i][0]);
				S.insert(I[i][1]);
			}
		}
		bool c = 1;
		loop(i,N){
			if(!(mask & (1 << i))){
				c &= F.find(I[i][0]) != F.end();
				c &= S.find(I[i][1]) != S.end();			
			}
			
		}	
		if(c) ans = max(ans,N - popcnt(mask));
	}
	return ans;
}

int main(){
	pre();
	int T;
	cin >> T;
	loop(t,T){
		cin >> N;
		loop(i,N) loop(j,2) cin >> I[i][j];
		printf("Case #%d: %d\n",t + 1,solve());	
	}
	return 0;
}
