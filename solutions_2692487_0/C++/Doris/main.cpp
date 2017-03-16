#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int N = 1100000;
int a[N];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, x;

    cin>>t;
    x=t;
    while(t--)
    {
        int n, m;
        scanf("%d %d", &m, &n);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        int ans = n;
        int now = 0;
        sort(a, a + n);
        for(int i = 0; i < n; i++)
        {
            while (m <= a[i] && m - 1)
            {
                now ++;
                m += m - 1;
            }
            if (m == 1)
            {
                break;
            }
            m += a[i];
            ans = min(ans, now + n - i - 1);
        }
        cout<<"Case #"<<x-t<<": "<<ans<<endl;
    }
    return 0;
}
