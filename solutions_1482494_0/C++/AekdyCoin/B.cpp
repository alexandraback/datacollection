#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 1111;
#define mp make_pair
#define pb push_back
#define OPEN(s) freopen(s,"r",stdin);
#define SAVE(s) freopen(s,"w",stdout);
bool flg[ maxn ][ 2] ;
int d[ maxn ][ 2 ];
int n;

int main() {
    OPEN("D:\\B-small-attempt2.in");
    SAVE("D:\\B-s.out");
    int T, cas = 0;
    cin >> T;
    while(T -- ){
         memset( flg, 0, sizeof flg);
         int now = 0, ct = 0;
         cin >> n;
         for(int i=0;i<n;++i) scanf("%d%d",&d[i][0],&d[i][1]);      
         while( true ) {
                //cout <<"now = " << now << endl;
                bool sc = 0, fd = 0;
                for(int i = 0; i < n; ++ i) if( ! flg[i][1]) {
                      fd=1;  
                      if(now >= d[i][1]) {
                           ++ ct;
                           now += flg[i][0]?1:2;  
                           flg[i][1]=1;
                           sc = 1;
                           break ;
                      }
                }
                if(!fd) break;
                if(!sc) {
                      int op=-1;  
                      for(int i = 0; i < n; ++ i) if(! flg[i][0] && now >= d[i][0] && !flg[i][1]) {
                            if(op<0 || d[i][1] > d[op][1]) op=i;  
                      }
                      if(op<0) break;
                      ++ now;
                      flg[op][0]=1;  
                      ++ ct;
                }
         }
         ++ cas;
         printf("Case #%d: ",cas);  
         bool ok = 1;
         for(int i=0;i<n;++i) if(!flg[i][1]) ok=0;
         if(!ok) puts("Too Bad"); 
         else printf("%d\n", ct);            
    }
    return 0;
}
