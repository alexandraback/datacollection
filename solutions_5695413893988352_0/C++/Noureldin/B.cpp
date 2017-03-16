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

int T;
char A[5],B[5];
string best_A,best_B;
int val_A,val_B;
vi a,b;
int ans;
	
void solve(int i,int j){
	if(i == sz(a) && j == sz(b)){
		int x,y;
		sscanf(A,"%d",&x);
		sscanf(B,"%d",&y);
		if(abs(y - x) < ans){
			ans = abs(y - x);
			best_A = string(A);
			best_B = string(B);
			val_A = x;
			val_B = y;
		}	
		else if(abs(y - x) == ans && x <  val_A){
			x = val_A;
			y = val_B;
			best_A = string(A);
			best_B = string(B);
		}
		else if(abs(y - x) == ans && y <  val_B){
			x = val_A;
			y = val_B;
			best_A = string(A);
			best_B = string(B);
		}
		return;
	}
	if(i < sz(a)){
		loop(x,10) {
			A[a[i]] = x + '0';
			solve(i + 1,j);
		}
		return;
	}
	loop(x,10) {
		B[b[j]] = x + '0';
		solve(i,j + 1);
	}
}

int main(){	
	scanf("%d",&T);
	loop(t,T){
		scanf("%s %s",A,B);
		a.clear();
		b.clear();		
		int L = strlen(A);
		ans = INT_MAX;
		loop(i,L){
			if(A[i] == '?') a.pb(i);
			if(B[i] == '?') b.pb(i);
		}
		solve(0,0);
		printf("Case #%d: %s %s\n",t + 1,best_A.c_str(),best_B.c_str());
	}	
	return 0;
}
