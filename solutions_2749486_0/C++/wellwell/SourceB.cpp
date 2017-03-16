#define _USE_MATH_DEFINES

#include <vector>
#include <iostream>
#include <functional>
#include <sstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define SQR(x)  (x) * (x)

int f(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    string tmp;
    cin >> tc;
    getline(cin, tmp);
    set<char> v;
    v.insert('a');
    v.insert('e');
    v.insert('o');
    v.insert('i');
    v.insert('u');

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'W', 'E', 'S', 'N'};

    for(int t_ = 1; t_ <= tc; t_++) {        
        cout << "Case #" << t_ << ": ";
        int x, y;
        cin >> x >> y;
        int nx, px = 1, ny, py = 3;
        if (x < 0) px = 0;
        if (y < 0) py = 2;

        if (x < y) {
            double tmp = (-1 + sqrt(1 + 8 * 1.0 * abs(x))) / 2;
            nx = floor(tmp);

            for(int i = 0; i < nx; i++) 
                cout << dir[px];

            tmp = (-(2 * nx + 1) + sqrt(SQR(2 * nx + 1) + 8 * 1.0 * abs(y))) / 2;
            ny = floor(tmp);

            for(int i = 0; i < ny; i++) 
                cout << dir[py];

            
            for(int i = abs(x); i > f(1, nx); i--) {
                int px_ = x < 0 ? 1 : 0;
                cout << dir[px_] << dir[px];
            }

            for(int i = abs(y); i > f(nx + 1, nx + ny); i--) {
                int py_ = y < 0 ? 3 : 2;
                cout << dir[py_] << dir[py];
            }


        }
        else {
            double tmp = (-1 + sqrt(1 + 8 * 1.0 * abs(y))) / 2;
            nx = floor(tmp);

            for(int i = 0; i < nx; i++) 
                cout << dir[py];

            tmp = (-(2 * nx + 1) + sqrt(SQR(2 * nx + 1) + 8 * 1.0 * abs(x))) / 2;
            ny = floor(tmp);

            for(int i = 0; i < ny; i++) 
                cout << dir[px];

            
            for(int i = abs(y); i > f(1, nx); i--) {
                int py_ = y < 0 ? 3 : 2;
                cout << dir[py_] << dir[py];
            }

            for(int i = abs(x); i > f(nx + 1, nx + ny); i--) {
                int px_ = x < 0 ? 1 : 0;
                cout << dir[px_] << dir[px];
            }
        }

        

            
        cout << endl;
    }

}
