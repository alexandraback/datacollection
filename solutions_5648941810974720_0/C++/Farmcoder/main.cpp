#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int num[30];
int ans[10];
string s;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>s;
        memset(num,0,sizeof(num));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<s.length();i++)
        {
            num[s[i]-'A']++;
        }
        ans[6]=num['X'-'A'];
        ans[0]=num['Z'-'A'];
        num['S'-'A']-=ans[6];
        ans[7]=num['S'-'A'];
        num['V'-'A']-=ans[7];
        ans[5]=num['V'-'A'];
        num['F'-'A']-=ans[5];
        ans[4]=num['F'-'A'];
        ans[8]=num['G'-'A'];
        ans[9]=num['I'-'A']-ans[5]-ans[6]-ans[8];
        ans[2]=num['W'-'A'];
        ans[3]=num['R'-'A']-ans[0]-ans[4];
        ans[1]=num['O'-'A']-ans[2]-ans[4]-ans[0];
        printf("Case #%d: ",ca);
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<ans[i];j++)
            {
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
