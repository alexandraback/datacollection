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

int a[105][55];
int cnt[2505];
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
        
        fr(i,1,2500) cnt[i] = 0;
        
        int m = n*2 - 1;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                int x;
                read(x);
                
                cnt[x]++;
            }
        }
        
        vi ans;
        
        fr(i,1,2500) {
            if(cnt[i] % 2 == 1) {
                ans.pb(i);
            }
        }
        
        sort(all(ans));
        
        printf("Case #%d: ",t);
        rep(i,sz(ans)) {
            printf("%d ", ans[i]);
        }
        
        printf("\n");
    }
    
    return 0;
}

//Look at my code it's amazing !!!

