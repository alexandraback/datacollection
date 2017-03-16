                /* In the Name of God */
#include <iostream>
#include <set>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include<cstdio>
#define lch(r) (2*(r)+1)
#define rch(r) (2*(r)+2) 
#define inf (1<<30)
#define F first
#define S second
#define mod 1000000007
using namespace std;
typedef pair<int ,int > pii;
typedef long long ll;
typedef long double ld;
const int  MAXN = 100000+10;
ifstream fin("in.in");
ofstream fout("out.out");
int fact(int l)
{
int sum=1;
 for(int i=1;i<=l;i++)
 sum*=i;
 return sum;
}
 int a[11];
 string s[11];
int  main()
{
   ios_base::sync_with_stdio(false);
             int t,tt=1;
             fin>>t;
             while(t)
             {
                      
                int n,ans=0;
                fin>>n;
                        for(int i=1;i<=n;i++)
                         fin>>s[i];
                        for(int i=1;i<=n;i++)
                         a[i]=i; 
                         int j=0 , h=fact(n);
                   while(j<h)
                    {
                        int p=0;
                                
                                for(int i=1;i<n;i+=2)
                                if(s[ a[i] ][  s[a[i]].size()-1 ]!=s[a[i+1]][0])
                                {
                                        p=1;
                                        break;
                                }
                                       if(s[a[n]][0]!=s[a[n-1]][s[a[n-1]].size()-1])
                                        p=1;
                                   if(p==0)
                                    ans++;
                                    j++;
                        next_permutation(a+1 , a+n+1);
                    }
                 fout<<"Case #"<<tt<<": ";
                  fout<<ans<<endl;
                      tt++;           
                        t--;
             }              
} 
