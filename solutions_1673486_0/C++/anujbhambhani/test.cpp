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
double min(double a,int b)
{
    if(a<b)return a;
    return b;
}
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
        int a,b;
        cin>>a>>b;
        double p[a];
        for(int x=0;x<a;x++)
            cin>>p[x];
        double ans=1000000.0;
        if(a==1)
        {
            ans=min(ans,p[0]*(b-a+1)+(1-p[0])*(b-a+1+b+1));//keep on typing
            //press backspace once
            ans=min(ans,1+b+1);
            //press enter right away
            ans=min(ans,1+b+1);
        }
        if(a==2)
        {
            ans=min(ans,(p[0]*p[1])*(b-a+1)+(1-p[0]*p[1])*(b-a+1+b+1));//keep on typing
            //press backspace once
            ans=min(ans,p[0]*(1+b)+(1-p[0])*(1+b+b+1));
            //press backspace twice
            ans=min(ans,2+b+1);
            //press enter right away
            ans=min(ans,1+b+1);
        }
        if(a==3)
        {
            ans=min(ans,(p[0]*p[1]*p[2])*(b-a+1)+(1-p[0]*p[1]*p[2])*(b-a+1+b+1));//keep on typing
            //press backspace once
            ans=min(ans,(p[0]*p[1])*(1+b-a+2)+(1-p[0]*p[1])*(1+b-a+2+b+1));
            //press backspace twice
            ans=min(ans,p[0]*(2+b)+(1-p[0])*(2+b+b+1));
            //press backspace thrice
            ans=min(ans,3+b+1);
            //press enter right away
            ans=min(ans,1+b+1);
        }
        printf("Case #%d: %.6f\n",cs,ans);
        //cout<<"Case #"<<cs<<": "<<ans<<"\n";

    }
    return 0;
}
