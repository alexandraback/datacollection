// Coder nyble
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<string> vs;

#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(__typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())
#define nl          printf("\n")

int main()
{
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        long long a,b,k,temp;
        long long ways=0;
        cin>>a>>b>>k;

        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }

        if(a<=k)
            ways = a*b;
        else
        {
            ways+= (k*b);
            ways+= (a-k)*k;
            for(long long i = k ; i<a ; i++)
            {
                for(long long j = k ; j<b ; j++)
                {
                    if( (i&j)<k ) ways++;
                }
            }
        }

        printf("Case #%d: %lld\n",z,ways);
    }
    return 0;
}
