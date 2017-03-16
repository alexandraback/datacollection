#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;


void process(int tc)
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    cout << "Case #" << tc << ": " << a * b * min(c, m) << endl;
    for (int i = 0 ; i < a ; ++i)
        for (int j = 0 ; j < b ; ++j)
            for (int k = 0 ; k < c && k < m; ++k)
                cout << i + 1 << ' ' << j + 1 << ' ' << (i + j + k) % c + 1 << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 1 ; i <= t ; ++i)
        process(i);
    return 0;
}
