#include<bits/stdc++.h>
using namespace std;

char st[110];

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        scanf("%s",st);
        int len=strlen(st);
        int ret=0;
        for(int i=0;i<len;i++){
            bool judge=true;
            for(int j=0;j<len;j++){
                if(st[j]=='-')judge=false;
            }
            if(judge)break;
            ret++;
            if(st[0]=='+'){
                for(int j=0;j<len;j++){
                    if(st[j]=='+')st[j]='-';
                    else break;
                }
            }else{
                for(int j=0;j<len;j++){
                    if(st[j]=='-')st[j]='+';
                    else break;
                }
            }
        }
        printf("Case #%d: %d\n",_,ret);
    }
    return 0;
}
