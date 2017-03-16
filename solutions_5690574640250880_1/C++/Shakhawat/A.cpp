#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>

using namespace std;


int main()
{
    int T,cased=0;
    double ans,c,f,x,speed,temp;
    freopen("c.txt","r",stdin);
    freopen("b.txt","w",stdout);
    cin>>T;
    while(T--)
    {

        cin>>c>>f>>x;
        speed=2;
        temp=0;
        ans=x/2.0;
        while(temp+c/speed<=ans)
        {
           temp+=c/speed;
           speed+=f;
           ans=min(ans,temp+x/speed);
        }
      printf("Case #%d: %0.7lf\n",++cased,ans);
    }
}
