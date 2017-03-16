#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define sz(v) v.size()
#define eps 1e-10
#define fill(v,n,x) for(int i=0;i<(int)n;i++) v.push_back(x)
#define re return
#define sum(v) accumulate(v.begin(),v.end(),0)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define pi 3.1415926535897932384626433832795
#define print(v) for (auto& i:v) cout<<i<<endl
#define print "Case #"+to_string(t1)+": " 

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;

struct hik{
	int d,t;
};

int main() {
	freopen("c.txt", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	cin>>T;
	for(int t1=1; t1<=T; t1++) {
		int N;
		cin>>N;
		int res=0;
		vector<hik> V;
		for(int i=0; i<N; i++) {
			int di,hi,mi;
			cin>>di>>hi>>mi;
			for(int k=0; k<hi; k++) {
				hik t {di,mi+k};
				V.push_back(t);
			}
		}
		int nn=sz(V);
		if(nn==1) res=0;
		else {
			int t1=V[0].t, t2=V[1].t;
			if(t1==t2) {
				res=0;
			} else {
				int d1=V[0].d, d2=V[1].d;
				if(d1==d2) {
					if(t1>t2) swap(t1,t2);
					ld x=t1*360/(ld)(t2-t1);
					if(d2+x>360) res=0;
					else res=1;
				} else {
					if(d1>d2) {
						swap(d1,d2);
						swap(t1,t2);
					}
					ld d=d2-d1;
					if(t1<t2) {
						ld x=t1*d/(ld)(t2-t1);
						if(x+d2>=360) {
							res=0;
						} else{
							ld xx=t1*(d+360)/ld(t2-t1);
							if(xx+d2>360) res=0;
							else res=1;
						}
					} else {
						ld x=t2*(360-d)/(ld)(t1-t2);
						if(d1+x>360) res =0;
						else res=1;
					}
				}
			}
		}
		cout<<print<<res<<endl;
	}
	return 0;
}

