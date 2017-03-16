#include <iostream>
#include <cstring>
#include <stdio.h>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair

#define ll long long
ll f[40][2][2][2][2][2];
ll A, B, C;
ll dfs(int i, int x, int y, int f1, int f2, int flag ){
//    cout<<i<<" "<<x<<" "<<y<<" "<<f1<<" "<<f2<<" "<<flag<<" = "<<f[i][x][y][f1][f2][flag]<<endl;
    if( f[i][x][y][f1][f2][flag] ==-1 ){
//     if( i == 0 && x == 0 && y == 0 && f1 == 0 && f2 == 0 && flag == 0 )
//        cout<<"yes"<<endl;

        int ai = (A & (1LL <<i)) ? 1: 0;
        int bi = (B & (1LL << i )) ? 1: 0;
        int ci = (C & (1LL <<i )) ? 1: 0;
//        if( i == 0 && x == 0 && y == 0 && f1 == 0 && f2 == 0 && flag == 0 )
//        cout<<ai<<"+"<<bi<<"+"<<ci<<endl;
        if( f1 == 0 && x > ai ) return 0;
        if( f2 == 0 && y > bi ) return 0;
        if( flag == 0 && ( (x & y) > ci ) ) return 0;


        int new_f1 = f1 |(x < ai);
        int new_f2 = f2 |(y < bi);
        int new_flag = flag;
        new_flag |= (x & y) < ci ? 1: 0;
        ll res = 0;
        if( i == 0 ){
            if( i == 0 && new_f1 == 1 && new_f2 == 1 && new_flag == 1 ){
//                cout<<i<<" "<<x<<" "<<y<<" "<<f1<<" "<<f2<<" "<<flag<<" = "<<f[i][x][y][f1][f2][flag]<<endl;
               return 1;
            }
            return 0;
        }
        for(int x1 = 0; x1 <= 1; ++x1)
        for(int y1 = 0; y1 <= 1; ++y1){
            res += dfs(i - 1, x1, y1, new_f1, new_f2, new_flag);
        }
        f[i][x][y][f1][f2][flag] = res;
    }
//     cout<<i<<" "<<x<<" "<<y<<" "<<f1<<" "<<f2<<" "<<flag<<" = "<<f[i][x][y][f1][f2][flag]<<endl;
    return f[i][x][y][f1][f2][flag];
}
ll solve(){
    memset(f, -1, sizeof(f));
    return dfs(32, 0, 0, 0, 0, 0);
}


int main(){
//    freopen("in.txt", "r", stdin );
//    freopen("B0.in", "r", stdin );
//    freopen("B0.out", "w", stdout);
    freopen("B1.in", "r", stdin );
    freopen("B1.out", "w", stdout );
    int tcase;
    int tno = 0;
    cin>>tcase;
    while( tcase-- ){
        cin>>A>>B>>C;
        ll res = solve();
//        cout<<res<<endl;
        printf("Case #%d: %I64d\n", ++tno, res);
//        break;
    }
    return 0;
}
