#include<bits/stdc++.h>
using namespace std;
char c[50];
int n,j;
void print(int now){
    if(j==0)
        return;
    if(now==n-2){
        printf("%s",c);
        for(int i=3;i<=11;i++)
            printf(" %d",i);
        printf("\n");
        j--;
    }
    else{
    c[now]='0';
    c[now+1]='0';
    print(now+2);
    if(j==0)
        return;
    c[now]='1';
    c[now+1]='1';
    print(now+2);
    if(j==0)
        return;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    scanf("%d %d",&n,&j);
    for(int i=0;i<n;i++)
        c[i]='0';
    c[0]='1';
    c[1]='1';
    c[n-1]='1';
    c[n-2]='1';
    printf("Case #1:\n");
    print(2);
}
