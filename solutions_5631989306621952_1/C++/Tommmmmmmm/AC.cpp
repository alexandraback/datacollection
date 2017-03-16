#include<bits/stdc++.h>
using namespace std;
int n;
char s[5555];
char q[5555];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int _,cas=1;scanf("%d",&_);    
    while(_--){
        scanf("%s",s);
        printf("Case #%d: ",cas++);
        n=strlen(s);
        int front=2000,rear=2000;
        for(int i=0;i<n;i++){
            bool flag=1;
            for(int j=front;j<=rear;j++){
                char c1=j==rear?s[i]:q[j];
                char c2=j==front?s[i]:q[j-1];
                if(c1>c2)break;
                if(c1<c2){
                    flag=0;
                    break;
                }
            }
            if(flag)q[rear++]=s[i];
            else q[--front]=s[i];
        }
        for(int i=front;i<rear;i++)putchar(q[i]);puts("");
    }
}
