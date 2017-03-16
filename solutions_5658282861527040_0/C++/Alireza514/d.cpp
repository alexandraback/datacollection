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
const int  MAXN = 100000+10;
ifstream fin("B-small-attempt0.in");
ofstream fout("out.out");
int  main()
{
   ios_base::sync_with_stdio(false);
        int t;
        fin>>t;
           for(int tt=1;tt<=t;tt++)
           {
                        int a, b , c,ans=0 ;
                        fin>>a>>b>>c;
                        for(int i=0;i<a;i++)
                         for(int j=0;j<b;j++)
                         if((i&j )<c)
                          ans++;
                    
                          fout<<"Case #"<<tt<<": "<<ans<<endl;
           }
} 
