#include <bits/stdc++.h>
#define maxx 100005
#define inf 2000000000
#define mod 1000000007
#define pii pair<int,int>
#define piii pair<pii,pii>
#define pli pair<long long,int>
#define f first
#define s second
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%lld",&x)
#define inch(x) scanf("%s",x)
#define indo(x) scanf("%lf",&x)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int t, N, k, n;
int divs[] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
char S[50];
vector<int>v[20];

void build_string(int x, int pos){
    int idx = pos;
    while(x){
        S[idx] = '0' + (x%2);
        x /= 2;
        idx += 2;
    }
    while(idx < N - 1){
        S[idx] = '0';
        idx += 2;
    }
}
int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("c_large_output.txt", "w", stdout);
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        cin >> N >> k;
        cout << "Case #" << cases << ":" << endl;
        n = (N - 2)/2;
        for(int i = 1; i <= n; i++)
            v[i].clear();

        for(int i = 1; i < (1<<n); i++)
            v[__builtin_popcount(i)].pb(i);

        S[0] = '1'; S[N - 1] = '1'; S[N] = '\0';
        for(int i = 1; i <= n && k; i++)
            for(int j = 0; j < v[i].size() && k; j++)
                for(int l = 0; l < v[i].size() && k; l++){
                    build_string(v[i][j], 1);
                    build_string(v[i][l], 2);
                    cout << S;
                    for(int o = 0; o < 9; o++)
                        cout << " " << divs[o];
                    cout << endl;
                    k--;
                }
    }
    return 0;
}
