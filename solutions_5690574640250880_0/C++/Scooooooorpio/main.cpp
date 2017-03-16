#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;

void prework();
void work();

int main(int argc, char *argv[])
{
#if 1
auto t1 = freopen("1.in","r",stdin);
if (t1== nullptr) {
    cerr <<"no file"<<endl;
    return 0;
}
auto t2 = freopen("output.txt","w",stdout);
#endif

    prework();

    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Case #"<<i+1<<": ";
        work();
        cout<<endl;
    }

    cerr<<"end!!!!!!!!!!"<<endl;

}

void prework() {
}

void outre(int r, int c, int r1, int c1, int x, int y) {
    char ma[60][60];
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            ma[i][j] = '*';
        }
    }
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c1; j++) {
            ma[i][j] = '.';
        }
    }
    ma[0][0] = 'c';
    for (int f = 0; f<x; f++) {
        ma[r1-f-1][c1-1] = '*';
    }
    for (int f = 0; f<y; f++) {
        ma[r1-1][c1-f-1] = '*';
    }
    for (int i=0; i<r; i++) {
        cout<<endl;
        for (int j=0; j<c; j++) {
            cout<<ma[i][j];
        }
    }
}

void work() {
    int r,c,m;
    cin>>r>>c>>m;
    int left = r*c - m;
    if (left==1) {
        outre(r,c,1,1,0,0);
        return;
    }
    for (int i =1; i<=r; i++) {
        for (int j=1; j<=c; j++) {

            if (i*j <left) continue;
            if (i*j == left) {
                if (i==1) {
                    if (r>1) continue;
                }
                if (j==1) {
                    if (c>1) continue;
                }
                outre(r,c,i,j,0,0);
                return;
            }
            if (i<3 || j<3) continue;
            int x = i*j - left;
            if (i+j-5 < x) continue;

            if (i-2 >=x) {
                outre(r,c,i,j,x,1);
                return;
            }
            outre(r,c,i,j,i-2,  x-i+3);
            return;
        }
    }
    cout<<endl<<"Impossible";

}
