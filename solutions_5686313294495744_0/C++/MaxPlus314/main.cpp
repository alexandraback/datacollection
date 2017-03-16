#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#define pb push_back

using namespace std;

const int N = 2001;

string s1, s2;
map<string, int> m1, m2;
vector<int> nei[N];
int m, u[N], ch[N];

bool tr(int v)
{
    if (u[v])
        return 0;
    u[v] = 1;
    for (auto i: nei[v])
        if (!ch[i] || tr(ch[i]))
            return ch[i] = v, 1;
    return 0;
}

int main()
{
    ifstream cin("C-small-attempt0.in");
    ofstream cout("ans");
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        m1.clear(), m2.clear();
        memset(ch, 0, sizeof(ch));
        for (auto &i: nei)
            i.clear();
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> s1 >> s2;
            if (!m1[s1])
                m1[s1] = m1.size();
            if (!m2[s2])
                m2[s2] = m2.size();
            nei[m1[s1]].pb(m2[s2]);
        }
        for (int i = 1; i <= m1.size(); ++i)
            memset(u, 0, sizeof(u)), tr(i);
        int amf = 0;
        for (int i = 1; i <= m2.size(); ++i)
            amf += !!ch[i];
        cout << "Case #" << i + 1 << ": " << m - (m1.size() + m2.size() - amf) << '\n';
    }
    return 0;
}
