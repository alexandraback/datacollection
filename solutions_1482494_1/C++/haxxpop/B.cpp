#include<stdio.h>
#include<algorithm>
using namespace std; 
typedef pair<int,int> order;
order lev[2000];
order tmp[2000];
int ch[2000];
int main(){
    int n;
    int t;
    scanf("%d",&t);
    for(int g = 0 ; g < t ; g++ ){
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++ ) ch[i] = 0;
        for(int i = 0 ; i < n ; i++ ) scanf("%d %d",&lev[i].second,&lev[i].first);
        sort(lev,lev+n);
        int rate = 0;
        int fail = 0;
        int ans = 0;
        for(int k = 0 ; k < n ; k++ ){
            if( lev[k].first <= rate ){ 
                if( ch[k] == 0 ) rate += 2 ; 
                if( ch[k] == 1 ) rate += 1 ;
                ch[k] = 1;
                ans++;
                continue; 
            }
            for( ; lev[k].first > rate ; ){
                for(int i = n-1 ; i >= 0 ; i-- ){
                    fail = 1;
                    if( ch[i] == 0 && lev[i].second <= rate ){
                        ch[i] = 1;
                        rate += 1;
                        ans++;
                        //printf("x %d %d %d\n",lev[i].second,rate,i);
                        fail = 0;
                        break;
                    }
                }
                if( fail ) break;
            }
            if( fail ) break;
            else{
                if( ch[k] == 0 ) rate += 2;
                if( ch[k] == 1 ) rate += 1;
                ch[k] = 1;
                ans++;
                continue;
            }
        }
        if( fail ) printf("Case #%d: Too Bad\n",g+1);
        else printf("Case #%d: %d\n",g+1,ans);
    }
    //for(;;);
}
