#include<bits/stdc++.h>
#include <unistd.h>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 1000006

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }
//to increase stack size : -Wl,--stack,1677721600

int r, c, w;

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	int ans = 0;
	for(casee=1;casee<=T;casee++){
		ans = 0;
		cin >> r >> c >> w;
		cout << "Case #" << casee << ": " ;

		for(int i = 0;i<r-1;i++){
			ans += (c/w);
		}
		
		if(c%w == 0) ans += ((c/w) + w-1);
		else ans += ((c/w) + w);
		cout << ans << endl;
		//if(c%w == 0) cout << (c/w) + w-1 << endl;
		//else cout << (c/w) + w << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
return 0;	
}

