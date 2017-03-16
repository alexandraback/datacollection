#include <fstream>
using namespace std;
ifstream ka("B-small-attempt0.in");
ofstream ki("ceva.out");
int t, gasite, unde[10], minim;
string a, b, sol1, sol2;

void back(int t)
{
    if(t > gasite)
    {
        int nr = 0;
        for(int j = 0; j < a.size(); j++)
            nr = nr * 10 + a[j] - '0';
        int nr2 = 0;
        for(int j = 0; j < b.size(); j++)
            nr2 = nr2 * 10 + b[j] - '0';
        if(abs(nr - nr2) < minim)
        {
            minim = abs(nr - nr2);
            sol1 = a;
            sol2 = b;
        }
    }
    else
    {
        for(int i = 0; i <= 9; i++)
        {
            if(unde[t] < 4)
                a[unde[t]] = i + '0';
            else
                b[unde[t] - 4] = i + '0';
            back(t + 1);
        }
    }
}

int main()
{
    ka >> t;
    for(int i = 1; i <= t; i++)
    {
        ka >> a >> b;
        minim = 0x7fffffff;
        gasite = 0;
        for(int j = 0; j < a.size(); j++)
            if(a[j] == '?')
                unde[++gasite] = j;
        for(int j = 0; j < b.size(); j++)
            if(b[j] == '?')
                unde[++gasite] = j + 4;
        back(1);
        ki << "Case #" << i << ": " << sol1 << " " << sol2 << '\n';
    }
}
