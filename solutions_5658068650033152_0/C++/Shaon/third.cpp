#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int shaon( int x ){
    if ( x==0 )return 0;
    return (x&1) + shaon( x>>1 );
}

#define SIZE 22

int n,m,tot;

bool place[SIZE][SIZE];

int parent [SIZE];

int parentOf ( int x ){
    if ( x == parent [x] ) return parent [x];
    return parent [x] = parentOf (parent [x]);
}

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int main(){

    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int k;
        scanf("%d %d %d",&n,&m,&k);
        tot = n*m;

        int ans = tot;

        for (int state= 0;state<(1<<tot);++state){
            int cnt = 1;
            for (int i=0;i<n;++i){
                for (int j=0;j<m;++j){
                    place[i][j] =false;
                    parent[i*m+j+1] = i*m+j+1;
                }
            }

            cnt = 0;
            for (int i=0;i<n;++i){
                for (int j=0;j<m;++j){
                    if ( check( state,cnt ) ){
                        place[i][j]=true;
                        //cout<<i<<" "<<j<<endl;
                    }
                    cnt++;
                }
            }

            //cout<<state<<endl;;
            cnt = 0;
            int rr,cc;
            int p,q;
            for (int i=0;i<n;++i){
                for (int j=0;j<m;++j){
                    if ( place[i][j] )continue;
                    for (int k=0;k<4;++k){
                        rr=i+dr[k];
                        cc=j+dc[k];
                        if ( rr>=0 && rr<n && cc>=0 && cc<m && !place[rr][cc] ){
                            p = parentOf (i*m+j+1);
                            q = parentOf ( rr*m+cc+1 );
                            parent [p] = q;
                        }
                    }
                }
            }

            int mother = 30;
            parent[mother] = 30;
            for (int i=0;i<n;++i){

                for (int j=0;j<m;++j){
                    if ( i==0 || i==n-1 || j==0 || j== m-1 ){

                        if ( !place[i][j] ){
                            p = parentOf( i*m+j+1 );
                            q= parentOf( mother );

                            parent[p]=q;
                            //cout<<"ss "<<i<<" "<<j<<endl;
                        }

                    }
                }

            }
            cnt = 0;
            for (int i=0;i<n;++i){
                for (int j=0;j<m;++j){
                    if ( ( parentOf( i*m+j+1 ) != parentOf(mother) ) || place[i][j] ){
                        cnt++;
                    }
                }
            }

            //cout<<"shaon "<<cnt<<endl;

            if ( cnt>=k ){
                //cout<<"ok\n";
                ans = min( ans , shaon( state ) );
            }

        }

        printf("Case #%d: %d\n",kk,ans);
    }


    return 0;
}
