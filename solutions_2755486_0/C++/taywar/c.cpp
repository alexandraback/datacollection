#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 222;
const int M = 676065;;
int a[N*10];
typedef pair<int,int> PII;
vector< pair<PII,int> >b[M];

bool cmp( pair<PII,int> x, pair<PII,int> y) {
     return x.second < y.second;
}

int main() {
    int T;
    cin>>T;
    for( int tc = 1; tc <= T; ++tc ) {
         int n, s, t, d, e, p, m, init, power;
         for( int i = 0 ; i < M; ++i ) b[i].clear();
         cin>>n;
         for( int i = 0 ; i < n; ++i ) {
              cin>>init>>m>>s>>t>>power>>d>>p>>e;
              s += N;
              t += N;
              for( int j = 0 ; j < m; ++j ) {
                   b[init].push_back( make_pair( PII(s*2,t*2),power) );
                   init += d;
                   s += p;
                   t += p;
                   power += e;
              }
         }
         int ans = 0;
         memset( a, 0, sizeof(a));
         for( int i = 0 ; i < M; ++i ) {
              sort( b[i].begin(), b[i].end(), cmp );
              for( int j = 0; j < b[i].size(); ++j ) {
                   int flag = 0;
                   //cout<<i<<" "<<j<<" "<<b[i][j].second<<endl;
                   for( int k = b[i][j].first.first; k <= b[i][j].first.second; ++k ) {
                        if( a[k] < b[i][j].second ) {
                            flag = 1;
                            a[k] = b[i][j].second;
                        }
                   }
                   ans += flag;
              }
         }
         cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
    return 0;
}
/*
6
3414 2 -25 61 326 54788 -7 61
181452 8 -10 3 6717 12710 2 -498
223505 8 -62 77 280 13242 5 595
101271 3 -16 37 8692 213187 -4 -883
265384 8 -81 89 3249 13934 -5 -37
197549 4 -3 78 2761 22851 -10 560
*/
