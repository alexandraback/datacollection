#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<int,int> tb[6][6][6];
int c[8][2];

int main(){
    int TT,tt,n,m,r,i,j,k,h,d,z,md,x;
    char ans[4];
    scanf("%*d");
    scanf("%d %d %d %d",&TT,&n,&m,&r);
    puts("Case #1:");
    for( i=2; i<=m; i++ ){
        for( j=2; j<=m; j++ ){
            for( k=2; k<=m; k++ ){
                for( h=0; h<8; h++ ){
                    d=1;
                    if(h&1) d*=i;
                    if(h&2) d*=j;
                    if(h&4) d*=k;
                    tb[i][j][k][d]++;
                }
            }
        }
    }
    for( tt=0; tt<TT; tt++ ){
        map<int,int> tc;
        for( i=0; i<r; i++ ){
            scanf("%d",&x);
            tc[x]++;
        }
        z=0;
        for( map<int,int>::iterator it=tc.begin(); it!=tc.end(); ++it ){
            c[z][0]=it->first;
            c[z][1]=it->second;
            z++;
        }
        md=100000;
        sprintf(ans,"222");
        for( i=2; i<=m; i++ ){
            for( j=2; j<=m; j++ ){
                for( k=2; k<=m; k++ ){
                    for( h=0; h<z; h++ ){
                        if(tb[i][j][k][c[h][0]]==0) break;
                    }
                    if(h==z){
                        d=0;
                        for( h=0; h<z; h++ ){
                            int dd=(tb[i][j][k][c[h][0]]-c[h][1]);
                            d+=dd*dd;
                        }
                        if(d<md){
                            md=d;
                            sprintf(ans,"%d%d%d",i,j,k);
                        }
                    }
                }
            }
        }
        puts(ans);
    }
    return 0;
}
