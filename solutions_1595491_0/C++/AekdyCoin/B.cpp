#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;

const int maxn = 105 ;
#define pb push_back
#define mp make_pair

vector< vector<int> > d[ 35 ][ 2 ];

int s[ maxn ];
int N, S, P;
bool f[ maxn ][ maxn ][ maxn ];

void read(){
    freopen("D:\\GCJ\\B-small-attempt0.in","r",stdin);
    freopen("D:\\GCJ\\B-small-attempt0.out","w",stdout); 
}

bool cmp( vector< int > a, vector< int > b ) {
     return a[2] > b[2];
}

void pre(){
     for(int a = 0; a <= 10; ++ a) for(int b = a; b <= 10; ++ b)
       for(int c = b; c <= 10; ++ c) {
              if(c - b > 2 || c - a > 2 || b - a > 2) continue ;
              vector< int > v;
              v.pb(a); v.pb(b);v.pb(c);
              if(c-b == 2 || c - a == 2 || b - a == 2) {
                    d[ a + b + c ][1].pb( v ); 
              }else {
                    d[ a + b + c ][0].pb( v );
              } 
       }
       for(int i = 0; i < 31; ++ i) for(int j = 0; j  < 2; ++ j) if( d[ i ][ j ].size() )
         sort( d[i][j].begin(), d[i][j].end(), cmp);
}

void dp(){
    memset(f,0,sizeof f); 
    f[0][0][0] = 1;
    for(int i = 0; i < N; ++ i)
      for(int j = 0; j <= S && j <= i; ++ j)
        for(int k = 0; k <= N && k <= i; ++ k) if( f[ i ][ j ][ k ]){
                int v;
                // sur
                if( d[ s[i + 1] ][ 1 ].size()) {
                    v=d[s[i+1]][1][0][2];
                    //cout <<"v = " << v << endl;
                    f[i+1][j+1][k+(v >= P)] |= f[i][j][k];
                }
                // not sur
                if( d[ s[i + 1] ][ 0 ].size()) {
                    v=d[s[i+1]][0][0][2];
                    //cout <<"v = " << v << endl;
                    f[i+1][j][k+(v>=P)] |= f[i][j][k];
                    //cout <<"ok!!" << endl;
                }
        } 
    //cout <<"ok" << endl;    
    int i;
    for(i = N; i >= 0; -- i) if( f[ N ][ S ][ i ]) break ;
    cout << i << endl;
}

int main(){
    //read();
    pre();
    int T, cas = 0;
    cin >> T;
    while(cin >> N >> S >> P) {
        for(int i = 1; i <= N; ++ i) scanf("%d", s + i);   
        printf("Case #%d: ", ++ cas);
        dp();
    }
    return 0;
}
