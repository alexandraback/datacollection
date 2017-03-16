#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct seg
{
    int s;
    int e;
}segs[100005];

bool isVol(char c)
{
    return (c == 'a' || c == 'i' || c == 'o' || c == 'e' || c == 'u');
}

int main()
{
    ofstream fout;
    fout.open("out1.out", ios::out);
    int t;
    cin >> t;
    for (int kk = 1; kk <= t; ++kk)
    {
        char s[100005];
        int n;
        cin >> s >> n;
        int l = strlen(s);
        bool ins = false;
        int cnt = 0;
        int ti;
        for (int i = 0; i < l; ++i)
        {
            if (!ins && !isVol(s[i]))
            {
                ins = true;
                ti = i;
            }
            if (isVol(s[i]))
            {
                if (ins && i - ti >= n)
                {
                    segs[cnt].s = ti;
                    segs[cnt++].e = i - 1;
                }
                ins = false;
            }
        }
        if (!isVol(s[l - 1]) && l - ti >= n)
        {
            segs[cnt].s = ti;
            segs[cnt++].e = l - 1;
        }
        long long res = 0;
        int pos = 0;
        ins = false;
        if (cnt > 0)
        {
            for (int i = 0; i < l; ++i)
            {
                if (pos >= cnt)
                    break;
                if (i == segs[pos].s)
                    ins = true;
                else if (i == segs[pos].e + 1)
                {
                    ins = false;
                    ++pos;
                }
                if (ins)
                {
                    if (segs[pos].e - i + 1 >= n)
                        res += l - (i + n - 1);
                    else if (pos < cnt - 1)
                    {
                        res += l - (segs[pos + 1].s + n - 1);
                    }
                }
                else if (pos < cnt)
                {
                    res += l - (segs[pos].s + n - 1);
                }
            }
        }
        fout << "Case #" << kk << ": " << res << endl;
    }
}
