#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int x,r,c;
        cin>>x>>r>>c;
        if(r<c)
            swap(r,c);
        cout<<"Case #"<<tc<<": ";
        string s="GABRIEL\n",s1="RICHARD\n";
        if(x==1)
            cout<<s;
        else if(x==2)
            if((r*c)%2==0)
                cout<<s;
            else
                cout<<s1;
        else if(x==3)
            if((r*c)%3==0&&c>1)
                cout<<s;
            else
                cout<<s1;
        else if(r==4&&c>=3)
            cout<<s;
        else
            cout<<s1;
    }
}
