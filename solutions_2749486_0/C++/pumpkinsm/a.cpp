#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
using namespace std;
void display()
{
    int Case;
    scanf("%d", &Case);
    for (int ca=1;ca<=Case;ca++) {
        printf("Case #%d: ", ca);
        int x, y;
        scanf("%d%d", &x, &y);
        //cout << x << ' ' << y << endl;
        for (int i=0;i<abs(x);i++) {
            if (x>0) printf("WE");
            else printf("EW");
        }
        for (int i=0;i<abs(y);i++) {
            if (y>0) printf("SN");
            else printf("NS");
        }
        printf("\n");
    }
}
int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    //freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    display();
    return 0;
}
