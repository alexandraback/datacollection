#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
#include <climits>

#define repx(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repx(i,0,n)
#define pb push_back
#define full(v)	v.begin(),v.end()
#define VI vector<int>
#define VS vector<string>
#define LL long long
using namespace std;

int main()
{
    int test,cas=0;
    ifstream cin("elfbig.in");
    ofstream cout("elfbigout.txt");
    cin>>test;
    while(test-- && ++cas)
    {
            string s;
            cin>>s;
            double nume = 0.0 , denom = 0.0;
            int i;
            for(i=0;s[i]!='/';i++)
            {
                nume = nume*10.0 + (int)(s[i]-'0');
            }
            for(++i; i<s.size() ; i++)
            {
                denom = denom * 10.0 + (int)(s[i] - '0');
            }

            double val = nume/denom;

             cout<<"Case #"<<cas<<": ";

            int ret = -1;
            bool b = true;
            for(i=0;i<=40;i++)
            {
                if(val >= (double)1.0 && b)
                {
                    ret = i;
                    b=false;
                }
                int temp = (int) val;
                double t2 = (double) temp;
                if(val == t2)
                     break;
                val = val*2;
            }

        if(i>40)
            cout<<"impossible\n";
        else
            cout<<ret<<"\n";
    }
    return 0;
}
