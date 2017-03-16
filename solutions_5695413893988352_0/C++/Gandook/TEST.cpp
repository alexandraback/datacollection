#include<bits/stdc++.h>

#define SZ(x) ((int(x.size())))

typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = 1*1000*1000+10;
int T, n, tvn[4], tmp;
bool flg;
string s, t;
pair <int, pair <int, int> > mn;

int ABS (int x)
{
    if (x < 0)
        return -x;
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    ifstream in;
    ofstream out;
    in.open ("B-small-attempt2.in", ios::in);
    out.open ("B-small-attempt2.out", ios::out);
    tvn[0] = 1;
    for (int i = 1; i < 4; i++)
        tvn[i] = tvn[i - 1] * 10;
    in >> T;
    for (int i = 0; i < T; i++)
    {
        mn = {INF, {INF, INF}};
        in >> s >> t;
        n = s.length();
        for (int j = 0; j < tvn[n]; j++)
        {
            for (int k = 0; k < tvn[n]; k++)
            {
                flg = 0;
                tmp = j;
                for (int p = n - 1; p >= 0; p--)
                {
                    if (s[p] != '?' && s[p] - '0' != tmp % 10)
                    {
                        flg = 1;
                        break;
                    }
                    tmp /= 10;
                }
                if (flg)
                    continue;
                tmp = k;
                for (int p = n - 1; p >= 0; p--)
                {
                    if (t[p] != '?' && t[p] - '0' != tmp % 10)
                    {
                        flg = 1;
                        break;
                    }
                    tmp /= 10;
                }
                if (flg)
                    continue;
                mn = min (mn, make_pair (ABS (j - k), make_pair (j, k)));
            }
        }
        out << "Case #" << i + 1 << ": ";
        if (mn.second.first < 100)
        {
            if (mn.second.first > 9)
            {
                for (int j = 0; j < n - 2; j++)
                    out << "0";
            }
            else
            {
                for (int j = 0; j < n - 1; j++)
                    out << "0";
            }
        }
        out << mn.second.first << " ";
        if (mn.second.second < 100)
        {
            if (mn.second.second > 9)
            {
                for (int j = 0; j < n - 2; j++)
                    out << "0";
            }
            else
            {
                for (int j = 0; j < n - 1; j++)
                    out << "0";
            }
        }
        out << mn.second.second << endl;
    }
    in.close();
    out.close();
	return 0;
}
