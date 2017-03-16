//GCJ Q p1 f1

#include <iostream>
#include <cstdio>

using namespace std;

char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', \
                'x', 'd', 'u', 'i', 'g', 'l', 'b', \
                'k', 'r', 'z', 't', 'n', 'w', 'j', \
                'p', 'f', 'm', 'a', 'q'};

int main()
{
    int n = 0, t = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    cin >> t; scanf("\n");
    while (t--)
    {
        string v;
        getline(cin, v);
        printf("Case #%d: ", ++n);
        for (int i = 0; i < v.size(); i++) cout << map[v[i] - 'a'];
        cout << endl;
    }
    return 0;
}
