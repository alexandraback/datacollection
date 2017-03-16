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
    ifstream cin("blotsmall.in");
ofstream cout("blotsmallout.txt");

int test=0,cas=0;
cin>>test;
while(test-- && ++cas)
{
    int a,b,k;
    cin>>a>>b>>k;
    int ret =0;
    rep(i,a)
    {
        rep(j,b)
        {
            if((int)(i&j) < k)
             ret++;
        }
    }

    cout<<"Case #"<<cas<<": "<<ret<<"\n";

}
return 0;
}
