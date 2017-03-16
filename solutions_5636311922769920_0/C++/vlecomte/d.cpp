#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
typedef long long ll;

int main()
{
    int nt;
    cin >> nt;
    for (int t=1; t<=nt; t++) {
        int k,c,s;
        cin >> k >> c >> s;
        printf("Case #%d:", t);
        for (int i=1; i<=k; i++)
            cout << ' ' << i;
        cout << endl;
    }
}
