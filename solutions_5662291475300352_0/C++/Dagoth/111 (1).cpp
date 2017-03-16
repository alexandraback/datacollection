#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;

double eps = 1e-9;

struct st
{
    double pos;
    double speed;
};

bool pred(st a, st b)
{
    return a.pos < b.pos || (a.pos == b.pos && a.speed < b.speed);
}

signed main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    freopen("C-small-1-attempt3.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    int fix = 0;
    while(T--)
    {
        fix++;
        int n;
        cin >> n;
        int num = 0;
        vector<st> hs;
        for(int i = 0; i < n; i++)
        {
           double d;
           int h;
           double m;
           cin >> d >> h >> m;
           num += h;
            for(int j = 0; j < h; j++)
            {
                st temp;
                temp.pos = d;
                temp.speed = (double) (360.0/(m+j));
                hs.push_back(temp);
            }
        }
        if(num == 1)
        {
              cout << "Case #" << fix << ": " << 0 << '\n';
            continue;
        }
        sort(all(hs), pred);

         if(hs[0].speed > hs[1].speed)
        {
            double tt = (hs[1].pos - hs[0].pos) / (hs[1].speed - hs[0].speed);
                hs[0].pos += tt*hs[0].speed;
                hs[1].pos += tt*hs[1].speed;
        }

          double st = hs[0].pos;
        int rem = 360.0 - st;
        double t = rem / hs[0].speed;
        double snd = hs[1].pos + t * hs[1].speed;

        if(snd < (720.0 - eps))
        {
            cout << "Case #" << fix << ": " << 0 << '\n';
            continue;
        }

        if(fabs(hs[0].speed - hs[1].speed) > eps)
        {
            cout << "Case #" << fix << ": " << 1 << '\n';
            continue;
        }
        else
            cout << "Case #" << fix << ": " << 2 << '\n';
    }
    return 0;
}
