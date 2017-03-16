#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string solve() {
    int x, y;
    scanf("%d%d", &x, &y);
    char a[3], b[3];
    if (x < 0) a[0] = 'E', a[1] = 'W';
    else a[0] = 'W', a[1] = 'E';
    a[2] = '\0';
    if (y < 0) b[0] = 'N', b[1] = 'S';
    else b[0] = 'S', b[1] = 'N';
    b[2] = '\0';
    string s = "";
    for (int i = abs(x) ; i >= 1 ; --i) s += a;
    for (int i = abs(y) ; i >= 1 ; --i) s += b;
    return s;
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 1 ; i <= t ; ++i)
        printf("Case #%d: %s\n", i, solve().c_str());
    fclose(stdin);
    fclose(stdout);
    return 0;
}