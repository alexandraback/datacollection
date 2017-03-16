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

int main(int argc, char **argv)
{
    int T;
    cin >> T;
    for (int t = 1;t <= T; t++) {
        int K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << t << ":";
        for (int i = 1;i <= S; i++)
            cout << " " << i;
        cout << endl;
    }

    return 0;
}
