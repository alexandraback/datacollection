#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void test() {
    std::random_device rd;
    std::mt19937 mt(time(0));
    std::uniform_int_distribution<int> dist(1, 10000);
    int t = 1000;
    for (int i = 1; i <= t; i++) {
        int l = dist(mt) % 8;
        cout << l << "\n";
    }
}

int solve(vector<pair<int,int> > h) {
    if (h.size() < 2) return 0;
    double t1 = (360 - h[0].first) / 360.0 * h[0].second ;
    double t2 = (360 - h[1].first) / 360.0 * h[1].second ;
    if (t1 >= t2 + h[1].second || t2 >= t1 + h[0].second) return 1;
    return 0;
}

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out"); 
    int testCount;
    cin >> testCount;
    for (int testCase = 1; testCase <= testCount; testCase++) {
        int N;
        cin >> N;
        vector< pair<int,int> > h;
        for (int i = 1; i <= N; i++) {
            int D, H, M;
            cin >> D >> H >> M;
            h.push_back(make_pair(D, M));
            for (int j = 1; j < H; j++) {
                h.push_back(make_pair(D, M + 1));
            }
        }

        sort(h.begin(), h.end());
        
        cout << "Case #" << testCase << ": " << solve(h) << "\n";
    }
    return 0;
}
