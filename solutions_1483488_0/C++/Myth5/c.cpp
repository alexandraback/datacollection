#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("c1.in", "r", stdin);
    freopen("c1.out", "w", stdout);
    
    int t1, t2;
    cin >> t1;
    for (t2 = 1; t2 <= t1; ++t2) {
        cout << "Case #" << t2 << ": ";
        int A, B;
        cin >> A >> B;
        map<int, int> f;
        int t = 1;
        while (t * 10 <= B)
            t *= 10;
        for (int i = A; i <= B; ++i) {
            int j = i, k = i;
            do {
                k <?= j;
                j = j / 10 + j % 10 * t;
            }while (j != i);
            ++f[k];
        }
        long long ret = 0;
        for (map<int, int>::iterator it = f.begin(); it != f.end(); ++it)
            ret += it->second * (it->second - 1);
        cout << ret / 2 << endl;
    }
    
    return 0;
}
