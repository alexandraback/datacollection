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
    //vector<bool>
    int n;
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
    long long solve()
    {
        long long ret = 0;
        int len = name.length();
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + n; j <= len; ++j)
            {
                if (check(name.substr(i, j-i), n))
                    ++ret;
            }
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