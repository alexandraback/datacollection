#include<stdio.h>
#include<set>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;




int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("pb.out","w",stdout);

    int T,x,y,fx,fy;

    scanf(" %d",&T);
    for( int cas = 1; cas <= T; cas++ ){
        scanf(" %d %d",&x,&y);
        printf("Case #%d: ",cas);
        for( int i = 0; i < abs(x); i++ ){
            if( x > 0 ) printf("WE");
            else        printf("EW");
        }
        for( int i = 0; i < abs(y); i++ ){
            if( y > 0 ) printf("SN");
            else        printf("NS");
        }
        printf("\n");
    }

    return 0;
}
