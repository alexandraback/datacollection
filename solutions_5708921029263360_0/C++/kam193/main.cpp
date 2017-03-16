#include <iostream>
#include <vector>

using namespace std;

struct ub
{
    int j, p, s;
};
vector<vector<int> > JP, JS, PS;
vector<ub> dni;


int main()
{
    int T;
    cin >> T;

    int J, P, S, K;
    int ile;
    for(int t = 1; t <= T; ++t)
    {
        cin >> J >> P >> S >> K;
        ile = 0;
        dni.clear();

        JP.clear();
        JS.clear();
        PS.clear();

        JP.resize(J);
        for (auto &x : JP)
            x.resize(P, 0);

        JS.resize(J);
        for(auto &x: JS)
            x.resize(S, 0);

        PS.resize(P);
        for(auto &x : PS)
            x.resize(S, 0);

        for (int s = 0; s < S; ++s)
        {
            for (int p = 0; p < P; ++p)
            {
                    for(int j = 0; j < J; ++j)
                    {
                        if (JS[j][s] < K && PS[p][s] < K && JP[j][p] < K)
                        {
                            ub u;
                            u.j = j;
                            u.p = p;
                            u.s = s;
                            ++ile;
                            ++JP[j][p];
                            ++JS[j][s];
                            ++PS[p][s];
                            dni.push_back(u);
                        }
                    }
            }
        }

        cout << "Case #" << t << ": " << ile << endl;
        //cout << J << " " << P << " " << S << " " << K << endl;
        for (auto x : dni)
        {
            cout << x.j + 1 << " " << x.p + 1 << " " << x.s + 1 << endl;
        }
    }

    return 0;
}
