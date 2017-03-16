#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

vector<int> match;
vector<vector<int>> edges;
vector<char> used;

bool kuhn(int v)
{
    if (used[v]) return false;
    used[v] = true;
    
    for (int u: edges[v])
        if (match[u] == -1 || kuhn(match[u]))
        {
            match[u] = v;
            return true;
        }
        
    return false;
}

void solve(int testN)
{
    vector<string> left, right;
    vector<pair<string, string>> input;
    
    int n;
    cin >> n;
    
    input.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i].first >> input[i].second;
        left.push_back(input[i].first);
        right.push_back(input[i].second);
    }
    
    sort(all(left));
    left.erase(unique(all(left)), left.end());
    sort(all(right));
    right.erase(unique(all(right)), right.end());
    
    edges.assign(left.size(), vector<int>());
    match.assign(right.size(), -1);
    for (int i = 0; i < n; i++)
    {
        int u = lower_bound(all(left), input[i].first) - left.begin(),
            v = lower_bound(all(right), input[i].second) - right.begin();
            
        edges[u].push_back(v);
        //printf("%d -> %d\n", u, v);
    }
    
    int matchSize = 0;
    for (int i = 0; i < (int)left.size(); i++)
    {
        used.assign(left.size(), false);
        if (kuhn(i))
            matchSize++;
    }
    
    //printf("match %d (%d + %d)\n", matchSize, (int)left.size(), (int)right.size());
    
    int answer = input.size() - (left.size() + right.size() - matchSize);
    printf("Case #%d: %d\n", testN, answer);
}

int main()
{
    int nt;
    cin >> nt;
    
    for (int i = 0; i < nt; i++)
        solve(i + 1);
    
    return 0;
}
