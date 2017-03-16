#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <sstream>
#include <fstream>
using namespace std;

ifstream in("A-small-attempt2.in");
ofstream out("outA.txt");


#define cin in
#define cout out
/**/


int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int ans = 0;
        int r, c, w;
        cin >> r >> c >> w;
        // first r - 1 rows
        ans = (r - 1) * (c + w - 1) / w;
        // last row
        int o = (c - w) / w;
        ans += o;
        int left =  c - w * o;
        if (left == w)
            ans += left;
        else
            ans += w + 1;
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
}