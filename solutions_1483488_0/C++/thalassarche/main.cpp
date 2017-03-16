#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstdlib>

using namespace std;

inline int recycle(int i, int x) {
    i*=10;
    return (i%x)+(i/x);
}

int solve() {
    int result=0;
    int a,b;
    cin >> a >> b;
    int x=1;
    while (x<=a) x*=10;
    for (int i=a;i<=b;i++) {
        int recycled=i;
        do {
            recycled=recycle(recycled,x);
            if (recycled>i&&recycled<=b) ++result;
        } while (recycled!=i);
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int i=0;i<t;i++) cout << "Case #" << i+1 << ": " << solve() << endl;
    return 0;
}
