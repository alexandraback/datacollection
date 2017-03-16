#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mem0(ar) memset(ar, 0, sizeof(ar))
#define mem1(ar) memset(ar, -1, sizeof(ar))

struct hiker {
    int start_pos;
    int speed;
}temp;

int main()
{
    //freopen("C-large.in", "r", stdin);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int TESTS;
    cin >> TESTS;
    for (size_t test_number = 1; test_number <= TESTS; test_number++) {
        cout << "Case #" << test_number << ": ";
        int N;
        cin >> N;
        vector<hiker> hikers;
        for (int i = 0; i < N; i++) {
            int start_pos, quantity, min_speed;
            cin >> start_pos >> quantity >> min_speed;
            for (int j = 0; j < quantity; j++) {
                temp.start_pos = start_pos;
                temp.speed = min_speed + j;
                hikers.push_back(temp);
            }
        }
        if (hikers.size() < 2) {
            cout << 0;
        } else {
            hiker slower = hikers[0];
            hiker faster = hikers[1];
            if (slower.speed < faster.speed) {
                swap(slower, faster);
            }
            long double time = ((long double)360 - (long double)slower.start_pos) * ((long double)360 / (long double)slower.speed);
            long double time2 = ((long double)360 - (long double)faster.start_pos) * ((long double)360 / (long double)faster.speed);
            long double time3 = (time - time2) * ((long double)360 / (long double)faster.speed) / (long double)360;
            if (time3 < (long double)1.0)
                cout << 0;
            else
                cout << 1;
        }
        cout << endl;
    }
}
