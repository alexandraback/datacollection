#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("A-large.in");
    ofstream out("A-large.out");
    int t;
    in >> t;
    for(int caso = 1; caso <= t; caso++)
    {
        long long int n;
        long long int molt = 0;
        in >> n;
        if(n == 0)
        {
            out << "Case #" << caso << ": INSOMNIA" << endl;
            continue;
        }
        vector<bool> v(10, false);
        while(count(v.begin(), v.end(), true) != 10)
        {
            molt++;
            string tmp = to_string(n * molt);
            for(auto& i: tmp)
            {
                v[i - '0'] = true;
            }
        }
        out << "Case #" << caso << ": " << n * molt << endl;
    }
    return 0;
}
