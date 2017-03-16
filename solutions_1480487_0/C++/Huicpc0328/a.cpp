#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 11111;
double a[N] ,b[N];
double r[N];

int main() {
    int test , i  , j , n;
    scanf("%d",&test);
    for( int tc = 1 ; tc <= test ;++tc )
    {
        scanf("%d",&n);
        double x = 0 ;
        for( i = 0 ; i < n;i++ ) {
            scanf("%lf",&a[i]);
            b[i] = a[i];
            x += a[i];
            r[i] = 0;
        }
        printf("Case #%d:",tc);

        sort( b , b+n );
        double p = 100, pre = 0;
        for( i = 0 ; i < n-1;i++ ) {
            double dis = (b[i+1]-b[i])*(i+1);
            double need = dis/x * 100;
            if( need > p ) {
                r[i] = pre + p/(i+1);
                pre = r[i++];
                p = 0;
                break;
            } else {
                p -= need;
                r[i] = pre + need/(i+1);
            }
            pre = r[i];
        }
        for( j = i ; j < n ;j++) r[j] =  pre + p/(j+1) , pre = r[j];

        //for(i = 0 ; i < n;i++ )
            //cout<<r[i]<<endl;

        for( i = 0 ; i < n;i++ ) {
            for( j = 0 ; j < n;j++ )
                if( a[i] == b[j] ) {
                    break;
                }
            if( j > 0 ) pre = r[j-1];
            else pre = 0;
            printf(" %lf",r[n-1] - pre);
        }
        puts("");
    }
    return 0;
}
