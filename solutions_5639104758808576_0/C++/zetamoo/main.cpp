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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sum=0,ans=0;
        for(int f=0;f<=n;f++)
        {
            if(sum<f&&s[f]>'0')
                ans+=f-sum,sum=f;
            sum+=s[f]-'0';
        }
        cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
}
