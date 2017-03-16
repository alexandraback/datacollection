
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef long long int ll;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int r, c, w;
        cin >> r >> c >> w;
        int spr = c / w;
        int spt = r * spr;
        int ret = spt + w;
        if (c % w == 0) --ret;

        cout << "Case #" << i + 1 << ": " << ret << endl;
    }

    return 0;
}
