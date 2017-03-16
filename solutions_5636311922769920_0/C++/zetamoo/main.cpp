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
    int t=0;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int k,c,s;
        cin>>k>>c>>s;
        cout<<"Case #"<<tc<<":";
        for(int f=1;f<=s;f++)
        cout<<" "<<f;
        cout<<endl;
    }
}
