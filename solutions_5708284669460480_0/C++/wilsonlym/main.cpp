#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int num[26], arr[10], f[10];
vector<int> types;
int K, L, S, s1, s2, total;

void dfs(int x)
{
    if (x == S)
    {
        total++;
        int res = 0;
        for (int i = 0; i <= S - L; i++)
        {
            bool flag = true;
            for (int j = 0; j < L; j++)
                if (f[i + j] != arr[j])
                {
                    flag = false;
                    break;
                }
            if (flag) res++;
        }
        s1 = max(s1, res);
        s2 += res;
        return;
    }
    for (int i = 0; i < (int)types.size(); i++)
    {
        f[x] = types[i];
        dfs(x + 1);
    }
}

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d%d", &K, &L, &S);
        types.clear();
        for (int i = 0; i < K; i++)
        {
            char ch;
            scanf(" %c", &ch);
            num[ch - 'A']++;
            types.push_back(ch - 'A');
        }
        for (int i = 0; i < L; i++)
        {
            char ch;
            scanf(" %c", &ch);
            arr[i] = ch - 'A';
        }
        s1 = s2 = total = 0;
        dfs(0);
//        cout<<total<<" "<<s1<<" "<<s2<<endl;
        double ans = s1 - (double)s2 / total;
        printf("Case #%d: %.8f\n", cas, ans);
    }
    return 0;
}
