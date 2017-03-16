#include<stdio.h>
#include<string.h>
char word[110];
bool is(char in)
{
    if(in=='a'||in=='e'||in=='i'||in=='o'||in=='u')
    {
        return true;
    }
    return false;
}
int calc(int i,int j,int n)
{
    int flag=0;
    for(int k=i;k+n-1<=j;k++)
    {
        flag=0;
        for(int k1=0;k1<n;k1++) if(is(word[k+k1]))
            flag=1;
        if(!flag)
            return 1;
    }
    return 0;
}
int main()
{
    #ifdef OJ
        freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
    #endif // OJ
    int T,n;
    int ca=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",word);
        int res=0;
        scanf("%d",&n);
        int ll=strlen(word);
        for(int i=0;i<ll;i++)
            for(int j=i;j<ll;j++)
            {
                res+=calc(i,j,n);
            }
       // printf("%s\n%d\n",word,n);
        printf("Case #%d: %d\n",++ca,res);
    }
}
