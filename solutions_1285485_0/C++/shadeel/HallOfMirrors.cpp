#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int gcd(int a, int b){
    int x=(a>=b)?(a):(b);
    int y=(a>=b)?(b):(a);
    while( x%y ){
        int z = y;
        y = x%y;
        x = z;
    }
    return y;
}

int main(void){
    
    freopen("DSin.txt", "r", stdin);
    freopen("DSout.txt", "w", stdout);
    
    int cas, c=0, h, w, d;
    int pdh, ndh, pdw, ndw, ans, dis;
    char bo[35][35];
    bool up, down, left, right, use[201][201];
    
    scanf("%d", &cas);
    while( cas-- ){
        printf("Case #%d: ", ++c);
        scanf("%d %d %d", &h, &w, &d);
        for(int i=0; i<h; ++i)
            scanf("%s", bo[i]);
        for(int i=1; i<h; ++i)
        for(int j=1; j<w; ++j)
        if( bo[i][j] == 'X' ){
            pdh = i - 1;
            ndh = h - 3 - pdh;
            pdw = j - 1;
            ndw = w - 3 - pdw;
        }
        
        ans = 0;
        up=false; down=false; left=false; right=false;
        if( pdh*2+1 <= d ){
            up = true;
            ++ans;
        }
        if( ndh*2+1 <= d ){
            down = true;
            ++ans;
        }
        if( pdw*2+1 <= d ){
            left = true;
            ++ans;
        }
        if( ndw*2+1 <= d ){
            right = true;
            ++ans;
        }
        
        memset(use,0,sizeof(use));
        if( up & left ){
            for(int i=1; ; ++i){
                int x = (i+1)/2*2*pdw + i/2*2*ndw + i;
                if( x >= d )    break;
                for(int j=1; ; ++j){
                    int y = (j+1)/2*2*pdh + j/2*2*ndh + j;
                    if( x*x + y*y > d*d )   break;
                    int g = gcd(x,y);
                    if( use[100-x/g][100-y/g] ) continue;
                    else{
                        use[100-x/g][100-y/g] = true;
                        ++ans;
                    }
                }
            }
        }
        if( up & right ){
            for(int i=1; ; ++i){
                int x = (i+1)/2*2*ndw + i/2*2*pdw + i;
                if( x >= d )    break;
                for(int j=1; ; ++j){
                    int y = (j+1)/2*2*pdh + j/2*2*ndh + j;
                    if( x*x + y*y > d*d )   break;
                    int g = gcd(x,y);
                    if( use[100-x/g][100+y/g] ) continue;
                    else{
                        use[100-x/g][100+y/g] = true;
                        ++ans;
                    }
                }
            }
        }
        if( down & left ){
            for(int i=1; ; ++i){
                int x = (i+1)/2*2*pdw + i/2*2*ndw + i;
                if( x >= d )    break;
                for(int j=1; ; ++j){
                    int y = (j+1)/2*2*ndh + j/2*2*pdh + j;
                    if( x*x + y*y > d*d )   break;
                    int g = gcd(x,y);
                    if( use[100+x/g][100-y/g] ) continue;
                    else{
                        use[100+x/g][100-y/g] = true;
                        ++ans;
                    }
                }
            }
        }
        if( down & right ){
            for(int i=1; ; ++i){
                int x = (i+1)/2*2*ndw + i/2*2*pdw + i;
                if( x >= d )    break;
                for(int j=1; ; ++j){
                    int y = (j+1)/2*2*ndh + j/2*2*pdh + j;
                    if( x*x + y*y > d*d )   break;
                    int g = gcd(x,y);
                    if( use[100+x/g][100+y/g] ) continue;
                    else{
                        use[100+x/g][100+y/g] = true;
                        ++ans;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
