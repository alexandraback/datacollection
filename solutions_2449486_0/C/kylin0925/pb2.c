#include <stdio.h>
int land[110][110]={0};
int land2[110][110]={0};
void check_v(int land[][110],int n,int m){
    int i,j;
    int max=-1;
    for(i=0;i<m;i++){
        max = -1;
        for(j=0;j<n;j++){
            if(land[j][i]>max)  
                max = land[j][i];
        }
        //printf("v max %d\n",max);
        for(j=0;j<n;j++){
            land2[j][i] = max;
        }
    }
}
void check_h(int land[][110],int n,int m){
    int i,j;
    int max = -1;
    for(i=0;i<n;i++){
        max =-1;
        for(j=0;j<m;j++){
          //  printf("h  %d\n",land[i][j]);
            if(land[i][j]>max)  
                max = land[i][j];
        }
        //printf("h max %d\n",max);
        for(j=0;j<m;j++){
            if(land2[i][j]>max)  
                land2[i][j]=max;
        }


    }
}
void dump(int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d ",land2[i][j]);
        printf("\n");
    }
        printf("\n");

}
int check(int land[][110],int n,int m){
    int i,j;
    check_v(land,n,m);
    //dump(n,m);
    check_h(land,n,m);
    //dump(n,m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(land[i][j] !=land2[i][j])
                return 0;
        }
    }
    return 1;
}
int main(int argc,char **argv){
    int t,n,m;
    int idx=1;
    int i,j;
    scanf("%d",&t);
    for(idx=1;idx<=t;idx++){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++){
                scanf("%d",&land[i][j]);
            }
        }
        if(n==1 || m ==1){
            printf("Case #%d: YES\n",idx); 
        }
        else if(check(land,n,m)){
            printf("Case #%d: YES\n",idx); 
        }else{
            printf("Case #%d: NO\n",idx); 
        }
    }
    return 0;
}
