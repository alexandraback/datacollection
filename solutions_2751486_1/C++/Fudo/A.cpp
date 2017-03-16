#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

using namespace std;

char vowels[6] = "aeiou";
struct GCase
{
    //int a;
    string name;
    vector<bool> cvt;
    int n;
    vector<string> ssss1;
    vector<string> ssss2;
    bool check(const string & s, int n)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            bool b = false;
            for (int j = 0; j < 5; ++j)
                if (s[i] == vowels[j])
                {
                    b = true;
                    break;
                }
            if (b)
                sum = 0;
            else
                ++sum;
            if (sum >= n)
                return true;
        }
        return false;
    }
    bool checkV(char s)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (s == vowels[j])
                return true;
        }
        return false;
    }

    long long solve()
    {
        long long ret = 0;
        int len = name.length();
        for (int i = 0; i < len; ++i)
        {
            if (checkV(name[i]))
                cvt.push_back(false);
            else
                cvt.push_back(true);
        }

        int lst = 0;
        for (; lst < len; )
        {
            int s = 0;
            int k = 0;
            int st = lst;
            for (int j = lst; j < len; ++j)
            {
                if (cvt[j])
                    s++;
                else
                    s = 0;
                // count
                if (s >= n)
                {
                    st = j;
                    // find last
                    k = j + 1;
                    for (; k < len; ++k)
                        if (!cvt[k])
                            break;
                    break;
                }
            }
            if (k == 0)
                break;
            if (k <= len)
            {
                int ed = k - n;
                //long x = ed - lst + 1;
                //long y = len - st;
                //int nn = ed - st + 1;
                //int m = 0;
                //if (nn > 0)
                //    m = nn * (nn + 1)/2;
                //for ()
                //ret += x * y - m;

                for (int ii = lst; ii <= ed; ++ii)
                {
                    int mm = max(ii+n-1, st);
                    ret += (len - mm);
                }
            }
            lst = k-n+1;
        }
        return ret;
    }
};

int g_nCases = 0;
vector<GCase*> g_cases;

void read_input()
{
    cin >> g_nCases;
    for (int i = 0; i < g_nCases; ++i)
    {
        GCase* gc = new GCase;
        // do sth
        cin >> gc->name;
        cin >> gc->n;
        g_cases.push_back(gc);
    }
}

int main(int argc, char**argv)
{
    read_input();

    for (int i = 0; i < g_nCases; ++i)
    {
        cout << "Case #" << i+1 << ": " << g_cases[i]->solve();
        cout << endl;
    }
    return 0;
}