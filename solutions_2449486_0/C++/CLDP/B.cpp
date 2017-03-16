#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int v, a, b;     
};

bool compare(const node &a, const node &b) {
    return a.v < b.v;     
}

int n, m;
int x[101][101], y[101][101], z[101];


int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int tt;
    cin >> tt;
    vector<node> input;
    for (int ttt = 1; ttt <= tt; ++ttt) {
        input.clear();
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j) {
             cin >> x[i][j];
             node pp;
             pp.v = x[i][j];
             pp.a = i;
             pp.b = j;
             input.push_back(pp);
         }
        
        for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j) y[i][j] = 100;
        
        sort(input.begin(), input.end(), compare);
        
        bool ans = true;
        
        for (int i = 0; i < input.size(); ++i) {
            for (int j = 0; j < m; ++j) {
                z[j] = y[input[i].a][j];
                if (y[input[i].a][j] > input[i].v) {
                    y[input[i].a][j] = input[i].v;
                }
            }
            bool temp_flag = true;
            for (int j = 0; j < m; ++j) {
                if (y[input[i].a][j] < x[input[i].a][j]) {
                    temp_flag = false;
                    break;                     
                }
            }
            if (temp_flag) continue;
            for (int j = 0; j < m; ++j) y[input[i].a][j] = z[j];
            
            for (int j = 0; j < n; ++j) {
                z[j] = y[j][input[i].b];
                if (y[j][input[i].b] > input[i].v) {
                    y[j][input[i].b] = input[i].v;
                }
            }
            temp_flag = true;
            for (int j = 0; j < n; ++j) {
                if (y[j][input[i].b] < x[j][input[i].b]) {
                    temp_flag = false;
                    break;                     
                }
            }
            if (temp_flag) continue;
            ans = false;
            break;
        }
        cout << "Case #" << ttt << ": ";
        if (ans) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    
    return 0;    
}
