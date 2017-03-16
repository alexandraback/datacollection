#include<stdio.h>
#include<stdlib.h>
struct nodee{
    int* inherit;
    int num;
};
int check(struct nodee* node,int n,int last){
    //printf("node%d last=%d\n",n,last);
    if(node[n].num==0&&n==last)return 1;
    int temp=0;

    for(int i=0;i<node[n].num;i++){
        if(check(node,node[n].inherit[i]-1,last))temp++;
    }
    //printf("n=%d last=%d temp=%d\n",n,last,temp);
    return temp;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        int n;
        scanf("%d",&n);
        struct nodee* node=(struct nodee*)malloc(sizeof(struct nodee)*n);
        for(int j=0;j<n;j++){
            int inherit;
            scanf("%d",&inherit);
            node[j].num=inherit;
            node[j].inherit=(int*)malloc(sizeof(int)*inherit);
            for(int i=0;i<inherit;i++)scanf("%d",&node[j].inherit[i]);
        }
        printf("Case #%d: ",k+1);
        int pass=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(check(node,i,j)>1){
                        printf("Yes\n");
                        pass=1;
                        break;
                    }
                }
            }
            if(pass)break;
        }
        if(!pass)printf("No\n");
        /*if(check(node,0)>1){
            printf("Yes\n");
        }
        else printf("No\n");*/

    }

    return 0;
}
