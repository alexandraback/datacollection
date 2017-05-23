#include<stdio.h>
#include<string.h>

typedef long long ll;


void main()
{
    ll t, n, i, j, k=1;
    char s[1005], ans[1005], ch[2];
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-output.txt", "w", stdout);
    scanf("%lld", &t);
    while(k<=t)
    {
        scanf("%s", s);
        ans[0]=s[0];
        ans[1]='\0';
        n=strlen(s);
        for(i=1; i<n; i++)
        {
            if(s[i]<ans[0])
            {
                ans[i]=s[i];
            }
            else
            {
                for(j=i; j>=0; j--)
                {
                    ans[j+1]=ans[j];
                }
                ans[0]=s[i];
            }
            ans[i+1]='\0';
        }
        printf("Case #%lld: %s\n", k, ans);
        k++;
    }

}
