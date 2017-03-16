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

ll ans, temp;

char s[1100000];
int a[1100000];
ll t, l, n;
char fb[10]={'a', 'e', 'i', 'o', 'u'};
vector< pair<int, int> >v;
inline bool check(int x)
{
       for (int i=0; i<5; i++)
           if ( s[x]==fb[i] )
              return 0;
       return 1;       
}
inline int bin(int st, int fin, int e)
{
    if ( st==fin )
       return st;
    int med=(st+fin+1)/2;
    int ee, rr;
    if ( e==0 )
       ee=0;
    else
       ee=a[e-1];
    rr=a[med];
    if ( (rr-ee)==(med-e+1) )
       return bin(med, fin, e);
    else
       return bin(st, med-1, e);  
}
void solve(int test)
{
     v.clear();
     ans=temp=0;
     scanf("%s", s);
     scanf("%d", &n);
     l=strlen(s);
     a[0]=check(0); 
     for (int i=1; i<l; i++)
         a[i]=a[i-1]+check(i);
     //for (int i=0; i<l; i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
     for (int i=0; i<l; i++)
     {
         if ( check(i)==0 )
            continue;
         int z=bin(i, l-1, i);
         if ( z-i+1>=n )
            v.push_back(make_pair(i, z));
     }   
     //for (int i=0; i<v.size(); i++)
     //    cout<<v[i].X<<" "<<v[i].Y<<endl;
     ans=l*(l+1)/2;
     for (int i=0; i<l; i++)
     {
         vector<pair<int, int> >::iterator it=lower_bound( v.begin(), v.end(), make_pair(i, i) );    
         if ( it==v.end() )
            temp+=(ll)l-1-i+1;
         else
         {
            ll f=(*it).X+n-2;     
            temp+=(ll)f-i+1;
         }
         //cout<<temp<<endl;
     }
     printf("Case #%d: %I64d\n", test, ans-temp);
}
int main ()
{
    freopen("A-large.in", "r", stdin);   
    freopen("out.txt", "w", stdout);
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        solve(i);    
    }
    cin>>t;
    return 0;
}
