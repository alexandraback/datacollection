#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const string tab[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int have[26];
int ans[10];
void sub(int n,int x)
{
    for(int i=0;i<(int)tab[n].size();++i)
    {
        have[tab[n][i]-'A']-=x;
    }
}
int main()
{
    int T,cas=0;
    cin>>T;
    while(T--)
    {
        printf("Case #%d: ",++cas);
        string s;
        cin>>s;
        int len=(int)s.size();
        memset(have,0,sizeof(have));
        for(int i=0;i<len;++i)
        {
            have[s[i]-'A']++;
        }
        memset(ans,0,sizeof(ans));
        ans[0]=have['Z'-'A'];
        sub(0,ans[0]);
        ans[2]=have['W'-'A'];
        sub(2,ans[2]);
        ans[4]=have['U'-'A'];
        sub(4,ans[4]);
        ans[6]=have['X'-'A'];
        sub(6,ans[6]);
        ans[8]=have['G'-'A'];
        sub(8,ans[8]);

        ans[1]=have['O'-'A'];
        sub(1,ans[1]);
        ans[5]=have['F'-'A'];
        sub(5,ans[5]);
        ans[7]=have['S'-'A'];
        sub(7,ans[7]);

        ans[3]=have['R'-'A'];
        sub(3,ans[3]);
        ans[9]=have['E'-'A'];
        sub(9,ans[9]);

        for(int i=0;i<10;++i)
        {
            for(int j=1;j<=ans[i];++j)
            {
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
