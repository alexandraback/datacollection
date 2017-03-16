#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool was;
vector <char> c, j, cntc, cntj, ans1, ans2;
int n;

void gen(int i, int flag)
{
    if (i == n)
    {
        long long cc = 0, jj = 0, ansc = 0, ansj = 0;
        if (!was)
        {
            ans1 = cntc, ans2 = cntj;
            was = true;
            return;
        }
        for (int q = 0; q < n; ++q)
        {
            cc = 10 * cc + (cntc[q] - '0'), jj = 10 * jj + (cntj[q] - '0');
            ansc = 10 * ansc + (ans1[q] - '0'), ansj = 10 * ansj + (ans2[q] - '0');
        }
        if (make_pair(abs(ansc - ansj), make_pair(ansc, ansj)) > make_pair(abs(cc - jj), make_pair(cc, jj)))
            ans1 = cntc, ans2 = cntj;
        return;
    }
    if (flag == 1) //c greater
    {
        if (c[i] == '?')
            cntc[i] = '0';
        if (j[i] == '?')
            cntj[i] = '9';
        gen(i + 1, flag);
        cntc[i] = c[i], cntj[i] = j[i];
    }
    else if (flag == -1) //c less
    {
        if (c[i] == '?')
            cntc[i] = '9';
        if (j[i] == '?')
            cntj[i] = '0';
        gen(i + 1, flag);
        cntc[i] = c[i], cntj[i] = j[i];
    }
    else
    {
        if (c[i] == '?' && j[i] == '?')
        {
            cntc[i] = '0', cntj[i] = '0';
            gen(i + 1, flag);
            cntc[i] = '1', cntj[i] = '0';
            gen(i + 1, 1);
            cntc[i] = '0', cntj[i] = '1';
            gen(i + 1, -1);
        }
        else if (c[i] == '?')
        {
            if (j[i] != '0')
                cntc[i] = j[i] - 1, gen(i + 1, -1);
            if (j[i] != '9')
                cntc[i] = j[i] + 1, gen(i + 1, 1);
            cntc[i] = j[i];
            gen(i + 1, 0);
        }
        else if (j[i] == '?')
        {
            if (c[i] != '0')
                cntj[i] = c[i] - 1, gen(i + 1, 1);
            if (c[i] != '9')
                cntj[i] = c[i] + 1, gen(i + 1, -1);
            cntj[i] = c[i];
            gen(i + 1, 0);
        }
        else
        {
            int nxt = 0;
            if (c[i] > j[i])
                nxt = 1;
            if (c[i] < j[i])
                nxt = -1;
            gen(i + 1, nxt);
        }
    }
}



int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int t;
    cin >> t;
    string one, two;
    for (int q = 1; q <= t; ++q)
    {
        cin >> one >> two;
        n = one.size();
        c.clear();
        j.clear();
        cntc.clear();
        cntj.clear();
        for (int i = 0; i < n; ++i)
            c.push_back(one[i]), j.push_back(two[i]);
        cntc = c, cntj = j;
        was = false;
        gen(0, 0);
        cout << "Case #" << q << ": ";
        for (int i = 0; i < n; ++i)
            cout << ans1[i];
        cout << ' ';
        for (int i = 0; i < n; ++i)
            cout << ans2[i];

        cout << "\n";
    }
}
