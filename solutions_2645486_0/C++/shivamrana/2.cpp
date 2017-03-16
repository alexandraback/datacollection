/* shivamrana */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
#define f0r(i,n) for(int i=0;i<n;i++)
#define fOr(i,n) for(int i=1;i<=n;i++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%I64d",a)
#define n(l) cout<<endl
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;

int e,r,n,maxi;
int v[113];
void go(int start,int s,int piggi)
{
                   if(start==n)
                   {
                             maxi=max(maxi,piggi);
                             return ;          
                   }
                   for(int i=0;i<=s;i++)
                   {
                                         if((s-i+r)<=e)
                                         go(start+1,(s-i)+r,piggi+v[start]*i);        
                                         else
                                         go(start+1,s,piggi+v[start]*i);
                   }
                   return ;
}
int main()
{
                 freopen("2a.in","r",stdin);
                 freopen("2a.out","w",stdout);
                    int t;
                    cin>>t;
                    for(int c=1;c<=t;c++)
                    {
                            cin>>e>>r>>n;
                            for(int i=0;i<n;i++)
                                    si(v[i]);
                            maxi=0;
                            go(0,e,0);  
                            printf("Case #%d: %d\n",c,maxi);
                    }
                    return 0;    
}

