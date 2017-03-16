#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;
char Map[30];
char revMap[30];

vector<string> Ip;
vector<string> Op;
inline void prepareMap()
{
    Ip.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    Op.push_back("our language is impossible to understand");

    Ip.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    Op.push_back("there are twenty six factorial possibilities");

    Ip.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    Op.push_back("so it is okay if you want to just give up");

    memset(Map, -1, sizeof Map);
    memset(revMap, -1, sizeof revMap);
    for(int i=0;i<3;i++)
    {
        int N = Ip[i].length();
        assert(N == (int)Op[i].length());
        for(int j=0;j<N;j++)
        {
            int x = Ip[i][j]-'a';
            int y = Op[i][j]-'a';
            char xx = x + 'a';
            char yy = y + 'a';
            if(xx == ' ')
            {
                assert(yy == xx);
                continue;
            }
            // cout << "At string = " << i << " " << xx << " " << yy << endl;
            if(Map[x] == -1) {
                Map[x] = yy;
                assert(revMap[y] == -1);
                revMap[y] = xx;
            }
            else
            {
                assert(Map[x] == yy);
                assert(revMap[y] == xx);
            }
        }
    }
    /*
    for(int i=0;i<26;i++)
    {
        char x = i+'a';
        char y = Map[i];
        cout << x << " " << y << endl;
    }
    */
    Map['q'-'a'] = 'z';
    Map['z'-'a'] = 'q';

    revMap['z'-'a'] = 'q';
    revMap['q'-'a'] = 'z';

}

char s[120];
int main()
{
    prepareMap();
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    gets(s);
    sscanf(s, "%d", &T);
    for(int cases=1;cases<=T;cases++)
    {
        gets(s);
        string ss(s);
        int N = ss.length();
        cout << "Case #" << cases << ": ";

        for(int i=0;i<N;i++)
        {
            if(ss[i] == ' ')
            cout << " ";
            else
            cout << Map[ss[i]-'a'];
        }

        cout << endl;
    }
    return 0;
}
