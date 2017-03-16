#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    freopen("D-large.in", "rt", stdin);
    freopen("output.txt","wt", stdout);
    int m;
    cin >> m;
    for (int test = 1; test <= m; test++) {
        
        cout << "Case #" << test << ": ";
        int n;
        cin >> n;
        vector < double > first(n), second(n);
        for (int i = 0; i < n; i++)
            cin >> first[i];
        for (int i = 0; i < n; i++)
            cin >> second[i];
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        int a, b;
        a = b = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
            if (first[i] > second[j])
                j++;
        a = j;
        j = 0;
        for (int i = 0; i < n; i++)
            if (second[i] > first[j])
                j++;
        b = n - j;
        cout << a << ' ' << b << endl;
    }

    return 0;
}