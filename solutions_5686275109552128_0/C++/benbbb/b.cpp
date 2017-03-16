#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int T,ca,i,cnt,ans,j,D;
    int p[1010];
    cin>>T;
    for (ca=1;ca<=T;ca++)
    {
        ans=999999;

        cin>>D;
        for (i=1;i<=D;i++)
         cin>>p[i];
        for (i=1;i<=1000;i++)
         {
             cnt=i;
             for (j=1;j<=D;j++)
                cnt+=(p[j]+i-1)/i-1;
             if (cnt<ans) ans=cnt;
         }
         printf("Case #%d: %d\n",ca,ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
