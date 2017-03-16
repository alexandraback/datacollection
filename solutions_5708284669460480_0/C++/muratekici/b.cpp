#include <bits/stdc++.h>

using namespace std;

#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define orta (bas + son >> 1)
#define sag (k + k + 1)
#define sol (k + k)

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define endl '\n'

typedef pair < int ,int > pii;

typedef long long ll;

const int inf = 1e9, mod = 1e9+7;
const int N = 1e5+5;

int k, all, n, m, x, y, mx, t, sum;

string str, str2 , s;

void calc(int x, string ss) {
	if(x > k) {
		all++; int t = 0;
		FOR(i,0,k-m) if(ss.substr(i,m) == str2) t++;
		mx = max(mx, t);
		sum += t;
		return ;
	}
	FOR(i,1,n) calc(x+1,ss+str[i-1]);
}

int main(){
	
	scanf("%d",&t);

	FOR(i,1,t) {
		scanf("%d %d %d",&n,&m,&k);
		cin >> str >> str2;
		all = sum = mx = 0; calc(1,"");
		cout << "Case #" << i << ": " << setprecision(12) << fixed << mx - (1.0 * sum / all) << endl;
	}
	
    return 0;
}
