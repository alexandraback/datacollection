#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <memory>
#include <functional>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>
#include <sstream>
#include <set>
#include <map>

using namespace std;

int main()
{
    ifstream in ("in.in");
    ofstream out ("out.txt");

    int T;

    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        out << "Case #" << t << ": ";

        int r, c, w;

        in >> r >> c >> w;

        int ans = (c / w) * r + (w - 1);

        if (c > ((c / w) * w))
            ++ans;

        out << ans << endl;

    }

    in.close();
    out.close();
    return 0;
}
