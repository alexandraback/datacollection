#include<stdio.h>

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 0; t<T; t++)
    {

        char shyness[1005];
        int n;
        scanf("%d%s",&n,shyness);

        int people = 0;
        int invited = 0;
        for(int i=0;i<n+1;i++)
        {
            if(i>people)
            {
                int tm = i-people ;
                people+=tm;
                invited+=tm;
            }
            people+=shyness[i]-'0';
        }
        printf("Case #%d: %d\n",t+1,invited);
    }
    return 0;
}
