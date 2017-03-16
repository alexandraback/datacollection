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
#define sz(x) ((int)x.size())
using namespace std;

typedef long long ll;

int a[2300000];
int b[1000];
vector<int> ff, ss;

int main(void)
{
    int t, tt, i, j, n;
    cin >> t;
    fo(tt, t)
        {
            memset(a, 0, sizeof(a));
            a[0] = 1;
            cout << "Case #" << tt+1 << ": " << endl;
            cin >> n;
            fo(i,n) cin >> b[i];
            sort(b, b+20);
            int sum = 0;
            bool found = false;
            fo(i,n)
                {
                    sum += b[i];
                    ff.clear();
                    ss.clear();
                    for(j = sum; j >= b[i]; j--)
                        {
                            if (a[j - b[i]])
                                {
                                    if (a[j])
                                        {
                                            found = true;
                                            int k;                                            
                                            for(k = j; k; k -= a[k]) ff.pb(a[k]);
                                            ss.pb(b[i]);
                                            for(k = j - b[i]; k; k -= a[k]) ss.pb(a[k]);
                                            break;
                                        }
                                    a[j] = b[i];
                                }
                        }
                    if (found)
                        {
                            sort(all(ff));
                            sort(all(ss));
                            fo(i,sz(ff)) cout << ff[i] << " ";
                            cout << endl;
                            fo(i,sz(ss)) cout << ss[i] << " ";
                            cout << endl;
                            break;
                        }
                }
            if (!found) cout << "Impossible" << endl;
        }
}
