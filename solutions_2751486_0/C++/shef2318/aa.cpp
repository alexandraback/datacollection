#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define ll long long

using namespace std;

char s[110];
int t, l, n;
char fb[10]={'a', 'e', 'i', 'o', 'u'};
bool check(int x)
{
     if (x+n-1>=l)
        return 0;
     for (int i=x; i<=x+n-1; i++)
         for (int j=0; j<5; j++)
             if ( fb[j]==s[i] )
                return 0;
     return 1;  
}
void solve(int test)
{
     set< pair<int, int> >ss;
    

     cin>>s;
     cin>>n;
     l=strlen(s);
     for (int i=0; i<l; i++)
     {
         if ( check(i) )
            for (int j=0; j<=i; j++)
                for (int z=i+n-1; z<l; z++)
                    ss.insert( make_pair(j, z) );
     }    
     printf("Case #%d: %d\n", test, ss.size()); 
}
int main ()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        solve(i);    
    }
    cin>>t;
    return 0;
}
