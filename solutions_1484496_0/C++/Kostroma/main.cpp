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
int a[400];

void solve()
{  
    cin>>n;
    cout<<"Case #"<<timer<<": "<<endl;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int m=0; m<(1<<n); m++)
    {
        for (int s=m; ; s=(s-1)&m) 
        {
            int s1=0, s2=0;
            for (int i=0; i<n; i++)
                if (m & (1<<i))
                {
                    if ( s & (1<<i) )
                        s1+=a[i];
                    else
                        s2+=a[i];
                }
            if (s1>0 && s1==s2)
            {
                //cout<<s1<<' '<<s2<<endl;
                vector <int> a1, a2;
                for (int i=0; i<n; i++)
                        if (m & (1<<i))
                        {
                            if ( s & (1<<i) )
                                a1.pb(a[i]);
                            else
                                a2.pb(a[i]);
                        }
                for (int i=0; i<a1.size(); i++)
                    cout<<a1[i]<<' ';
                cout<<endl;
                for (int i=0; i<a2.size(); i++)
                    cout<<a2[i]<<' ';
                cout<<endl;
                return;
            }
            if (s==0)  
                break;
        }
    }
    
    
    cout<<"Impossible";
    cout<<endl;
}
