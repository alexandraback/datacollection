#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int box[1010];
bool judge(int x,int r,int c){
    if( x == 1 ) return true;
    if( r < c ) swap( r , c);
    if( x == 2 ){
        if( r%2==0 || c%2==0 ) return true;
        else return false;
    }
    else if( x==3 ){
        if( r==3 || c==3 ){
            if( r==3 ) {
                if( c > 1 )  return true;
                else return false;
            }
            else return true;
        }
        else return false;
    }
    else {
        if( r < 4 ) return false;
        if( c < 3 ) return false;
        return true;
    }
}
int main(){
    freopen("./D-small-attempt0.in","r",stdin);
    freopen("./D-small-attempt0.out","w",stdout);
    int T,casenum=1;
    scanf("%d",&T);
    int   x,r,c;
    while(T--){
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d: %s\n",casenum++,judge(x,r,c)?"GABRIEL":"RICHARD");
    }
    return 0;
}
