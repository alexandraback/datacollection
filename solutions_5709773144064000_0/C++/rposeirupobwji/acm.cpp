#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define mp(a, b) make_pair(a, b)
#define D(a) #a << ": " << a << "\n"

int main()
{
    srand(time(NULL));
    cout << setprecision(15);
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        double c, f, x, p = 2.0, time = 0;
        cin >> c >> f >> x;

        vector<double> arr;
        arr.clear();

        while (arr.size() < 2 || arr.back() < arr[arr.size()-2])
        {
            arr.push_back(time + x / p);
            //cout << arr.back() << endl;
            time += c / p;
            p += f;
        }

        printf("Case #%d: ", CASE, arr.size());
        cout << arr[arr.size() - 2] << endl;

    }

    return 0;
}