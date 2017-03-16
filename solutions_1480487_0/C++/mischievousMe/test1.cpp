#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long lint;typedef vector<int> vi;typedef vector<vi> vii;typedef pair<int, int> p;
class node{public :    int x;    int y;    int cost;};
bool operator < ( const node & first, const node & second){    return first.cost<second.cost;}

int main()
{
   freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    int cs=0;
    while(t--)
    {
        cs++;
        int n;cin>>n;
        double ar[n];
        double tot=0.0;
        for(int x=0;x<n;x++)
        {cin>>ar[x];tot+=ar[x];}
        double val=tot*2.0/n;
        int nn=n;
        double rem=0;
        for(int x=0;x<n;x++)
        {
            if(ar[x]>val)
            nn--;
            else
            rem+=ar[x];
        }
        double vval=(rem+tot)/nn;
        double ret[n];
        for(int x=0;x<n;x++)
        {
            if(ar[x]>val) ret[x]=0;
            else ret[x]=((vval-ar[x])/tot)*100;
        }
        printf("Case #%d:",cs);
        for(int x=0;x<n;x++)
        printf(" %.6lf",ret[x]);
        cout<<"\n";
    }
    return 0;
}
