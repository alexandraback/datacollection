#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("A-large.in");
    ofstream cout("ansLarge");
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        vector<int> a(256, 0);
        for (auto i: s)
            a[i]++;
        vector<int> am(10, 0);
        am[0] = a['Z'];
        am[2] = a['W'];
        am[4] = a['U'];
        am[6] = a['X'];
        am[8] = a['G'];
        am[3] = a['T'] - am[2] - am[8];
        am[5] = a['F'] - am[4];
        am[7] = a['S'] - am[6];
        am[9] = a['I'] - am[5] - am[6] - am[8];
        am[1] = a['N'] - am[7] - 2 * am[9];
        cout << "Case #" << i + 1 << ": ";
//        for (int i = 0; i < 10; ++i)
//            cerr << am[i] << '\n';
        for (int i = 0; i < 10; ++i)
        while (am[i]--)
            cout << i;
        cout << '\n';
    }
    return 0;
}
