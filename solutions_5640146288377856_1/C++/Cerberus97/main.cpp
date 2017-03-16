#include <iostream>
#include <fstream>

using namespace std;

int solve (int r, int c, int w)
{
    if (r > 1)
        return (r - 1) * (c / w) + solve (1, c, w);

    if (w >= c - 1)
        return c;

    if (w == 1)
        return c;

    if (c / w > 1)
        return 1 + solve (r, c - w, w);

    if (c / w == 1)
        return w + 1;
}

int main()
{
    ifstream in ("in.txt");
    ofstream out ("out.txt");

    int t, r, c, w;

    in >> t;

    for (int j = 1; j <= t; ++j)
    {
        in >> r >> c >> w;

        out << "Case #" << j << ": " << solve (r, c, w) << '\n';
    }

    return 0;
}
