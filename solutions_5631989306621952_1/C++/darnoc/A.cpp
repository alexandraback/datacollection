#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <deque>

using namespace std;

#define N 1004
int sol[N];

int main()
{
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        deque<char> o;
        char cm = 0;
        for (char c : s) {
            if (c >= cm) {
                cm = c;
                o.push_front(c);
            }
            else {
                o.push_back(c);
            }
        }
        printf("Case #%d: ", t);
        for (char c : o) putchar(c);
        putchar('\n');
    }
    

    return 0;
}
