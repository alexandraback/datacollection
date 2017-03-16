#include <algorithm>
#include <string.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define INF 1000000010
#define MAXN 1000

#define SUBMIT 0 /// CHANGE TO SUBMIT
#ifdef SUBMIT
    #define cin fin
    #define cout fout
#endif // SUBMIT

using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

int T;
int R, C, W;

int main()
{
    cin >> T;

    for (int test=1; test<=T; test++) {
        cin >> R >> C >> W;

        int ans = C/W*R;
        ans += W;

        if (C%W == 0)
            ans --;

        cout << "Case #" << test << ": " << ans << "\n";
    }

    return 0;
}
