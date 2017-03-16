#include <cstdio>
#include <cstring>
int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("largeans.txt","w",stdout);
    int T,tmp;
    char n[10];
    scanf("%d",&T);
    for(int cases=1; cases<=T; cases++)
    {
        bool used[10]= {};
        int cnt=0, now=1;
        scanf("%d",&tmp);
        sprintf(n,"%d",tmp);
        if(n[0]=='0')
        {
            printf("Case #%d: INSOMNIA\n",cases);
            continue;
        }
        while(cnt!=10)
        {
            sprintf(n,"%d",tmp*now);
            now++;
            for(int i=0; n[i]; i++)
            {
                if(!used[n[i]-'0'])
                {
                    used[n[i]-'0']=true;
                    cnt++;
                }
            }
        }
        printf("Case #%d: %s\n",cases,n);
    }
    return 0;
}
