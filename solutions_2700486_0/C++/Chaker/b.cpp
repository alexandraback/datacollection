#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define pb push_back
#define sz(v) (int(v.size()))
#define mp make_pair

const int x0 = 50;
int height[2 * x0 + 10000];

double prob[25][2 * x0 + 100][2 * x0 + 100];

inline void add_rock(int mode) 
{
    int x = x0;
    if (mode == 0) {
        while (height[x - 1] < height[x]) {
            --x;
        }
    }
    if (mode == 1) {
        while (height[x + 1] < height[x]) {
            ++x;
        }
    }
    while (height[x + 1] < height[x]) {
        ++x;
    }
    while (height[x - 1] < height[x]) {
        --x;
    }
    //cerr << "fixed at " << x << endl;
    height[x - 1] = height[x + 1] = height[x] + 1;
    height[x] += 2;
}

void calc(int n)
{   
    cerr << n << endl;
    //cerr << n << " " << x << " " << y << endl;
    //x += x0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        //cerr << "mask = " << mask << endl;
        for (int i = 0; i < 2 * x0 + 10; ++i) {
            height[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            add_rock(mask & (1 << i));
        }
        for (int x = 0; x < 2 * x0; ++x) {
            for (int y = 0; y < height[x]; ++y) {
                prob[n][x][y] += 1;
            }
        }
        /*
        for (int x = x0 - 3; x <= x0 + 3; ++x) {
            cerr << height[x] << " ";
        }
        */
        //cerr << endl;
    }
    for (int x = 0; x < 2 * x0; ++x) {
        for (int y = 0; y < x0 + 10; ++y) {
            prob[n][x][y] /= (1 << n);
        }
    }
    //return cnt / double(1 << n);
}

int main()
{
    int TEST = 0;
    cin >> TEST;
    for (int n = 0; n <= 20; ++n) {
        calc(n);
    }
    for (int test = 1; test <= TEST; ++test) {
        cout << "Case #" << test <<": ";
        int n,x,y;
        cin >> n >> x >> y;
        if (x > x0 || y > x0 || x < -x0) {
            cout << 0 << endl;
        } else {
            printf("%.10lf\n", prob[n][x + x0][y]);    
        }
    }
    return 0;
}