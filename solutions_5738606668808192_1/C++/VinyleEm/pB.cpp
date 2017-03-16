#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <utility>

#include "common.h"

using namespace std;

void genJamCoins(int N, int J)
{
    int np = N / 2 - 2;
    for (int i = 0;i < J; i++) {
        string jamCoin = "11";
        for (int j = 0;j < np; j++)
            if (i & (1<<j))
                jamCoin += "11";
            else jamCoin += "00";
        jamCoin += "11";
        cout << jamCoin;
        for (int b = 2;b <= 10; b++)
            cout << " " << (1 + b);
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    cout << "Case #1:" << endl;
    genJamCoins(32, 500);
}
