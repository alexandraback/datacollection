#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <set>
using namespace std;
int ct[300];
int cr[30][300];
string ss[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
bool wk(int x)
{
    for(int i=0;i<=30;i++)
        if(ct[i]<cr[x][i])
            return 0;
    return 1;
}
vector<int> an;
void su(int x)
{
    for(int i=0;i<=30;i++)
        ct[i]-=cr[x][i];
    an.push_back(x);
    return;
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int j=0;j<=9;j++)
    {
        for(int k=0;k<ss[j].length();k++)
            cr[j][ss[j][k]-'A']++;
    }
    for(int tt=1;tt<=t;tt++)
    {
        string s;
        cin>>s;
        for(int j=0;j<=300;j++)
            ct[j]=0;
        for(int i=0;i<s.length();i++)
        {
            ct[s[i]-'A']++;
        }
        an.clear();
        while(wk(0))su(0);
        while(wk(2))su(2);
        while(wk(4))su(4);
        while(wk(6))su(6);
        while(wk(8))su(8);
        while(wk(3))su(3);
        while(wk(7))su(7);
        while(wk(1))su(1);
        while(wk(5))su(5);
        while(wk(9))su(9);
        sort(an.begin(),an.end());
        printf("Case #%d: ",tt);
        for(int i=0;i<an.size();i++)
            printf("%d",an[i]);
        printf("\n");
    }
}
