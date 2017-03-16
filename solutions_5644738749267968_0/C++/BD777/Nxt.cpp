#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define bug puts("here");

using namespace std;

typedef long long ll;

const int maxn =  1086;
const ll mod = 1e9+7;

double a[maxn],b[maxn];

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.txt","w+",stdout);
    int T;
    cin >>T;
    int kase = 0;
    while(T--)
    {
        int n;
        cin >> n;
        int i;
        for(i=0;i<n;i++)
            cin >> a[i];
        for(i=0;i<n;i++)
            cin >> b[i];
        sort(a,a+n);
        sort(b,b+n);
        /*
        for(i=0;i<n;i++)
            cout << a[i] << ' ';
        cout << endl;
        for(i=0;i<n;i++)
            cout << b[i] << ' ';
        cout << endl;
        */
        int ans1,ans2;
        ans1 = ans2 = 0;
        int la,lb,ra,rb;
        la = lb = 0;
        ra = rb = n-1;
        while(rb >= lb)
        {
            if(a[ra] > b[rb])
            {
                ans2 ++;
                lb ++;
            }
            else{
                rb --;
            }
            ra --;
        }
        la = lb = 0;
        ra = rb = n-1;
        while(rb >= lb)
        {
            if(a[la] < b[lb])
            {
                rb --;
                la ++;
            }
            else
            {
                ans1 ++;
                la ++;
                lb ++;
            }
        }
        cout << "Case #" << ++kase << ": " << ans1 << ' ' << ans2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
}
