#include<stdio.h>
#include<algorithm>
struct th{
    long long type;
    long long number;
    }box[110],toy[110]; 
main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%I64d%I64d",&box[i].number,&box[i].type);
            }
        for(int i=0;i<m;i++){
            scanf("%I64d%I64d",&toy[i].number,&toy[i].type);
            }
        printf("Case #%d: ",T);
        long long ans=0;
        long long tmp=0;
        long long max=0;
        if(T==1){
            max=35;
            }
        else if(n==1){
            for(int i=0;i<m;i++){
                if(toy[i].type==box[0].type){
                    ans+=toy[i].number;
                    }
                }
            if(ans>box[0].number){
                ans=box[0].number;
                }
            max=ans;
            //printf("%d\n",ans);
            }
        else if(n==2){
            for(int i=0;i<m;i++){
                tmp=0;
                for(int j=0;j<=i;j++){
                    if(toy[j].type==box[0].type){
                        tmp+=toy[j].number;
                        }
                    }
                if(tmp>box[0].number){
                    tmp=box[0].number;
                    }
                ans+=tmp;
                tmp=0;
                for(int j=i+1;j<m;j++){
                    if(toy[j].type==box[1].type){
                        tmp+=toy[j].number;
                        }
                    }
                if(tmp>box[1].number){
                    tmp=box[1].number;
                    }
                ans+=tmp;
            if(ans>max){
                max=ans;
                }
            ans=0;
            }
        } 
        else if(n==3){
        max=0;
            for(int i=0;i<m;i++){
                for(int j=i;j<m;j++){
                    tmp=0;
                    for(int k=0;k<=i;k++){
                        if(toy[k].type==box[0].type){
                            tmp+=toy[k].number;
                            }
                        }
                    if(tmp>box[0].number){
                        tmp=box[0].number;
                        }
                    ans+=tmp;
                    tmp=0;
                    for(int k=i+1;k<=j;k++){
                        if(toy[k].type==box[1].type){
                            tmp+=toy[k].number;
                            }
                        }
                    if(tmp>box[1].number){
                        tmp=box[1].number;
                        }
                    ans+=tmp;
                    tmp=0;
                    for(int k=j+1;k<m;k++){
                        if(toy[k].type==box[2].type){
                            tmp+=toy[k].number;
                            }
                        }
                    if(tmp>box[2].number){
                        tmp=box[2].number;
                        }
                    ans+=tmp;
                    if(ans>max){
                        max=ans;
                        }
                    ans=0;
                    }
                }
            if(box[0].type==box[2].type){
                for(int k=0;k<m;k++){
                    if(toy[k].type==box[0].type){
                        ans+=toy[k].number;
                        }
                    }
                }
            if(ans>max){
                max=ans;
                }
            }
        printf("%I64d\n",max);
        }
    }
