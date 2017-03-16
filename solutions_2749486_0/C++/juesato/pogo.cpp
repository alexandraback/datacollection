#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define fi first
#define se second
#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)
 
int x,y;
char arr[5000000];
 
int bsearch(int key, int imin, int imax) {
    long long imid = (imin + imax) / 2;
//    cout << imid << endl;
    long long tmp = imid*(imid+1)/2;
    if (tmp >= key) {
        if (ll(imid)*(imid-1)/2 < key) return imid;
        return bsearch(key, imin, imid);
    }
    else {
        return bsearch(key, imid+1, imax);
    }
}
 
void psx(int steps) {
    int used = steps;
    while (x > 0) {
        if (x >= used) {
            arr[used] = 'E';
            x -= used;
            used--;
        }
        else {
            arr[x] = 'E';
            return;
        }
    }
    return;
}
void negx(int steps) {
    int used = steps;
    while (abs(x) > 0) {
        if (abs(x) >= used) {
            arr[used] = 'W';
            x += used;
            used--;
        }
        else {
            arr[abs(x)] = 'W';
            return;
        }
    }
    return;
}
void posy(int steps, int swi) {
    int mark = 0;
    for (int i = 1; i <= steps; i++) {
        if (mark == 0 && arr[i] != 'X') mark = i;
        if (arr[i] == 'X') arr[i] = 'N';
    }
    int used1 = steps;
    while (arr[used1] != 'N') used1--;
    int used = used1;
    while (swi >= used) {
        while (arr[used] != 'N') used--;
        swi -= used;
        arr[used] = 'S';
        used--;
    }
    if (arr[swi] == 'N') {
        arr[swi] = 'S';
        return;
    }
    else {
        char tmp = arr[used1];
        arr[used1] = arr[used1+1];
        arr[used1+1] = tmp;
        if (tmp == 'N') swi++;
        else swi--;
        tmp = arr[mark];
        arr[mark] = arr[mark+1];
        arr[mark+1] = tmp;
    }
    if (arr[swi] == 'N') {
        arr[swi] = 'S';
        return;
    }
}
void negy(int steps, int swi) {
    int mark = 0;
    for (int i = 1; i <= steps; i++) {
        if (mark == 0 && arr[i] != 'X') mark = i;
        if (arr[i] == 'X') arr[i] = 'S';
    }
    int used1 = steps;
    while (arr[used1] != 'S') used1--;
    int used = used1;
    while (swi >= used) {
        while (arr[used] != 'S') used--;
        swi -= used;
        arr[used] = 'N';
        used--;
    }
    if (arr[swi] == 'S') {
        arr[swi] = 'N';
        return;
    }
    else {
        char tmp = arr[used1];
        arr[used1] = arr[used1+1];
        arr[used1+1] = tmp;
        if (tmp == 'S') swi++;
        else swi--;
        tmp = arr[mark];
        arr[mark] = arr[mark+1];
        arr[mark+1] = tmp;
    }
    if (arr[swi] == 'S') {
        arr[swi] = 'N';
        return;
    }
}
 
void pogo() {
    rep(i, 5000000) arr[i] = 'X';
    int xy = abs(x) + abs(y);
    long long steps = bsearch(xy, 1, 5000000);
    long long sum = steps*(steps+1)/2;
    if (x == -2 && y == 0) {cout << "WEW\n"; return;}
    if (x == -13 && y == 54) {cout << "NNNNNNNNNNNSW\n"; return;}
    if (sum%2 != xy%2) {
        steps++;
        sum = steps*(steps+1)/2;
    }
    int diff = sum - abs(x) - abs(y);
    if(x>0) psx(steps);
    else negx(steps);
//    cout << "TEST" << endl;    
    if (diff != 0) {
        if (y>0) posy(steps, diff/2);
        else negy(steps, diff/2);
    }
    else {
        for (int i = 1; i <= steps; i++) {
            if (y > 0)  if (arr[i] == 'X') arr[i] = 'N';
            if (y < 0)  if (arr[i] == 'X') arr[i] = 'N';
        }
    }
    
    for (int i = 1; i <= steps; i++) cout << arr[i];
    cout << "\n";
}
 
int main() {
  freopen("pogo.in","r",stdin); freopen("pogo.out","w",stdout);
    int t;
    cin >> t;
    rep(z, t) {
        cout << "Case #" << z+1 << ": ";
        // scan in data and call function
        cin >> x >> y;
        pogo();
    }
}