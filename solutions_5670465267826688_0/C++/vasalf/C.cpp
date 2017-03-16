#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct quat
{
    string s;
    bool m;
    quat(string _s, bool _m)
    {
        s = _s;
        m = _m;
    }
    quat() {}
};

quat operator* (const quat& q1, const quat& q2)
{
    int fm = q1.m ? -1 : 1;
    int sm = q2.m ? -1 : 1;
    bool resm = fm * sm < 0 ? true : false;
    string ress;
    if (q1.s == "1")
        ress = q2.s;
    else if (q2.s == "1")
        ress = q1.s;
    else if (q1.s == "i")
    {
        if (q2.s == "i")
        {
            resm = !resm;
            ress = "1";
        }
        else if (q2.s == "j")
            ress = "k";
        else if (q2.s == "k")
        {
            resm = !resm;
            ress = "j";
        }
    }
    else if (q1.s == "j")
    {
        if (q2.s == "i")
        {
            resm = !resm;
            ress = "k";
        }
        else if (q2.s == "j")
        {
            resm = !resm;
            ress = "1";
        }
        else if (q2.s == "k")
            ress = "i";
    }
    else if (q1.s == "k")
    {
        if (q2.s == "i")
            ress = "j";
        else if (q2.s == "j")
        {
            resm = !resm;
            ress = "i";
        }
        else if (q2.s == "k")
        {
            resm = !resm;
            ress = "1";
        }
    }
    return quat(ress, resm);
}

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        vector<quat> qs(l * x);
        for (int i = 0; i < l * x; i++)
            qs[i] = quat(s.substr(i % l, 1), false);
        bool f = false;
        quat q("1", false);
        for (int i = 0; (i < l * x) && (!f); i++)
        {
            q = q * qs[i];
            if (!q.m && q.s == "i")
            {
                quat qqq("1", false);
                for (int j = i + 1; j < l * x; j++)
                    qqq = qqq * qs[j];
                quat qq("1", false);
                for (int j = i + 1; j < l * x - 1 && (!f); j++)
                {
                    qqq = quat(qs[j].s, true) * qqq;
                    qq = qq * qs[j];
                    if (!qq.m && qq.s == "j")
                        if (!qqq.m && qqq.s == "k")
                            f = true;
                }
            }
        }
        cout << "Case #" << test + 1 << ": ";
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
