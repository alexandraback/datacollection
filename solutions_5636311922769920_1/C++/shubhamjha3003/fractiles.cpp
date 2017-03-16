#include<cstdio>
#include<algorithm>
using namespace std;
long long pwr_arr[200];
long long get_pos(int curr,int iter,int maxLevel,int n){
    if(curr==maxLevel){
        return iter;
    }
    return pwr_arr[maxLevel-curr]*(iter-1)+get_pos(curr+1,min(iter+1,n),maxLevel,n);
}
int main()
{
    int i,t,k,c,s,j,grp;
    long long pwr;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d",&k,&c,&s);
        grp=k/c;
        if(k%c!=0)
            grp++;
        if(grp>s)
            printf("Case #%d: IMPOSSIBLE\n",i);
        else{
            c=min(k,c);
            pwr=k;
            pwr_arr[0]=1;
            for(j=1;j<=c;j++){
                pwr_arr[j]=pwr_arr[j-1]*pwr;
            }
            printf("Case #%d: ",i);
            j=1;
            while(j<=grp){
                printf("%lld ",get_pos(1,c*(j-1)+1,c,k));
                j++;
            }
            printf("\n");
        }
    }
    return 0;
}
