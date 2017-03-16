#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define all(v)v.begin(),v.end()

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int casos, t;
    string st;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++)
    {
        cin >> t >> st;
        int res = 0, a = 0;
        forn(i,t+1)
        {
            while(a<i) {
                a++;
                res++;
            }
            forn(j,st[i]-'0')
                a++;
        }
        printf("Case #%d: %d\n",casito,res);
    }

}
