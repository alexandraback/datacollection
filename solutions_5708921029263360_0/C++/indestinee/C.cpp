#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int cas, a, b, c, k, ans, cnt, x[1011], y[1011], z[1011], xy[10][10], yz[10][10], zx[10][10];
vector<string> v, tmp;
string itos( int x ){
    string ret = "";
    while( x ){
        ret = (char)( x % 10 + '0' ) + ret;
        x /= 10;
    }
    return ret;
}
void dfs( int st , int ed , int pick ){
    if( pick + ed - st <= ans )
        return;
    if( st == ed ){
        if( ans < pick ){
            ans = pick;
            v = tmp;
        }
        return;
    }
    if( xy[x[st]][y[st]] < k && yz[y[st]][z[st]] < k && zx[z[st]][x[st]] < k ){
        xy[x[st]][y[st]] ++;
        yz[y[st]][z[st]] ++;
        zx[z[st]][x[st]] ++;
        tmp.push_back( itos( x[st] + 1 ) + " " + itos( y[st] + 1 ) + " " + itos( z[st] + 1 ) ); 
        dfs( st + 1 , ed , pick + 1 );
        xy[x[st]][y[st]] --;
        yz[y[st]][z[st]] --;
        zx[z[st]][x[st]] --;
        tmp.resize( tmp.size() - 1 );
    }
    dfs( st + 1 , ed , pick );
    
}
int main(){
    freopen( "C-small-attempt0.in" , "r" , stdin );
    freopen( "C.out" , "w" , stdout );
    scanf( "%d" , &cas );
    for( int T = 1 ; T <= cas ; T ++ ){
        scanf( "%d%d%d%d" , &a , &b , &c , &k );
        ans = cnt = 0;
        for( int i = 0 ; i < a ; i ++ )
            for( int j = 0 ; j < b ; j ++ )
                for( int k = 0 ; k < c ; k ++ ){
                    x[cnt] = i;
                    y[cnt] = j;
                    z[cnt] = k;
                    cnt ++;
                }
        dfs( 0 , cnt , 0 );
        printf( "Case #%d: %d\n" , T , ans );
        for( int i = 0 , sz = v.size() ; i < sz ; i ++ )
            cout << v[i] << endl;
        v.clear();
    }
}
