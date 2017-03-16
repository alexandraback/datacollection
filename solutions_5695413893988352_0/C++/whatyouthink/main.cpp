#include <bits/stdc++.h>
using namespace std;
bool check(int x,char* s)
{
    int len = strlen(s);
    for(int i = len - 1; i >= 0;i--)
    {
        if(s[i] == '?')
        {
            x /= 10;
            continue;
        }
        if((s[i] - '0') != x % 10)
            return false;
        x /= 10;
    }
    return true;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    cin>>t;
    for(int cas = 1; cas <= t; cas++)
    {
        char s1[4],s2[4];
        cin>>s1>>s2;
        int len = strlen(s1);
        int x = 1;
        for(int i = 0; i < len; i++) x = x * 10;
        bool flag = false;
        int c ,k;
        for(int i = 0; i < x; i++)
        {
            bool flag1 = check(i,s1);
            if(!flag1) continue;
            for(int j = 0; j < x; j++)
            {
                bool flag2 = check(j,s2);
                if(flag1 && flag2)
                {
                    if(!flag)
                    {
                        c = i;
                        k = j;
                        flag = true;
                    }
                    else if(abs(i - j) < abs(c - k))
                    {
                        c = i;
                        k = j;
                    }
                    else if(abs(i - j) == abs(c - k))
                    {
                        if(i < c)
                        {
                            c = i;
                            k = j;
                        }
                        else if(i == c)
                        {
                            k = min(k,j);
                        }
                    }
                }
            }
        }
        printf("Case #%d: ",cas);
        int x1 = c ? 0 : 1;
        int x2 = k ? 0 : 1;
        int tmp1 = c,tmp2 = k;
        while(tmp1){x1++,tmp1 /= 10;}
        while(tmp2){x2++,tmp2 /= 10;}
        for(int i = 1; i <= len - x1; i++)
            printf("0");
        printf("%d ",c);
        for(int i = 1; i <= len - x2; i++)
            printf("0");
        printf("%d\n",k);
    }
    return 0;
}
