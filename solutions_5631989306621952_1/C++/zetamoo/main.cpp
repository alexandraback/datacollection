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
        string s,ans;
        cin>>s;
        for(int f=0;f<s.size();f++)
        {
            if(ans.size()==0||s[f]<ans[0])
                ans+=s[f];
            else
                ans=s[f]+ans;
        }
        cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
    return 0;
}
