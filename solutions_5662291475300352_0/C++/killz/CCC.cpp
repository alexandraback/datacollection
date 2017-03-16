#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;
int v[101][101];

int main(){
freopen("C:\\Users\\Jui\\Downloads\\C-small-1-attempt0.in", "r", stdin);
freopen("CCC.txt", "w", stdout);

int a, b, c, d;
int TT, RR;
int G;
double eps = 1e-15;
pair<double, double> s, f;
cin >> TT;
REPI(RR, TT){
	cin >> G;
    if(G == 1){
        cin >> c >> i >> d;
        f = {c, d};
        s = {c, d+1};
    }
    else {
        cin >> c >> i >> d;
		f = {c, d};
        cin >> c >> i >> d;
		s = {c, d};
		if(f.se > s.se) swap(f, s);
    }
    double tf = f.se + (360.0-f.fi)*f.se/360.0;
    double ts = (360.0-s.fi)*s.se/360.0;
    if(abs(ts-tf) <= eps or tf < ts){
        c = 1;
    }
    else c = 0;
    printf("Case #%d: %d\n", RR, c);
}



return 0;
}
