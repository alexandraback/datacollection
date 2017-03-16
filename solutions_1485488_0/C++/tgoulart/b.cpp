#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#define DEBUG
#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) 
#endif

#define WATER_RATE 10.0
#define MAX 105
#define INF 1e10
#define EPS 1e-9

int cmp(double a, double b) {
    return (a+EPS < b) ? -1 : (a-EPS > b);
}
    
struct State {
    int i, j;
    double time;
    
    State (int a, int b, double c) {
        i = a, j = b, time = c;
    }
    
    bool operator <(const State &s) const {
        if (cmp(time, s.time) != 0) return time < s.time;
        if (i != s.i) return i > s.i;
        return j > s.j;
    }
};

int CEILING[MAX][MAX], FLOOR[MAX][MAX];
bool visited[MAX][MAX];

void solve(int id) {
    printf("Case #%d: ", id);
    double h;
    int n, m;
    
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    
    scanf("%lf %d %d\n", &h, &n, &m);
    
    for (int i=0; i < n; ++i) {
        for (int j=0; j < m; ++j) {
            scanf("%d", &CEILING[i][j]);
        }
    }
    for (int i=0; i < n; ++i) {
        for (int j=0; j < m; ++j) {
            scanf("%d", &FLOOR[i][j]);
        }
    }
    
    set <State> partial, table;
    partial.insert(State(0, 0, 0.0));
    
    memset(visited, false, sizeof(visited));
    visited[0][0] = true;
    
    while (!partial.empty()) {
        State s = *partial.begin(); partial.erase(partial.begin());
        
        if (s.i == n-1 && s.j == m-1) {
            printf("%.9lf\n", 0.0);
            return;
        }
        
        table.insert(State(s.i, s.j, 0.0));
        
        for (int k=0; k < 4; ++k) {
            int i = s.i + di[k];
            int j = s.j + dj[k];
            
            if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
                continue;
            }
            
            if (CEILING[i][j] - h < 50 || CEILING[i][j] - FLOOR[i][j] < 50 || CEILING[s.i][s.j] - FLOOR[i][j] < 50 || CEILING[i][j] - FLOOR[s.i][s.j] < 50) {
                continue;
            }
            
            partial.insert(State(i, j, 0.0));
            visited[i][j] = true;
        }

    }
    
    memset(visited, false, sizeof(visited));
    
    while (!table.empty()) {
        State s = *table.begin(); table.erase(table.begin());
        
        if (visited[s.i][s.j]) {
            continue;
        }
        
        visited[s.i][s.j] = true;
        
        if (s.i == n-1 && s.j == m-1) {
            printf("%.9lf\n", s.time);
            return;
        }
        
        double water = h - WATER_RATE * s.time;
        
        for (int k=0; k < 4; ++k) {
            int i = s.i + di[k];
            int j = s.j + dj[k];
            
            if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) {
                continue;
            }
            
            if (CEILING[i][j] - FLOOR[i][j] < 50 || CEILING[s.i][s.j] - FLOOR[i][j] < 50 || CEILING[i][j] - FLOOR[s.i][s.j] < 50) {
                continue;
            }
            
            double new_time = s.time;
            
            if (water > CEILING[i][j]-50) {
                new_time += (water - (CEILING[i][j] - 50)) / WATER_RATE;
            }
            
            if (water+EPS > FLOOR[s.i][s.j]+20.0 && FLOOR[s.i][s.j]+20 < CEILING[i][j]-50) {
                // kayak
                new_time += 1.0;
            }
            else {
                // walk
                new_time += 10.0;
            }
            
            table.insert(State(i, j, new_time));
        }
    }
}

int main() {
    int t, T = 1;
    
    scanf("%d ", &t);
    while (t--) {
        solve(T++);
    }
    
    return 0;
}
