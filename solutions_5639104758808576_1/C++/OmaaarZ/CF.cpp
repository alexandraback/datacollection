#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define LL long long
using namespace std;


int main()
{
  freopen("A-large.in","r",stdin);
   freopen("output.in","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >>t;
    int tc=1;
    while(t--)
    {
        int s;
        cin >> s;
        string t;
        cin>>t;
        int counter=0;
        int need=0;
        for(int  i= 0 ; i <=s;i++)
        {
            if(counter < i)
            {
                need += i-counter;
                counter=i;
            }
            counter += t[i]-'0';
        }
        cout << "Case #" <<tc++<<": " << need <<endl;
    }
    return 0;
}


