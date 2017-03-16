#include <iostream>

using namespace std;


int regularRow(int c, int w) {
    int res = 0;
    for (int i = w-1; i<c; i+=w)
        res++;
    return res;
}
int endRow(int c, int w) {
    int res = 0;
    int pos = 0;
    for (int i = w-1; i<c; i+=w) {
        res++;
        pos = i;
    }
    if (pos == c-1)
        return res+w-1;

    return res+w;
}

void solve(int caseNum) {
    int r, c, w;
    cin >> r >> c >> w;
    int res = regularRow(c,w)*(r-1) + endRow(c,w);
    cout<<"Case #"<<caseNum<<": "<<res<<"\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i+1);
}
