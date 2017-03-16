#include <iostream>
#include <string>
#include <vector>

#ifndef NDEBUG
    #define log(__arg__) cout<<__arg__
    #define logn(__arg__) cout<<__arg__<<endl
#else
    #define log(__arg__) while(0){}
    #define logn(__arg__) while(0){}
#endif

#define forx(__var__,__arg__) for(int __var__=0;__var__<(int)__arg__;__var__++)
#define fori(__arg__) forx(i,__arg__)
#define forj(__arg__) forx(j,__arg__)

using namespace std;

int r, c, w;

int solve() {
    cin >> r >> c >> w;
    auto ret = 0;

    ret += c/w * r;
    ret += w;

    if (c%w == 0) {
        ret -= 1;
    }

    return ret;
}

int main() {
    int nCase;
    cin >> nCase;
    fori(nCase) {
        cout << "Case #" << i+1 << ": " << solve();
        cout << endl;
    }
}
