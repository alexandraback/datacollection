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
