#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int T;
int n;
int len;
char ch;
int d[1000010];
int next[1000010];
int k;
int ans;

int main()
{
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        ch='.';
        k=0;
        len=0;
        while(1)
        {
            scanf("%c",&ch);
            while(ch<'a' || ch>'z') 
            {
                if(ch==' ') break;
                scanf("%c",&ch);
            }
            if (ch==' ') {
                scanf("%d",&n);
                break;
            }
            if(ch=='a' || ch=='o' || ch=='i' || ch=='u' || ch=='e') k=0;
            else k++;
            len++;d[len]=k;
        }
        memset(next,0,sizeof(next));
        k=0;
        for(int j=1;j<=len;j++)
        {
            if(d[j]>=n) {
                k=j;
            }else next[j]=k;
        }
        ans=0;
        //for(int j=1;j<=len;j++) printf("%d \n",next[j]);
        for(int j=len;j>=1;j--)
        {
            if(d[j]>=n)
            {
                ans+=j-n+1;
            }
            else
            {
                if(next[j]==0) continue; else ans+=next[j]-n+1;
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
