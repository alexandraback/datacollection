#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

int n, num, cnt;
long long a, b;

bool judge(long long tmp)
{
    stringstream s;
    s << tmp;
    string a;
    s >> a;
    string b = a;
    reverse(a.begin(), a.end());
    
    if (a == b)
        return true;
    else
        return false;
}

void solve()
{
    long long bgn = sqrt(a - 1) + 1;
    long long end = sqrt(b);
    long long tmp;
    for (long long i = bgn; i <= end; i++)
    {
        if (judge(i))
        {
            tmp = i * i;
            if (judge(tmp))
                cnt++;
        }
    }
}

int main()
{
    num = 0;
    ifstream fin("C-small-attempt0.in");
    ofstream fout("output.txt");
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        fin >> a >> b;
        solve();
        num++;
        fout << "Case #" << num << ": " << cnt << endl; 
    }

    return 0;
}
