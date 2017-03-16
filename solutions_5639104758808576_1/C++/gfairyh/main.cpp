#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 1005
int num[MAXN];

int main()
{
//    cout << "Hello world!" << endl;
    freopen("inputA.in", "r", stdin);
    freopen("outputA.out", "w", stdout);
    int t;
    int smax;
    char s[MAXN];
    cin >> t;
    int cas = 1;
    while(t--)
    {
        cin >> smax >> s;
        memset(num, 0, sizeof(num));
        for(int i=0; i<=smax; i++)
        {
            num[i] = s[i] - '0';
        }
        int cnt = 0;
        int add = 0;
        for(int i=0; i<=smax; i++)
        {
            if(num[i] == 0)
                continue;
            if(cnt < i)
            {
                add += i - cnt;
                cnt = i;
            }
            cnt += num[i];
        }
        cout << "Case #" << cas++ << ": " << add << endl;
    }
    return 0;
}
