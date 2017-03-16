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

int D[1000010];
int flip(int N) {
    vector<int> s;
    while(N != 0) {
        s.push_back(N%10);
        N/=10;
    }
    int k = 0;
    while(k!=s.size()) {
        N*=10;
        N+=s[k];
        k++;
    }
    return N;
}

int main()
{
    //freopen("A-large.in", "r", stdin);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    mem1(D);
    D[1] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        int r1 = i + 1;
        int r2 = flip(i);
        if (D[r1] == -1 || D[r1] > D[i] + 1) {
            D[r1] = D[i] + 1;
        }
        if (D[r2] == -1 || D[r2] > D[i] + 1) {
            D[r2] = D[i] + 1;
        }
    }
    int TESTS;
    cin >> TESTS;
    for (size_t test_number = 1; test_number <= TESTS; test_number++) {
        cout << "Case #" << test_number << ": ";
        int N;
        cin >> N;
        cout << D[N];
        cout << endl;
    }
}
