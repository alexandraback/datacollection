#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("C-small-2-attempt0.in");
ofstream out("C_out.out");
int T;
int R,n,m,k;

int main()
{
    in >> T;
    in >> R >> n >> m >> k;
    out << "Case #1:\n";
    for (int i = 0; i < R; ++i)
    {
        vector<int> v(k);
        for (int j = 0; j < k; ++j)
            in >> v[j];
        vector<int> sol;
        for (int j = 0; j < k; ++j)
        {
            if (v[j] == 1) continue;
            for (int i2 = 0; i2 < sol.size(); ++i2)
                v[j] /= sol[i2];
            if (v[j])
            for (int i2 = m; i2 > 1; --i2)
                while(v[j]%i2 == 0)
                {
                    v[j]/=i2;
                    sol.push_back(i2);
                }
        }
        bool b = 1;
        while (sol.size() < n && b)
        {
            b = 0;
            for (int j = 0; j < sol.size(); ++j)
            if (sol[j] == 4) {
                sol.erase(sol.begin()+j);
                sol.push_back(2); sol.push_back(2);
                b = 1;
                if (sol.size() == n) break;
            }
            else if (sol[j] == 6) {
                sol.erase(sol.begin()+j);
                sol.push_back(2); sol.push_back(3);
                b = 1;
                if (sol.size() == n) break;
            }
            else if (sol[j] == 8) {
                sol.erase(sol.begin()+j);
                sol.push_back(2); sol.push_back(4);
                b = 1;
                if (sol.size() == n) break;
            }
        }
        while (sol.size() < n)
            sol.push_back(2);
        for (int j = 0; j < n; ++j)
            out << sol[j];
        out << '\n';
    }
    return 0;
}
