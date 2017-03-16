#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <sstream>
#define mst(a,v) memset(a, v, sizeof(a))
#define msk(s,p) for(p=(s-1)&s;p=(p-1)&s)
#define _USE_MATH_DEFINES
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
using namespace std;

typedef long long ll;

int a[300], n;
double sum;

bool mayDrop(int ind, double y)
{
    double ownVal = a[ind] + sum * y, minY = y;
    int i;
    fo(i,n)
        {
            if (i == ind || a[i] >= ownVal) continue;
            minY += (ownVal - a[i]) / sum;
        }
    return (minY < 1);
}

int main(void)
{
    int t, tt, i, j;
    cin >> t;
    fo(tt, t)
        {
            cin >> n;
            fo(i,n) cin >> a[i];
            sum = 0;
            fo(i,n) sum += a[i];
            
            cout << "Case #" << tt+1 << ": ";
            fo(i,n)
                {
                    double l = 0, r = 1, m;
                    int rr;
                    fo(rr, 28)
                        {
                            m = (l + r) / 2;
                            if ( mayDrop(i, m) ) l = m; // sum < 1
                            else r = m;
                        }
                    printf("%.7lf ", m * 100);
                }
            cout << endl;
        }
}
