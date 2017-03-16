
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <list>

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef unsigned long long ull;
inline ll toInt(string s) { ll v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
template<class T> inline T sqr(T x) { return x*x; }


#define For(i,a,b)	for(int (i) = (a);i < (b);(i)++)
#define rep(i,n)	For(i,0,n)
#define clr(a)		memset((a), 0 ,sizeof(a))
#define mclr(a)		memset((a), -1 ,sizeof(a))
#define all(a)		(a).begin(),(a).end()
#define rall(a)		(a).rbegin(), (a).rend()
#define sz(a)		(sizeof(a))
#define Fill(a,v)	fill((int*)a,(int*)(a+(sz(a)/sz(*(a)))),v)

bool cheak(int x, int y, int xMax, int yMax){ return x >= 0 && y >= 0 && xMax > x && yMax > y; }
const int dx[3] = { -1, -1, 0 }, dy[3] = { -1, 0, -1};
const int mod = 1000000007;
const int INF = 1e9;

int main()
{
	int N;
	cin >> N;

	rep(Case, N){
		ll ans = 9;
		string n;
		cin >> n;

		if (n.size() == 1){
			ans = toInt(n);
		}else
		while (n.size()!=1){

			int l = n.size();
			bool ef = false;
			if (n[0] == '1'){
				For(i,1, n.size()){
					if (n[i] == '0'){
						if (i == n.size() - 1){
							ef = true;
							ans++;
						}
					}
					else{
						break;
					}
				}
			}
			if (!ef){

				if (n[l - 1] == '0'){
					n = toString(toInt(n) - 1); ans++;
				}

				bool f = false;
				for (int i = l - 1; i >= 0; i--){
					if (!i && n[0] == '1'){
						ans++; break;
					}
					if (i < l - i - 1){
						if (n[i] > '0')f = true;
					}

					ll t = min(i, l - i - 1);
					ans += (n[i] - '0') * pow(10LL, t);
				}
				if (f)ans++;
			}
			n.clear();
			rep(i, l - 1)n += "9";
		}
		
		cout << "Case #" << Case + 1 << ": " << ans << endl;
	}
	
	return 0;
}
