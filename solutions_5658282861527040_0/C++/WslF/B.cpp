//solution by Wsl_F
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#define author Wsl_F
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <x86intrin.h>

using namespace std;

typedef long long LL;
typedef double dbl;
typedef vector<int> vi;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)

int main()
{

 ios_base::sync_with_stdio(0);
 cin.tie(0);
// LL a[110];
// memset(a,0,sizeof(a));

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

 srand(__rdtsc());

 int T;
 cin>>T;

 for (int TT=1; TT<=T; TT++)
 {
     int a,b,k;
     cin>>a>>b>>k;
     int ans= 0;

     for (int a0= 0; a0<a; a0++)
        for (int b0= 0; b0<b; b0++)
        {
           int t= a0&b0;
         if (t<k) ans++;
        }
    cout<<"Case #"<<TT<<": "<<ans<<endl;
 }


 return 0;
}


