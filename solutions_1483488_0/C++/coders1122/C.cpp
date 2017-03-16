#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair

typedef pair<int, int> PII;
typedef pair<int, PII> triple;
typedef long long LL;
#define MAXN 2000001
vector<int> V[MAXN];
inline void pre_compute()
{
    int A = 1, B = 2000000;
    for(int i=A;i<=B;i++)
    {
        char buf[10];
        sprintf(buf, "%d", i);
        string s(buf);
        set<int> Set;
        for(int x=1;x<s.length();x++)
        {
            string pre = s.substr(0, x);
            string suf = s.substr(x);
            string ss = suf + pre;
            int j;
            sscanf(ss.c_str(), "%d", &j);
            if(i < j)
            Set.insert(j);
        }
        set<int>::iterator it;
        for(it=Set.begin();it!=Set.end();it++)
        {
            V[i].push_back(*it);
        }
    }

}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    pre_compute();
    int T;
    // T = 50;
    cin >> T;
    for(int cases=1;cases<=T;cases++)
    {
        int A, B;
        cin >> A >> B;
        // A = 1, B = 2000000;
        int ret = 0;

        for(int i=A;i<=B;i++)
        {
            int tmp = (int)(upper_bound(V[i].begin(), V[i].end(), B) - V[i].begin());
            ret += tmp;
        }

        cout << "Case #" << cases << ": " << ret << endl;
    }

    return 0;
}
