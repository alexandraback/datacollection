#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int r, n, m, k;
int v[16];

void calc() {
    int n2=0, n3=0, n5=0;
    int cn2, cn3, cn5;
    int a, i;
    for(i=0; i<k; ++i) {
        cn2=cn3=cn5 = 0;
        a = v[i];
        while(a%2==0) {
            cn2++;
            a/=2;
        }
        while(a%3==0) {
            cn3++;
            a/=3;
        }
        while(a%5==0) {
            cn5++;
            a/=5;
        }
        n2 = max(n2, cn2);
        n3 = max(n3, cn3);
        n5 = max(n5, cn5);
    }
    int left=n;
    for(i=0; i<n3; ++i) {
        cout<<3;
        --left;
    }
    for(i=0; i<n5; ++i) {
        cout<<5;
        --left;
    }
    for(i=0; i<(n2/2); ++i) {
        cout<<4;
        --left;
    }
    for(i=0; i<left; ++i) {
        cout<<2;
    }
    cout<<endl;
}

int main() {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-1-attempt0.out", "w", stdout);
    int i, j;
    int T, NT;
    cin>>NT;

    for(T=1; T<=NT; ++T) {
        cin>>r>>n>>m>>k;
        cout<<"Case #"<<T<<":"<<endl;
        for(i=0; i<r; ++i) {
            for(j=0; j<k; ++j) {
                cin>>v[j];
            }
            calc();
        }
    }
    return 0;
}
