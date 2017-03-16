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

const int MAXN = 1e3 + 5;

char f[MAXN][30], s[MAXN][30];
map<string, char> mf, ms;
bool used[MAXN];
map<string, char> act1, act2;

void solve(){
    int n;
    scanf("%d", &n);
    ms.clear();
    mf.clear();
    act1.clear(); act2.clear();
    int rest = n;
    for(int i = 0; i < n; i++){
        scanf("%s%s", f[i], s[i]);
        mf[f[i]]++;
        ms[s[i]]++;
        used[i] = 0;
    }
    int ans = 0;
    while(rest){
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            if(mf[f[i]] == 1 || ms[s[i]] == 1){
                q.push(i);
                used[i] = 1;
                rest--;
            }
        }
        if(rest && q.empty()){
            int mn = 1e9;
            int mnid = 0;
             for(int i = 0; i < n; i++){
                if(used[i]) continue;
                if(max(mf[f[i]], ms[s[i]]) < mn){
                    mn = max(mf[f[i]], ms[s[i]]);
                    mnid = i;
                }
            }
            q.push(mnid);
            used[mnid] = 1;
            rest--;
        }
        while(!q.empty()){
            int v = q.front(); q.pop();
            act1[f[v]] = 1;
            act2[s[v]] = 1;
            mf[f[v]]--;
            ms[s[v]]--;
            for(int i = 0; i < n; i++){
                if(act1.find(f[i]) != act1.end() &&
                   act2.find(s[i]) != act2.end() && !used[i]){
                        used[i] = 1;
                        q.push(i);
                        ans++;
                        rest--;
                   }
            }
        }
        break;
    }
    printf("%d", ans);
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
	cin >> t;
	int cs = 1;
	while(t--){
        printf("Case #%d: ", cs++);
		solve();
        printf("\n");
	}
	return 0;
}
