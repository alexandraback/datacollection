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

ifstream in("A-large.in");
ofstream out("outABIG.txt");


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
        ans = (r - 1) * c / w;
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