#include <fstream>

using namespace std;

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int t;
    fin >> t;
    for (int i = 1; i <= t; i++)
    {
        int r, c, w;
        fin >> r >> c >> w;
        int ans;
        if (w == 1)
            ans = r * c;
        else
        {
            if (c % w == 0)
                ans = (c / w + w - 1) + (c / w) * (r - 1);
            else
                ans = (c / w + w) + (c / w) * (r - 1);
        }

        fout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
