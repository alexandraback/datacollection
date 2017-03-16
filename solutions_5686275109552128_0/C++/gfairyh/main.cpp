#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1005

int num[MAXN];

int main()
{
//    cout << "Hello world!" << endl;
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t, d, p;
    int cas = 1;
    cin >> t;
    while(t--)
    {
        cin >> d;
        memset(num, 0, sizeof(num));
        int maxt = 0;
        for(int i=0; i<d; i++)
        {
            cin >> p;
            num[p]++;
            if(p > maxt)
                maxt = p;
        }
        int mint = maxt;
        for(int i=1; i<=maxt; i++)
        {
            int cnt = 0;
            for(int j=i+1; j<=maxt; j++)
            {
                cnt += num[j]*((j+i-1)/i-1);
            }
            if(cnt + i < mint)
                mint = cnt + i;
        }
        cout << "Case #" << cas++ << ": " << mint << endl;
    }
    return 0;
}
