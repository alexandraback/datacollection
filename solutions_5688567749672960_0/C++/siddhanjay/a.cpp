#include <bits/stdc++.h>
#define forall(i,a,b)               for(int i=a;i<=b;i++)
#define pb                          push_back
#define mp			  			    make_pair
#define MOD                         1000000007
#define maxn 10000
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map <string, int> msi;

int dp[1000010];
 
void foo() {
	memset(dp, 0x3f, sizeof dp);
	dp[1] = 1;
	forall(i,1, 1000000) {
		string tmp = to_string(i);
		reverse(tmp.begin(), tmp.end());
		int reverse = stoi(tmp);
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		dp[reverse] = min(dp[reverse], dp[i] + 1);
	}
}

int main()
{
	foo();
	 #ifndef ONLINE_JUDGE
     	freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
     #endif
     //ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	forall(kase,1,t)
	{
		int n;
		cin>>n;
		printf("Case #%d: %d\n", kase, dp[n]);
			
		
	}
	return 0;
}

