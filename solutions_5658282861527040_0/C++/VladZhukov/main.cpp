#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
    int t;
    in >> t;
    int a, b, k;
    vector<int> cnt;
    for (int i = 0; i < t; i++) {
        in >> a >> b >> k;
        cnt = vector<int>(k + 1, 0);
        for (int j = 0; j < a; j++)
            for (int p = 0; p < b; p++) {
                int c = j & p;
                if (c < k)
                    cnt[c]++;
            }
        int res = 0;
        for (int j = 0; j < k; j++)
            res += cnt[j];
        out << "Case #" << i + 1 << ": " << res << endl;

    }

    in.close();
    out.close();
    return 0;
}
