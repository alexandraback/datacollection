#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 100;

char ans[MAXN][MAXN];

void solve(){
    ll b, m;
    cin >> b >> m;
    ll sum = 1;
    for(int i = 0; i < b - 2; i++){
        sum *= 2;
    }
    if(sum < m){
        printf("IMPOSSIBLE\n"); return;
    }
    printf("POSSIBLE\n");
    for(int i = 0; i < b; i++){
        for(int j = 0; j < b; j++){
            ans[i][j] = '0';
        }
        ans[i][b] = '\0';
    }
    for(int i = 0; i < b - 1; i++){
        for(int j = 0; j < i; j++){
            ans[j][i] = '1';
        }
    }
    ans[0][b - 1] = '1';
    int v = 1;
    m--;
    while(m){
        ll cur = m % 2;
        if(cur){
            ans[v][b - 1] = '1';
        }
        v++;
        m /= 2;
    }
    for(int i = 0; i < b; i++){
        printf("%s\n", ans[i]);
    }
}

int main()
{
	#ifdef NASTYA
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
	int t = 1;
	int cs = 1;
	cin >> t;
	while(t--){
        printf("Case #%d: ", cs++);
		solve();
	}
	return 0;
}
