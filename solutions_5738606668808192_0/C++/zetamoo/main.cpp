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
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

void rev(long long &x)
{
    stack<int>s;
    while(x)
    {
        s.push(x%2);
        x/=2;
    }
    while(s.size())
    {
        x=(x*2+s.top());
        s.pop();
    }
}

bool check(long long x)
{
    int arr[11]={0};
    for(int f=2;f<11;f++)
    {
        for(int f1=2;f1<10&&!arr[f];f1++)
        {
            long long y=x,sum=0;
            rev(y);
            while(y)
            {
                sum=(sum*f+y%2)%f1;
                y/=2;
            }
            if(sum==0)
                arr[f]=f1;
        }
        if(arr[f]==0)
            return 0;
    }
    rev(x);
    while(x)
    {
        cout<<x%2;
        x/=2;
    }
    for(int f=2;f<=10;f++)
        cout<<" "<<arr[f];
    cout<<endl;
    return 1;
}

int dc()
{
    int sum=0;
    for(long long f=(1ll<<16)-1;f>0;f-=2)
    {
        sum+=check(f);
        if(sum>=50)
            return 1;
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cout<<"Case #1:\n";
    dc();
    int t=0;
    //cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        string s;
        cin>>s;
        cout<<"Case #"<<tc<<": ";
        int ans=0;
        for(int f=0;f<s.size();f++)
        {
            if(f)
            {
                if(s[f]!=s[f-1])
                    ans++;
            }
        }
        if(s[s.size()-1]=='-')
            ans++;
        cout<<ans<<endl;
    }
}
