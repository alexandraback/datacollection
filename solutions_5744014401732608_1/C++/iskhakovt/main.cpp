#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cassert>

using namespace std;

typedef unsigned long long ull;

void swap_to_zero(vector<vector<bool> > &solution, int idx) {
    for (vector<bool> &row : solution) {
        swap(row[0], row[idx]);
    }
}

bool solve(vector<vector<bool> > &solution, int n, ull m) {
    solution = vector<vector<bool>>(n, vector<bool>(n, false));
    
    for (int i = 1; i != n; ++i) {
        for (int j = i + 1; j != n; ++j) {
            solution[i][j] = true;
        }
    }
    
    
    for (int i = 1; i != n; ++i) {
        ull pow;
        if (i == n - 1) {
            pow = 1;
        } else {
            pow = (1ULL << (ull)(n - i - 2));
        }
        if (pow <= m) {
            m -= pow;
            solution[0][i] = true;
        }
    }
    
    return m == 0;
    
    /*
    
    for (int i = n - 2; i >= 0; --i) {
        ull pow = 1;
        
        for (int j = n - 1; j != i; --j) {
            if (pow > m) {
                if (m == 0) return true;
                
                solution[i].assign(n, false);
                solution[i][j] = true;
                
                m -= 1;
                for (int k = i + 1; k != n; ++k) {
                    pow /= 2;
                    if (pow <= m) {
                        m -= pow;
                        solution[i][k] = true;
                    }
                }
                
                swap_to_zero(solution, i);
                return true;
            } else {
                pow -= m;
                solution[i][j] = true;
            }
            
            pow *= 2;
        }
    }
    
    return m == 0;
    */
}

ull dfs(int v, vector<ull> &cnt, vector<vector<bool> > &solution) {
    if (cnt[v] != ULLONG_MAX) {
        return cnt[v];
    }
    
    if (v == cnt.size() - 1) {
        return cnt[v] = 1;
    }
    
    cnt[v] = 0;
    for (int i = 0; i != solution.size(); ++i) {
        if (solution[v][i]) {
            cnt[v] += dfs(i, cnt, solution);
        }
    }
    return cnt[v];
}

ull check(vector<vector<bool> > &solution) {
    vector<ull> cnt(solution.size(), ULLONG_MAX);
    return dfs(0, cnt, solution);
}

int main() {
    int tests;
    cin >> tests;
    
    for (int test = 0; test != tests; ++test) {
        int n;
        ull m;
        cin >> n >> m;
        
        vector<vector<bool> > sol;
        bool res = solve(sol, n, m);
        
        
        if (res) {
            if (check(sol) != m) {
                cout << "Case #" << test + 1 << " FAIL != " << check(sol) << ' ' << m << '\n';
            }
        
            cout << "Case #" << test + 1 << ": POSSIBLE\n";
            for (int i = 0; i != n; ++i) {
                for (int j = 0; j != n; ++j) {
                    cout << (sol[i][j] ? '1' : '0');
                }
                cout << '\n';
            }
        } else {
            sol = vector<vector<bool>>(n, vector<bool>(n, false));
            for (int i = 0; i != n; ++i) {
                for (int j = i + 1; j != n; ++j) {
                    sol[i][j] = true;
                }
            }
            
            if (check(sol) >= m) {
                cout << "Case #" << test + 1 << " FAIL >= " << check(sol) << ' ' << m << '\n';
            }
            
            cout << "Case #" << test + 1 << ": IMPOSSIBLE\n";
        }
        
    }
    
    return 0;
}