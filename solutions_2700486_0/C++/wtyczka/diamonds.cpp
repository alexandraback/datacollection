#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int LL;
typedef long double LLD;


vector<vector<LL> > newtonData;

void precomputeNewton()
{
    int howMany = 45;

    vector<LL> firstRow;
    firstRow.push_back(1);
    newtonData.push_back(firstRow);

    vector<LL> secondRow;
    secondRow.push_back(1);
    secondRow.push_back(1);
    newtonData.push_back(secondRow);

    for (int i = 2; i <= howMany; i++) {
        vector<LL> newRow;

        newRow.push_back(1);
        for (int j = 1; j < i; j++) {
            newRow.push_back(newtonData[i - 1][j - 1] + newtonData[i - 1][j]);
        }
        newRow.push_back(1);

        newtonData.push_back(newRow);
    }
}

// oblicza (a po b) (symbol Newtona)
inline LL N(int a, int b)
{
    return newtonData[a][b];
}

void printNewton()
{
    for (int i = 0; i < newtonData.size(); i++) {
        for (int j = 0; j < newtonData[i].size(); j++) {
            cout << newtonData[i][j] << " ";
        }
        cout << endl;
    }
}


inline LL possibilities(LL max_left_urn, LL max_right_urn, LL balls, LL from = 0)
{
    if (max_left_urn > max_right_urn)
        swap(max_left_urn, max_right_urn);

    LL sum = 0;


    LL pot_from = 0;
    if (balls > max_right_urn) {
        pot_from = balls - max_right_urn;
    }

    for (int i = max(from, pot_from); i <= max_left_urn; i++) {
        if (i > balls) {
            break;
        }

        sum += N(balls, i);
    }

    return sum;

    //return max_left_urn - (balls - max_right_urn) + 1;
}

LLD alg(LL n, LL x, LL y)
{
    x = abs(x);
    LL line = (x + y) / 2;

    LL cur = 0;
    LL spent = 0;
    LL next_frontier = 1;

    while (cur < line) {
        spent += next_frontier;
        next_frontier += 4;
        cur++;
    }

    LL left = n - spent;

    if (left >= next_frontier)
        return 1.0;

    if (left <= 0)
        return 0.0;

    LL big_urn_size = next_frontier / 2;

//LL a = possibilities(big_urn_size - y - 1, big_urn_size, left - 1) * N(left, y);
    LL a = possibilities(big_urn_size, big_urn_size, left, y + 1);
    LL b = possibilities(big_urn_size, big_urn_size, left);
    return ((LLD) a) / ((LLD) b);
}

int main()
{
    precomputeNewton();

    //printNewton();

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        LL n, x, y;
        cin >> n >> x >> y;

        LLD ans = alg(n, x, y);
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
}

