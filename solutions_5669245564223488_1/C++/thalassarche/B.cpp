#include <algorithm>
#include <iostream>
#include <vector>

#include <cassert>

#define mod 1000000007

using namespace std;

long long fac(long long n)
{
    long long r = 1;
    for (long long i = 2; i <= n; ++i) r = (r * i) % mod;
    return r;
}

bool test(const string& s)
{
    if (!s.size()) return true;
    vector<char> b(256, false);
    b[s[0]] = true;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1] && b[s[i]]) return false;
        else b[s[i]] = true;
    }
    return true;
}

vector<vector<string>> find_c(const vector<string>& v)
{
    vector<vector<string>> result;
    vector<char> used(v.size(), false);
    for (int i = 0; i < v.size(); ++i) {
        if (used[i]) continue;
        used[i] = true;
        vector<string> s;
        s.push_back(v[i]);
        vector<char> c(256, false);
        for (char x: v[i]) c[x] = true;
        
        bool changed = true;
        while (changed) {
            changed = false;
            for (int j = 0; j < v.size(); ++j) {
                for (char x: v[j]) if (!used[j] && c[x]) {
                    changed = true;
                    used[j] = true;
                    s.push_back(v[j]);
                    for (char y: v[j]) c[y] = true;
                }
            }
        }
        
        result.push_back(move(s));
    }
    
    return result;
}

long long find_cnt(vector<string> v)
{
    const int n = v.size();
    vector<int> start(256, -1);
    vector<int> end(256, -1);
    vector<vector<int> > all(256);
    
    for (int i = 0; i < n; ++i) {
        string& s = v[i];
        bool b = true;
        char c = s.front();
        for (char x: s) if (x != c) b = false;
        if (b) all[s.front()].push_back(i);
        else {
            if (start[s.front()] >= 0 || end[s.back()] >= 0) {
                return 0;
            }
            start[s.front()] = i;
            end[s.back()] = i;
        }
    }
    
    long long cnt = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        if ((start[i] < 0 && all[i].size() == 0) || end[i] >= 0) continue;
        
        string r;
        long long c = 1;
        
        char current = i;
        int used = 0;
        vector<char> is_used(n, false);
        bool possible = true;
        while (used < n) {
            if ((!current) || (start[current] < 0 && all[current].size() == 0) || (start[current] >= 0 && is_used[start[current]])) {
                possible = false;
                break;
            }
            
            char next = 0;
            if (start[current] >= 0) {
                const string& s = v[start[current]];
                is_used[start[current]] = true;
                r.append(s);
                next = s.back();
            }
            
            c *= fac(all[current].size());
            c %= mod;
            used += all[current].size();
            
            current = next;
            ++used;
        }
        if (!possible || !test(r)) continue;
        else cnt += c;
    }
    return cnt % mod;
}

void solve()
{
    int n; 
    
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    long long cnt = 1;
    vector<vector<string> > s = find_c(v);
    for (vector<string>& x: s) cnt = (cnt * find_cnt(x)) % mod;
    cnt = (cnt * fac(s.size())) % mod;
    
    cout << cnt << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
