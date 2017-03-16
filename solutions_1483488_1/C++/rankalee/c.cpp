#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
const int inf=(int)1e9;
const double INF=1e12,EPS=1e-9;

bool use[2000001];
int st[20], sz;

int main()
{
	int CS; cin>>CS;
	rep(cs,CS)
	{
		cerr << "Case: " << cs+1 <<endl;
		int a, b, ans = 0;
		cin >> a >> b;
		for(int i = a; i <= b; i++){
			char s[20];
			sprintf(s, "%d", i);
			int len = strlen(s);
			
			sz = 0;
			for(int j = 0; s[j]; j++){
				int x = 0;
				rep(k, len-j) x *= 10, x += s[j+k] - '0';
				rep(k, j) x *= 10, x += s[k] - '0';
				if(x > i && x <= b && !use[x]){
					ans++;
					use[st[sz++] = x] = 1;
				}
			}
			rep(i,sz) use[st[i]] = 0;
		}
		cout<<"Case #"<<cs+1<<": "<<ans<<endl;
	}
	
	return 0;
}
