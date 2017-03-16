#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=5e5+9;
const int inf=1e9+9;

int cnt[30],tmp[20];
int ans[2009];
char aa[30][30]= {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    int cass=1;
    while(t--)
    {
        string num;
        cin>>num;
        int len=num.length();
        printf("Case #%d: ",cass++);
        memset(cnt,0,sizeof(cnt));
        memset(tmp,0,sizeof(tmp));
        for(int i=0; i<len; i++)
        {
            cnt[num[i]-'A']++;
        }
        int loca=0;
        for(int i=0; i<cnt['Z'-'A']; i++)
        {
            ans[loca++]=0;
            tmp[0]=cnt['Z'-'A'];
        }
        for(int i=0; i<cnt['W'-'A']; i++)
        {
            ans[loca++]=2;
            tmp[2]=cnt['W'-'A'];
        }
        for(int i=0; i<cnt['X'-'A']; i++)
        {
            ans[loca++]=6;
            tmp[6]=cnt['X'-'A'];
        }
        for(int i=0; i<cnt['G'-'A']; i++)
        {
            ans[loca++]=8;
            tmp[8]=cnt['G'-'A'];
        }
        for(int i=0; i<cnt['U'-'A']; i++)
        {
            ans[loca++]=4;
            tmp[4]=cnt['U'-'A'];
        }
        for(int i=0; i<cnt['F'-'A']-tmp[4]; i++)
        {
            ans[loca++]=5;
            tmp[5]=cnt['F'-'A']-tmp[4];
        }
        for(int i=0; i<cnt['H'-'A']-tmp[8]; i++)
            {ans[loca++]=3;tmp[3]=cnt['H'-'A']-tmp[8];}
        for(int i=0; i<cnt['V'-'A']-tmp[5]; i++)
            {ans[loca++]=7;tmp[7]=cnt['V'-'A']-tmp[5];}
        for(int i=0; i<cnt['O'-'A']-tmp[0]-tmp[2]-tmp[4]; i++)
            {ans[loca++]=1;tmp[1]=cnt['O'-'A']-tmp[0]-tmp[2]-tmp[4];}
        for(int i=0; i<cnt['I'-'A']-tmp[5]-tmp[6]-tmp[8]; i++)
            ans[loca++]=9;
        sort(ans,ans+loca);
        for(int i=0; i<loca; i++) printf("%d",ans[i]);
        printf("\n");
    }

    return 0;
}
