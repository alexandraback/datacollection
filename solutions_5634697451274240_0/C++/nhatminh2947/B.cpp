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

string s;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("i.inp","r",stdin);
    freopen("o.out","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    for(int t = 1 ; t <= tcs ; t++){
        read(s);
        
        int step = 0;
        
        while(1){
            
//            cout << s << endl;
            
            bool allNeg = true;
            bool allPos = true;
            for(int i = 0 ; i < s.length() ; i++){
                allNeg &= (s[i] == '-');
                allPos &= (s[i] == '+');
            }
            
            if(allNeg) {
                printf("Case #%d: %d\n", t, step+1);
                break;
            }
            else if(allPos) {
                printf("Case #%d: %d\n", t, step);
                break;            
            }
        
            char c = s[0];
            
            if(c == '-') {
                for(int i = s.length() - 2 ; i >= 0 ; i--) {
                    if(s[i] == '-' && s[i+1] == '+')  {
//                        cout << "i = " << i << endl;
                        for(int k = 0 ; k <= i/2 ; k++) {
                            swap(s[k],s[i-k]);
                        }
                        
                        for(int k = 0 ; k <= i ; k++) {
                            if(s[k] == '-') s[k] = '+';
                            else s[k] = '-';
                        }
                        break;
                    }
                }
            }
            else {
                for(int i = s.length() - 2 ; i >= 0 ; i--) {
                    if(s[i] == '+' && s[i+1] == '-')  {
//                        cout << "i = " << i << endl;
                        for(int k = 0 ; k <= i/2 ; k++) {
                            swap(s[k],s[i-k]);
                        }
                        
                        for(int k = 0 ; k <= i ; k++) {
                            if(s[k] == '-') s[k] = '+';
                            else s[k] = '-';
                        }
                        break;
                    }
                }
            }
            
            step++;
        }        
    }
       
    return 0;
}

//Look at my code it's amazing !!!
