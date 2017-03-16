#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

const int N = 21;
int f[1<<N] , a[N];

struct node {
    int v , id;
    node(){};
    node( int vv,int i ): v(vv),id(i){}
};

node b[1<<N];

int cmp( node x,node y ) {
    return x.v < y.v;
}

inline int t( int x ) {
    return 1<<x;
}

void out(int id,int n ) {
    int f = 0;
    for( int i = 0 ; i < n;i++ ) {
        if( id&(t(i)) ) {
            if(f) putchar(' ');
            printf("%d",a[i]);
            f = 1;
        }
    }
    puts("");
}

int main() {
    int test , i , j, n;
    scanf("%d",&test);
    for( int tc = 1 ; tc <= test; tc++)
    {
        scanf("%d",&n);
        for( i = 0 ; i < n;i++ ) scanf("%d",&a[i]);
        memset( f , 0 , sizeof( f ));
        int tn = t(n);
        for( i = 0 ; i < tn; i++ ) {
            for( j = 0 ; j < n;j++ ) {
                if( (i&(t(j))) != 0 ) continue;
                f[ i+t(j) ] = f[i] + a[j];
            }
            b[i].id = i;
            b[i].v = f[i];
            //cout<<i<<" "<<f[i]<<endl;
        }

        sort( b , b+tn , cmp );
        //for( i = 0 ; i < tn;i++ )
            //printf("%d %d\n",b[i].v,b[i].id);

       //qsort(b,tn,sizeof(b[0]),cmp);
        for( i = 1 ; i < tn;i++ ) {
            //printf("%d %d\n",b[i].v,b[i].id);
            if( b[i].v == b[i-1].v ) {
                break;
            }
        }
        printf("Case #%d:\n",tc);
        if(i < tn ) {
            out( b[i].id,n );
            out( b[i-1].id,n );
        } else puts("Impossible");
    }
    return 0;
}
