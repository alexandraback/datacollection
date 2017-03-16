#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#define abs(x) (((x)>0)?(x):(-x))
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
using namespace std;
int T;
int n, D[20], M[20], H[20];
int d[20], m[20], c;
double s[20];

int main()
{
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        cout << "Case #" << Case << ": ";
        cin >> n;
        c = 0;
        for (int i = 0; i < n; i++) {
            cin >> D[i] >> H[i] >> M[i];
            for (int j = 0; j < H[i]; j++) {
                d[c] = D[i];
                m[c] = M[i] + j;
                c++;
            }
        }
        if (c == 0 || c == 1) {
            cout << 0 << endl;
        }
        else if (m[0] == m[1]) {
            cout << 0 << endl;
        }
        else {
            if (d[0] > d[1]) {
                d[0] = d[0] ^ d[1];
                d[1] = d[0] ^ d[1];
                d[0] = d[0] ^ d[1];
                m[0] = m[0] ^ m[1];
                m[1] = m[0] ^ m[1];
                m[0] = m[0] ^ m[1];
            }

            for(int i = 0; i < 20; i++){
                s[i] = 360.0 / m[i];
            }

            //forward is faster
            if (s[1] > s[0]) {
                double p = ((360.0 + d[0] - d[1]) / (s[1] - s[0]));
                double cur = p * s[0] + d[0];
                //cout << "first "<<cur << endl;
                if (abs(cur - 360.0) < 0.000000001 || cur < 360.0) {
                    cout << 1 << endl;
                }
                else {
                    cout << 0 << endl;
                }
            }
            //behind is faster
            else {
                //first meet
                double p1 = ((d[1] - d[0]) * 1.0 / (s[0] - s[1]));
                //cout << "second "<< p1 << endl;
                //second
                double p2 = (360.0) / (s[0] - s[1]) + p1;
                //cout << "second "<< p2 << endl;

                double cur = p2 * s[1] + d[1];
                //cout << "second "<< cur << endl;
                if (abs(cur - 360.0) < 0.000000001 || cur < 360.0) {
                    cout << 1 << endl;
                }
                else {
                    cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}
