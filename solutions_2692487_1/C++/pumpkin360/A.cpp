#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<deque>

#define inf 1000000000

using namespace std;

int main(){
int t, n, a, tab[100], res;
scanf("%d", &t);
for(int z=1; z<=t; z++){
    res=0;
    scanf("%d%d", &a, &n);
    for(int i=0; i<n; i++)
        scanf("%d", &tab[i]);
    sort(tab,tab+n);
    for(int i=0; i<=n; i++){
        if(i==n){
            n=0;
        }
        else if(a>tab[i])
            a+=tab[i];
        else{
            for(int j=0; j<n-i; j++)
                tab[j]=tab[j+i];
            n=n-i;
            break;
        }
    }
    //for(int k=0; k<n; k++)
    //    printf("%d ", tab[k]);
    //printf("\n");
    if(n==0){
        printf("Case #%d: 0\n", z);
        continue;
    }
    for(int i=1; i<=n&&!res; i++){
        int temp=a, n_prim=0, free=i;
        while(free){
            if(free>=(n-n_prim)){
    //            printf("enought\n");
                res=i;
            break;
            }
            else{
  //              printf("%d %d %d\n", a, tab[n_prim], free);
                while(free&&temp<=tab[n_prim]){
                    --free;
                    temp+=(temp-1);
                }
                while(n_prim<n&&temp>tab[n_prim]){
                    temp+=tab[n_prim];
                    ++n_prim;
                }
                if(n_prim==n){
                    res=i;
   //                 printf("dsa eat all\n");
                    break;
                }
            }
        }
    }
    printf("Case #%d: %d\n", z, res);
}
return 0;
}
