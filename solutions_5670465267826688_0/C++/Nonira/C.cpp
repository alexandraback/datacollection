#include<stdio.h>

int arr[4][4]={{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}},mul[8][8],i,j,t,k,s,left[10010],right[10010],all,p;
long long l,x,mnl,mnr;
char st[10010];

int main(){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            mul[i][j]=arr[i][j];
            mul[i+4][j]=(arr[i][j]+4)%8;
            mul[i+4][j+4]=arr[i][j];
            mul[i][j+4]=(arr[i][j]+4)%8;
        }
    }
    scanf("%d",&t);
    s=0;
    for(k=1;k<=t;k++){
        scanf("%lld %lld",&l,&x);
        scanf("%s",st);
        left[0]=0;
        for(i=0;i<l-1;i++){
            left[i+1]=mul[left[i]][st[i]-'h'];
        }
        all=mul[left[l-1]][st[l-1]-'h'];
        right[0]=0;
        for(i=l-1;i>0;i--){
            right[l-i]=mul[right[l-i-1]][st[i]-'h'];
        }
        p=0;
        for(i=0;i<x%4;i++)p=mul[p][all];
        if(p!=4)printf("Case #%d: NO\n",k);
        else{
            mnl=l*x;
            mnr=l*x;
            for(i=0;i<l;i++){
                p=left[i];
                for(j=0;j<4;j++){
                    if(p==1){
                        if(mnl>i+j*l)mnl=i+j*l;
                        break;
                    }
                    p=mul[all][p];
                }
            }
            for(i=0;i<l;i++){
                p=right[i];
                for(j=0;j<4;j++){
                    if(p==3){
                        if(mnr>i+j*l)mnr=i+j*l;
                        break;
                    }
                    p=mul[p][all];
                }
            }
            if(mnl+mnr<=l*x)printf("Case #%d: YES\n",k);
            else printf("Case #%d: NO\n",k);
        }
    }
    return 0;
}
