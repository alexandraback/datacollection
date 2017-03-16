#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int timer=1;
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while (t--)
        solve(), ++timer;
    return 0;
}

//#define int li

int n;
ld s[300];
ld sum=0;
ld ans[300];

void solve()
{  
    sum=0.0;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>s[i], sum+=s[i];
    
    for (int i=0; i<n; i++)
    {
        ld l=0.0, r=1.0;
        for (int w=0; w<200; w++)
        {
            ld m=l+r; m/=2.0;
            ld now=0.0;
            for (int j=0; j<n; j++)
                if(i!=j)
                {
                    ld delta=s[i]+sum*m-s[j];
                    //printf ("%.10lf %.10lf %.10lf %.10lf %.10lf\n", s[i], s[j], m, sum, delta);
                    if (delta>0)
                        now+=delta;
                }
            if (now+m*sum>sum)
                r=m;
            else
                l=m;
            //printf ("%.10lf %.10lf\n", l, r);
        }
        ans[i]=l;
    }
    
    cout<<"Case #"<<timer<<": ";
    
    for (int i=0; i<n; i++)
        printf ("%.10lf ", ans[i]*100.0);
    
    cout<<endl;
}
