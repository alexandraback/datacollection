#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int T;
    cin >> T;
    for (int i=0;i<T;i++)
    {
        int smax;
        cin >> smax;
        string a;
        cin >> a;
        int cnt = 0,add = 0;
        for (int j=0;j<=smax;j++)
        {
            if (cnt<j && a[j]!=0)
            {
                add += j-cnt;
                cnt = j;
            }
            cnt += (int)(a[j]-'0');
            //cout << cnt << endl;
        }
        printf("Case #%d: %d\n",i+1,add);
    }
}
