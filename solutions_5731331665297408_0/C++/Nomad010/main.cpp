#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <cassert>

using namespace std;

vector<string> zips;
vector< pair< string, int> > sorted_zips;
vector<int> city_to_lex;
vector< set<int> > edges;

int N, M;

// long long solve(set<int>& visited, vector<int>& stk, long long current)
string solve(set<int>& visited, vector<int>& stk, string current)
{
//     long long new_current = current*10 + (city_to_lex[stk.back()] + 1);
    string new_current = current + zips[stk.back()];
    
//     cout << "FKJSDJSDSJDL " << stk.back() << endl;
    if(visited.size() == N - 1)
    {
        return new_current;
    }
    else
    {
        visited.insert(stk.back());
        
//         long long best = 999999999999999LL;
        string best = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    
        vector<int> new_stk;
        
        for(int i = 0; i < int(stk.size()); ++i)
        {
            new_stk.push_back(stk[i]);
            int node = new_stk.back();
            
            for(set<int>::iterator it = edges[node].begin(); it != edges[node].end(); ++it)
            {
                int to = *it;
                if(visited.count(to))
                    continue;
                
                int old_sz = new_stk.size();
                new_stk.push_back(to);
//                 long long sc = solve(visited, new_stk, new_current);
                string sc = solve(visited, new_stk, new_current);
                new_stk.pop_back();
                if(sc < best)
                    best = sc;
            }
        }
        
        visited.erase(stk.back());
//         cout << "\t\tBEST " << best << endl;
        return best;
    }
}

int main(int argc, char** argv)
{
    int T = 0;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        cin >> N >> M >> ws;
        zips.resize(N);
        sorted_zips.resize(N);
        city_to_lex.resize(N);
        edges.clear();
        edges.resize(N);
        
        for(int i = 0; i < N; ++i)
        {
            cin >> zips[i] >> ws;
            sorted_zips[i] = make_pair(zips[i], i);
        }
        sort(sorted_zips.begin(), sorted_zips.end());
        for(int i = 0; i < N; ++i)
            city_to_lex[sorted_zips[i].second] = i;
        
        for(int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b >> ws;
            --a; --b;
            edges[a].insert(b);
            edges[b].insert(a);
        }
        
        set<int> visited;
//         long long best = 999999999999999LL;
        string best = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
        for(int i = 0; i < N; ++i)
        {
            vector<int> stk;
            stk.push_back(i);
//             long long sc = solve(visited, stk, 0);
            string sc = solve(visited, stk, "");
//             cout << "ROFL: " << i << " " << sc << endl;
            if(sc < best)
                best = sc;
        }
//         cout << best << endl;
        
//         string comb = "";
//         vector<int> bl;
//         for(int i = 0; i < N; ++i)
//         {
//             int dig = best % 10;
//             best /= 10;
//             bl.push_back(dig - 1);
//         }
//         for(int i = N - 1; i >= 0; --i)
//             comb += sorted_zips[i].first;
//         cout << best << endl;
        
        
        cout << "Case #" << t << ": " << best << endl;
        
    }
    return 0;
}