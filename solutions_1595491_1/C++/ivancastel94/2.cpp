#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int cases,i,t,n,s,p,pun,max,div;
    scanf("%d",&t);
    for(cases=1;cases<=t;cases++){
        max=0;
        scanf("%d %d %d",&n,&s,&p);
        for(i=0;i<n;i++){
            cin>>pun;
            div=pun/3;
            if(pun%3==0){
                if(div>=p)max++;
                else{
                    if(div+1>=p&&pun>=2&&s>0){
                        max++;
                        s--;
                        }
                    }
                }
            if(pun%3==1&&div+1>=p)max++;
            if(pun%3==2){
                if(div+1>=p)max++;
                else{
                    if(div+2>=p&&pun>=2&&s>0){
                        max++;
                        s--;
                        }
                    }
                }
            }
        cout<<"Case #"<<cases<<": "<<max<<endl;;
        }
    }
