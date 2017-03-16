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
        long long n,k;
        cin>>n>>k;
        cout<<"Case #"<<tc<<": ";
        if((1ll<<(n-2))<k)
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        string b;
        cout<<"POSSIBLE\n";
        k--;
        while(k)
        {
            b+='0'+k%2;
            k/=2;
        }
        while(b.size()!=n-1)
            b+='0';
        reverse(b.begin(),b.end());
        b+='1';
        cout<<b<<endl;
        for(int f=1;f<n;f++)
        {
            for(int f1=0;f1<n;f1++)
            {
                if(f1<=f)
                    cout<<'0';
                else
                    cout<<'1';
            }
            cout<<endl;
        }
    }
    return 0;
}
