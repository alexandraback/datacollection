#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int run = 0; run < T; ++run)
    {
        vector<int> Ps;

        int D;
        cin >> D;

        for (int i = 0; i < D; ++i)
        {
            int Pi;
            cin >> Pi;
            Ps.push_back(Pi);
        }

        int min = 1000;
        for (int i = 1; i < 1000; ++i) {
            int splits = 0;
            for (int j = 0; j < Ps.size(); ++j) {
                if (Ps[j] > i)
                    splits += (Ps[j] - 1) / i;
            }

            if (splits + i < min)
                min = splits + i;
        }

        cout << "Case #" << run + 1 << ": " << min << endl;
    }
    return 0;
}
