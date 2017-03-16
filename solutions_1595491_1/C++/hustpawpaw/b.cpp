#include<iostream>
#include<cstdlib>
using namespace std;
int sur[31];
int maxp[31];
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out", "w", stdout);
    for (int i = 1; i <= 30; ++i)
    {
        if (i % 3 ==0)
        {
              maxp[i] = i/3;
              sur[i] = i/3+1;
        }
        if (i % 3 ==1)
        {
              maxp[i] = sur[i] = i / 3 +1;
        }
        if (i % 3 == 2)
        {
              sur[i]  = i / 3 +2;
              maxp[i] = i / 3 +1;
        }
    }
    maxp[0] = 0;
    sur[0] = 0;
    int n,t,s,p;
    int ans;
    int score;
    cin >> t;
    for (int test = 1; test <= t; ++test)
    {
        cin >> n >> s >> p;
        ans = 0;;
        for (int k = 1; k <= n ; ++k)
        {
            cin >> score;
            if (maxp[score] >= p)
            {
               ans++;
               continue;
            }
            if (sur[score] >= p && s >=1)
            {
               ++ans; 
               s--;
               continue;
            }
        }
          cout <<"Case #"<<test<<": "<<ans<<endl;
    }
    return 0;
}
