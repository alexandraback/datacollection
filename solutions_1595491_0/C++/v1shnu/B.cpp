// #define GOD DJ
using namespace std;

// HEADER FILES
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>

// CONSTANTS
#define INF (1<<31)-1
#define PI 3.14159265358979323846264338327950288419716939937510
#define MAXV 100001

// FUNCTIONS
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
// gcd(a,b){ return (b==0)?a:gcd(b,a%b); }
// lcm(a,b){ return a*b/gcd(a,b); }

typedef long long LL;
typedef long double LD;
typedef long long unsigned int LLU;

// END TEMPLATE BY DJ


int main()
{
    //COMMENT THIS LINE BEFORE POSTING!
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    //COMMENT THIS LINE BEFORE POSTING!
    int x,t,n,s,p,i,score[102];
    scanf("%d",&t);
    x=t;
    while(t--)
    {
        int total=0;
        scanf("%d",&n);
        scanf("%d",&s);
        scanf("%d",&p);
        for(i=0;i<n;i++) scanf("%d",&score[i]);
        sort(score,score+n);
        for(i=n-1;i>=0;i--)
        {
            if(score[i]<p) continue;
            int left=score[i]-p-(p-1)-(p-1);
            if(left>=0) { total++; continue; }
            if(s>0&&left>-3) {total++; s--;}

        }

        cout<<"Case #"<<x-t<<": "<<total<<endl;

    }
}
