#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int check(char text[100], char target[110])
{
    int i,j,ans=0;
    int len = strlen(text),lent=strlen(target);
    for(i=0;i<len-lent+1;i++)
    {
        for(j=0;j<lent;j++)
            if(text[i+j]!=target[j])
               break;
        if(j==lent)
            ans++;
    }
    return ans;
}

int num;
double ans;

int tempmax;

void gao(int id, char xnum[10], int K,int S,  char target[9], char rad[8])
{
    if(id==S)
    {
        num++;
        int temp=check(rad, target);
        ans = ans +temp;
        if(temp>tempmax)
            tempmax=temp;
        return;
    }
    for(int i=0;i<K;i++){
        rad[id]=xnum[i];
        gao(id+1, xnum, K, S, target, rad);
    }
}

int main()
{
    int T,casn=0;
    int K,L,S,i,j;
    char keyp[100];
    char rad[100];
    char target[100];
    scanf("%d",&T);
    while(T--)
    {
        num=0;
        ans=0.0;
        scanf("%d%d%d",&K,&L,&S);
        scanf("%s",keyp);
        scanf("%s",target);
        rad[S]='\0';
        tempmax=0; 
        gao(0, keyp, K, S, target,rad);
        printf("Case #%d: %lf\n", ++casn, tempmax-ans/num);
    }
    return  0;
}
