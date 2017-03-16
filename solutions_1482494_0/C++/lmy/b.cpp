#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;
vector <int> b;

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    int t;
    cin>>t;
    for (int no = 1; no <= t; no++)
    {
        int n;
        cin>>n;
        a.clear();
        b.clear();
        for (int i = 0; i < n; i++)
        {
            int ai, bi;
            cin>>ai>>bi;
            a.push_back(ai);
            b.push_back(bi);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int cura = 0;
        int curb = 0;
        int curstar = 0;
        int cnt = 0;
        bool done = false;
        while (true)
        {
            if (curstar >= b[curb])
            {
                curb++;
                cnt++;
                curstar += 2;
                if (curb == n)
                {
                    done = true;
                    break;
                }
            }
            else
            {
                if (cura==n) break;
                if (curstar >= a[cura])
                {
                    cura++;
                    cnt++;
                    curstar += 1;

                }
                else
                {
                    break;
                }
            }
        }
        if (!done) cout<<"Case #"<<no<<": Too Bad"<<endl;
        else cout<<"Case #"<<no<<": "<<cnt<<endl;
    }
}
