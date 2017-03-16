#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define A frist
#define B second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;


string s;
int main()
{
        freopen("B.in","r",stdin);
        freopen("B1out.txt","w",stdout);
    int T;
    cin>>T;
    rep(cas,T)
    {
        int x,y;
        cin>>x>>y;
        s = "";
        if(x>0)rep(i,x)s+="WE";
        else
        {
            x=-x;
            rep(i,x)s+="EW";
        }

        if(y>0)rep(i,y)s+="SN";
        else
        {
            y=-y;
            rep(i,y)s+="NS";
        }
        printf("Case #%d: ",cas+1);
        cout  << s <<endl;
    }
}
