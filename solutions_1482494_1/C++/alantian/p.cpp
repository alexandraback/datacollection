#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int a[MAXN][2];
int p[MAXN];
int n;
int earn;

bool end(){
    for( int i = 0; i < n; i++ ) if ( p[i] < 2 ) return false;
    return true;
}

bool pick2(){
    for( int i = 0; i < n; i++ ) if ( p[i] == 0 && a[i][1] <= earn ){
        p[i] = 2;
        earn += 2;
        return true;
    }
    for( int i = 0; i < n; i++ ) if ( p[i] == 1 && a[i][1] <= earn ){
        p[i] = 2;
        earn += 1;
        return true;
    }
    return false;
}

bool pick1(){
    int best = -1;
    for( int i = 0; i < n; i++ ){
        if ( (p[i] == 0 && a[i][0] <= earn) ){
            if ( best == -1 || a[i][1] > a[best][1] )
                best = i;
        }
    }
    if ( best >= 0 ){
        p[best]++;
        earn++;
        return true;
    }else
        return false;
}

int solve(){
    int res = 0;
    earn = 0;
    while ( ! end() ){
        if ( pick2() )
            ;
        else if ( pick1() )
            ;
        else
            return -1;
        res++;
    }
    return res;
}

int main(){
    int T; scanf("%d",&T);
    for( int Case = 1; Case <= T; Case++ ){
        scanf("%d",&n);
        for( int i = 0; i < n; i++ )
            scanf("%d%d",&a[i][0],&a[i][1]);

        for( int i = 0; i < n; i++ )
            p[i] = 0;
        
        int res = solve();
        printf("Case #%d: ",Case);
        if ( res < 0 )
            printf("Too Bad\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
