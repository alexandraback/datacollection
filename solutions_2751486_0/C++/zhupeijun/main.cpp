#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string s;

bool check(int b,int e,int len)
{
    int cnt = 0,i;

    for(i = b;i <= e;i++)
    {
        if(s[i] == 'a' ||
           s[i] == 'e' ||
           s[i] == 'i' ||
           s[i] == 'o' ||
           s[i] == 'u')
            cnt = 0;
        else
            cnt ++;
        if(cnt >= len)
            return true;
    }
    return false;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    int ca,cn,i,j,m;

    cin >> cn;

    for(ca = 1;ca <= cn;ca++)
    {
        cin >> s >> m;

        int n = s.size(),ans = 0;

        for(i = 0;i < n;i++)
        {
            for(j = i;j < n;j++)
            {
                if(check(i,j,m))
                {
                    ans++;
                }
            }
        }

        cout << "Case #"<< ca <<": ";
        cout << ans << endl;
    }
    return 0;
}
