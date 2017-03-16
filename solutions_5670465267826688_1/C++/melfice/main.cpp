#include <bits/stdc++.h>

using namespace std;

#define int int64_t

string tab[8] = {
"1ijk!IJK",
"i!kJI1Kj",
"jK!iJk1I",
"kjI!KJi1",
"!IJK1ijk",
"I1Kji!kJ",
"Jk1IjK!i",
"KJi1kjI!",
};

string inv1 = "1ijk!IJK";
string inv2 = "1IJK!ijk";

main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        int l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        map<char, map<char, char>> C;
        map<char, char> inv;
        for(int i = 0; i < 8; i++)
            inv[inv1[i]] = inv2[i];
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                C[tab[i][0]][tab[0][j]] = tab[i][j];
        char P = '1';
        for(auto c: s)
            P = C[P][c];
        /*
        i = P^i * pre1
        j = suf1 * P^j * pre2
        k = suf2 * P^k
        i + j + k == x - 2
        */
        int n = s.size();
        set<pair<char, char>> presuf;
        char pre[n + 2];
        char suf[n + 2];
        pre[0] = suf[n + 1] = '1';
        for(int i = 1; i <= n; i++)
            pre[i] = C[pre[i - 1]][s[i - 1]],
            suf[n - i + 1] = C[s[n - i]][suf[n - i + 2]];
        for(int i = 1; i <= n + 1; i++)
            presuf.insert({pre[i - 1], suf[i]});
        string pows = "1";
        char t = P;
        for(int i = 0; i < 16; i++)
        {
            if(t == '1')
                break;
            pows += t;
            t = C[t][P];
        }
        set<tuple<char, char, char>> middle;
        set<char> preff;
        for(int i = 0; i < pows.size(); i++)
            for(int j = 0; j < pows.size(); j++)
                for(int k = 0; k < pows.size(); k++)
                    for(auto it1: presuf)
                        for(auto it2: presuf)
                        {
                            if(i + j + k + 2 > x)
                                continue;
                            if(C[pows[i]][it1.first] == 'i' && C[C[it1.second][pows[j]]][it2.first] == 'j' && C[it2.second][pows[k]] == 'k')
                            {
                                if((i + j + k) % pows.size() == (x - 2) % pows.size())
                                {
                                    cout << "YES\n";
                                    goto nxt;
                                }
                            }
                        }
        for(int i = 1; i <= n + 1; i++)
        {
            for(auto it: preff)
                middle.insert(make_tuple(it, C[C[inv[it]][P]][inv[suf[i]]], suf[i]));
            preff.insert(pre[i - 1]);
        }

        for(int i = 0; i < pows.size(); i++)
                for(int k = 0; k < pows.size(); k++)
                    for(auto it: middle)
                        {
                            if(i + k + 1 > x)
                                continue;
                            if(C[pows[i]][get<0>(it)] == 'i' && get<1>(it) == 'j' && C[get<2>(it)][pows[k]] == 'k')
                            {
                                if((i + k) % pows.size() == (x - 1) % pows.size())
                                {
                                    cout << "YES\n";
                                    goto nxt;
                                }
                            }
                        }
        cout << "NO\n";
        nxt:;
    }

}
