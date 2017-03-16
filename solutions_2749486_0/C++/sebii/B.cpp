#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int T;
    cin >> T;

    for (int id = 1; id <= T; ++id) {
        int ex, ey;
        cin >> ex >> ey;

        cout << "Case #" << id << ": ";
    
        string s;
        if (ey > 0)
            s = "SN";
        else
            s = "NS";
        for (int i = 0; i < abs(ey); ++i)
            cout << s;

        if (ex > 0)
            s = "WE";
        else
            s = "EW";
        for (int i = 0; i < abs(ex); ++i)
            cout << s;

        cout << "\n";
    }
}
