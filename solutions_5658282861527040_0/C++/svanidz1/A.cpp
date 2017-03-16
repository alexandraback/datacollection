#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<ext/hash_map>
#include<ext/hash_set>
#include<set>
#include<string>
#include<assert.h>
#include<vector>
#include<time.h>
#include<queue>
#include<deque>
#include<sstream>
#include<stack>
#include<sstream>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.0000000001
#define Pi 3.1415926535897932384626433832795
using namespace std;
using namespace __gnu_cxx;
const long long  MO=1000000000+7;
const int INF=1000000000+7;
int n,m,i,j,k,A,l[1000],r,B,a[1000];
string s[1000];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("text.txt","w",stdout);
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
     cin>>n>>m>>k;
     A=0;
     for (i=0;i<n;i++)
    for (j=0;j<m;j++) A+=((i&j)<k);
    cout<<"Case #"<<tt<<": "<<A<<endl;
    }
    return 0;
}
