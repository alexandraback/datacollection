#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int v[300],i,t;
string s;
string l[10]={"ZERO","ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector <int> a;

int main()
{
    ifstream f("in.txt");
    ofstream g("out.txt");
    f >> t;
    for (int w=1;w<=t;w++)
    {
        g << "Case #" << w << ": ";
        f >> s;
        a.resize(0);
        for (i='A';i<='Z';i++)
            v[i]=0;
        for (i=0;i<s.size();i++)
            v[s[i]]++;
        while (v['Z']>0)
        {
            for (i=0;i<l[0].size();i++)
                v[l[0][i]]--;
            a.push_back(0);
        }
        while (v['W']>0)
        {
            for (i=0;i<l[2].size();i++)
                v[l[2][i]]--;
            a.push_back(2);
        }
        while (v['X']>0)
        {
            for (i=0;i<l[6].size();i++)
                v[l[6][i]]--;
            a.push_back(6);
        }
        while (v['S']>0)
        {
            for (i=0;i<l[7].size();i++)
                v[l[7][i]]--;
            a.push_back(7);
        }
        while (v['V']>0)
        {
            for (i=0;i<l[5].size();i++)
                v[l[5][i]]--;
            a.push_back(5);
        }
        while (v['F']>0)
        {
            for (i=0;i<l[4].size();i++)
                v[l[4][i]]--;
            a.push_back(4);
        }
        while (v['R']>0)
        {
            for (i=0;i<l[3].size();i++)
                v[l[3][i]]--;
            a.push_back(3);
        }
        while (v['H']>0)
        {
            for (i=0;i<l[8].size();i++)
                v[l[8][i]]--;
            a.push_back(8);
        }
        while (v['I']>0)
        {
            for (i=0;i<l[9].size();i++)
                v[l[9][i]]--;
            a.push_back(9);
        }
        while (v['N']>0)
        {
            for (i=0;i<l[1].size();i++)
                v[l[1][i]]--;
            a.push_back(1);
        }
        sort(a.begin(),a.end());
        for (i=0;i<a.size();i++)
            g << a[i];
        g << "\n";
    }
    return 0;
}
