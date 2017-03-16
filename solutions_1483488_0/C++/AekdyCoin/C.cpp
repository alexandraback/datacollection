#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;

const int maxn = 1 << 23 ;
#define pb push_back
#define mp make_pair

struct HashNode{
      int a, b;
      int nxt ; 
}H[ maxn + maxn ];
int sz;
int flg[ maxn ], fid = 0;

void read(string s){
    string s0, s1;
    s0 =  "D:\\GCJ\\" + s + ".in";
    s1 =  "D:\\GCJ\\" + s + ".out";
    freopen(s0.c_str(),"r",stdin);
    freopen(s1.c_str(),"w",stdout); 
}

void init(){
     sz = maxn;
     ++ fid;
}

bool insert( int a, int b ){
    int key = abs(a*b)&(maxn-1);
    if(flg[key]!= fid){
         flg[key]=fid;
         H[key].nxt = - 1;
         H[key].a = a; H[key].b = b;
         return true;         
    } 
    while(key != - 1) {
         if(H[key].a == a && H[key].b == b) return false;
         if( H[key].nxt == -1) break;
         key = H[key].nxt;     
    }
    H[key].nxt=++sz;
    H[sz].nxt=-1;
    H[sz].a=a;H[sz].b=b;
    return true;
}
int A, B;
int ten[ 9];

int gao(int v) {
    int ans=0,s=v,ct=0,m = v;
    while(s) s/=10, ++ ct;
    --ct;
    for(int i=0;i<ct;++i){
         int lb = m % 10;
         m = m / 10 + lb * ten[ ct ];
         if( lb ){
             if( m > v && m <= B) {
                 ans += insert( v, m );
             }
         }   
    }
    return ans;
}

int main(){
    //read("C-small-attempt0");
    ten[0]=1;
    for(int i=1;i<9;++i)ten[i]=ten[i-1]*10;
    int T, cas = 0;
    cin >> T;
    while(T--) {
        cin >> A >> B;
        init();      
        printf("Case #%d: ", ++ cas);
        LL ans = 0;
        for(int i = A; i <= B; ++ i) ans += gao(i);
        cout << ans << endl;
    }
    return 0;
}
