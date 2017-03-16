/*
LANG: C++
TASK: xxx
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<sstream>

using namespace std;
#define x first
#define y second

#define FOR(i,a,b) for(__typeof(b)i = a; i < b;i++)
#define FORE(i,a,b) for(__typeof(b)i = a; i <= b;i++)
#define FOR_R(i,a,b) for(__typeof(b)i = a; i > b;i--)
#define FORE_R(i,a,b) for(__typeof(b)i = a; i >= b;i--)
#define TR(it , c) for(__typeof((c).end())it = (c).begin(); it != (c).end();it++)
int tCase;
string s;
int line[1000100];
int n;
int ans = 0;

void solve(int tt)
{
    ans = 0;
    cin >> s;
    cin >> n;
    /*FOR(i,0,s.length())
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            line[i] = 0;
        else
            line[i] = 1;
    }*/
    int pos_1 = -1;
    int now = 0;
    FOR(i , 0 , s.length())
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            now = 0;
        }
        else
        {
            now++;
            if(now == n)
            {
                //printf("(%d %d %d)%d = %d %d\n",s.length() , now , pos_1,i,(s.length()-i-1),(i-n-pos_1));
                now--;
                ans += (s.length()-i-1+1)*(i-n-pos_1+1);
                pos_1 = i-(n-1);
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    cin >> tCase;
    FOR(tt , 0 , tCase)
    {
        printf("Case #%d: ",tt+1);
        solve(tt+1);
    }
    return 0;
}


