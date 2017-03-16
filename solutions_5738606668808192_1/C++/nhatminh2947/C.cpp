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

int n, j;
int d[20];

ll getNum(int base) {
    ll result = 0;
    ll p = 1;
    for(int i = n-1 ; i >= 0 ; i--) {
        result += p * d[i];
        p *= base;
    }
    
    return result;
}

int getDivisor(ll k) {
    if(k == 2) return -1;
    if(k % 2 == 0) return 2;
    for(int i = 3 ; i <= sqrt(k) ; i+=2){
        if(k % i == 0) return i;
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("i.inp","r",stdin);
    freopen("o.out","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    for(int t = 1 ; t <= tcs ; t++){
        read2(n,j);
        
        printf("Case #%d:\n", t);
        int st = (1 << (n-1)) + 1;
        int ed = (1 << n) - 1; 
        
//        printf("Start: %d End: %d\n",st, ed);
        
        if(st % 2 == 0) st++;
        
        for(int i = st ; i <= ed && j ; i += 2) {
            int tmp = i;
            int cnt = 0;
            while(tmp)  {
                d[cnt] = tmp % 2;
                tmp /= 2;
                cnt++;
            }
            
//            fr(i,0,n-1) printf("%d",d[i]);
//            printf("\n");
                      
            bool hasPrime = false;
            for(int k = 2 ; k <= 10 ; k++){
                hasPrime |= (getDivisor(getNum(k)) == -1);
            }
            
            if(!hasPrime && j) {
                for(int k = 0 ; k < n ; k++) {
                    printf("%d",d[k]);
                }
                for(int k = 0 ; k < n ; k++) {
                    printf("%d",d[k]);
                }
                
                for(int k = 2 ; k <= 10 ; k++){
                    printf(" %d", getDivisor(getNum(k)));
                }
                
//                for(int k = 2 ; k <= 10 ; k++){
//                    printf(" %d", getNum(k));
//                }
                printf("\n");
                j--;
            }
        }
    }
       
    return 0;
}

//Look at my code it's amazing !!!
