#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2000001], n, num[20], t, target;
bool use[20];

void back(int index, int sum){
    if(index==n){
        ++dp[sum];
    }
    else{
        back(index+1,sum+num[index]);
        back(index+1,sum);
    }
}

void print(int index, int sum){
    
    if( t==2 )  return;
    
    if(index==n){
        if( sum==target ){
            for(int i=0,j=0; i<n; ++i)
            if( use[i] ){
                if( !j ){
                    ++j;
                    printf("%d", num[i]);
                }
                else    printf(" %d", num[i]);
            }
            putchar('\n');
            ++t;
        }
    }
    else{
        use[index] = true;
        print(index+1,sum+num[index]);
        use[index] = false;
        print(index+1,sum);
    }
}

int main(void){
    
    freopen("CS.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0;
    
    scanf("%d", &cas);
    while(cas--){
        
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%d", &num[i]);
        
        memset(dp,0,sizeof(dp));
        back(0,0);
        for(target=1; target<2000001; ++target)
        if( dp[target]>1 )   break;
        //printf("%d\n", target);
        
        printf("Case #%d:", ++c);
        if( target<2000001 ){
            putchar('\n');
            t = 0;
            memset(use,0,sizeof(use));
            print(0,0);
        }
        else puts("Impossible");
    }
    
    return 0;
}
