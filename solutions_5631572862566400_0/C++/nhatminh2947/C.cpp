//******************************************************************
// Author: Huynh Nhat Minh
// Name of Problem: 
// Verdict: 
//******************************************************************
#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = { 0,-1, 1, 0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define mod 1000000007

int b[15];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("i.inp","r",stdin);
    freopen("o.out","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs) {
        read(n);
//        DEBUG(n);
        fr(i,1,n) {
            read(b[i]);
        }
        
        int len = -1;
        for(int stt = 1 ; stt < (1<<n) ; stt++) {
            vi ans;
            for(int i = 0 ; i < n ; i++) {
                if(((1<<i) & stt) != 0) {
                    ans.pb(i+1);
                }
            }
            do {
            
                bool ok = true;
                int cl = sz(ans);
                for(int i = 0 ; i < sz(ans) ; i++) {
                    if(i == 0){
                        if(b[ans[0]] == ans[cl-1] || b[ans[0]] == ans[1]){
                        }
                        else {
                            ok = false;
                            break;
                        }
                    }
                    else if(i == (sz(ans)-1)){
                        if(b[ans[sz(ans)-1]] == ans[sz(ans)-2] || b[ans[sz(ans)-1]] == ans[0]) {
                        }
                        else {
                            ok = false;
                            break;
                        }
                    }
                    else if(b[ans[i]] == ans[i+1] || b[ans[i]] == ans[i-1]) {
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
                
                if(ok) {
//                    cout << "=======================OK======================" << endl;
//                    rep(i,sz(ans)) {
//                        cout << ans[i] << " ";
//                    }
//                    cout << endl;
//                    DEBUG(sz(ans));
//                    DEBUG(ans[sz(ans)-1]);
//                            DEBUG(ans[0]);
//                            DEBUG(ans[sz(ans)-2]);
//                            DEBUG(b[ans[sz(ans)-1]]);
//                    for(int i = 0 ; i < sz(ans) ; i++) {
//                        if(i == 0){
//                            if(b[ans[0]] == ans[cl-1] || b[ans[0]] == ans[1]){
//                                DEBUG(ans[0]);
//                                DEBUG(ans[1]);
//                                DEBUG(ans[cl-1]);
//                                DEBUG(b[ans[0]]);
//                            }
//                            else {
//                                ok = false;
//                                break;
//                            }
//                        }
//                        else if(i == (sz(ans)-1)){
//                            if(b[ans[sz(ans)-1]] == ans[sz(ans)-2] || b[ans[sz(ans)-1]] == ans[0]) {
//                                DEBUG(ans[sz(ans)-1]);
//                                DEBUG(ans[0]);
//                                DEBUG(ans[sz(ans)-2]);
//                                DEBUG(b[ans[sz(ans)-1]]);
//                            }
//                            else {
//                                ok = false;
//                                break;
//                            }
//                        }
//                        else if(b[ans[i]] == ans[i+1] || b[ans[i]] == ans[i-1]) {
//                            DEBUG(ans[i]);
//                            DEBUG(ans[i-1]);
//                            DEBUG(ans[i+1]);
//                            DEBUG(b[ans[i]]);
//                        }
//                        else {
//                            ok = false;
//                            break;
//                        }
//                    }
                    
                    len = max(len, sz(ans));
//                    DEBUG(len);
                    break;
                }
            } while(next_permutation(all(ans)));
        }
        
        printf("Case #%d: %d\n", t, len);
    }
    
    return 0;
}

//Look at my code it's amazing !!!

