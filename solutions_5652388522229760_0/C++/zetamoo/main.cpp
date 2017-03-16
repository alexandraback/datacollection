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

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        long long n;
        cin>>n;
        cout<<"Case #"<<tc<<": ";
        if(n==0)
        {
            cout<<"INSOMNIA\n";
            continue;
        }
        bool dig[10]={0};
        for(int f=1;f<100000;f++)
        {
            long long x=f*n;
            while(x)
            {
                dig[x%10]=1;
                x/=10;
            }
            for(int f1=0;f1<10;f1++)
                if(!dig[f1])
                    break;
                else if(f1==9)
                {
                    cout<<f*n<<endl;
                    f=100000;
                    break;
                }
            if(f==99999)
            {
                cout<<"INSOMNIA\n";
            }
        }
    }
}
