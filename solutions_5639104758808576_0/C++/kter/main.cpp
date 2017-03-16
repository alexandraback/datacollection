#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int s[2000];
int SMax;
int main(void)
{
    int tcase,tt;
    tt=0;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    cin>>tcase;
    while (tcase--)
    {
        tt++;
        string str;
        
        scanf("%d",&SMax);
        cin>>str;
        for (int i=0;i<=SMax;i++)
            s[i]=str[i]-'0';
        
        int Pnum=s[0];
        int ans=0;
        for (int i=1;i<=SMax;i++)
        {
            if (s[i]>0)
            {
                if (Pnum<i)
                {
                    ans+=(i-Pnum);
                    Pnum=i;
                    Pnum+=s[i];
                }
                else
                {
                    Pnum+=s[i];
                }
            }
        }
        
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}