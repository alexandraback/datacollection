#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

ull best1, best2;
ull bestdiff = -1;
string s1,s2;
int n;

ull ctol(char c) {
    return (ull)(c-'0');
}

void search(int x, ull val1, ull val2, int way)
{
//    cout << x << ", " << val1 << ", " << val2 << ", " << way << endl;
    if (x == n) {
//        cout << bestdiff << endl;
        if (val1 > val2) {
            ull diff = val1-val2;
            if (diff < bestdiff || (diff == bestdiff && val1 < best1) || (diff == bestdiff && val1 == best1 && val2 < best2)) {
                bestdiff = diff;
                best1 = val1;
                best2 = val2;
            }
        }
        else {
            ull diff = val2-val1;
            if (diff < bestdiff || (diff == bestdiff && val1 < best1) || (diff == bestdiff && val1 == best1 && val2 < best2)) {
                bestdiff = diff;
                best1 = val1;
                best2 = val2;
            }
        }
//        cout << bestdiff << endl;
        return;
    }
    if (s1[x] == '?' && s2[x] == '?') {
//        cout << 1 << endl;
        if (way == 0) {
            search(x+1, val1*10, val2*10, way);
            search(x+1, val1*10+1, val2*10, 1);
            search(x+1, val1*10, val2*10+1, -1);
        }
        else if (way == 1) { // val1 bigger
            search(x+1, val1*10+0,val2*10+9,way);
        }
        else {
            search(x+1,val1*10+9,val2*10+0,way);
        }
    }
    else if (s1[x] == '?') {
//        cout << 2 << endl;
        ull z = ctol(s2[x]);
        if (way == 0) {
            search(x+1,val1*10+z, val2*10+z, way);
            if (z < 9)
                search(x+1,val1*10+z+1, val2*10+z, 1);
            if (z > 0)
                search(x+1,val1*10+z-1, val2*10+z, -1);
        }
        else if (way == 1) { // val1 bigger
            search(x+1,val1*10+0, val2*10+z, way);
        }
        else {
            search(x+1,val1*10+9, val2*10+z, way);
        }
    }
    else if (s2[x] == '?'){
//        cout << 3 << endl;
        ull z = ctol(s1[x]);
        if (way == 0) {
            search(x+1,val1*10+z, val2*10+z, way);
            if (z < 9)
                search(x+1,val1*10+z, val2*10+z+1, 1);
            if (z > 0)
                search(x+1,val1*10+z, val2*10+z-1, -1);
        }
        else if (way == 1) { //val1 is bigger
            search(x+1,val1*10 + z, val2*10+9, way);
        }
        else {
            search(x+1,val1*10 + z, val2*10+0, way);
        }
    }
    else {
//        cout << 4 << endl;
        ull z1 = ctol(s1[x]);
        ull z2 = ctol(s2[x]);
        if (way == 0 && z1 < z2)
            search(x+1,val1*10 + z1, val2*10+z2, -1);
        else if (way == 0 && z2 < z1)
            search(x+1,val1*10 + z1, val2*10+z2, 1);
        else
            search(x+1,val1*10 + z1, val2*10+z2, way);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        cin >> s1;
        cin >> s2;
        n = s1.length();
        bestdiff = -1;
        search(0,0,0,0);
        cout << "Case #" << z << ": " << setw(n) << setfill('0') << best1 << " " << setw(n) << setfill('0') << best2 << endl;
    }
}
