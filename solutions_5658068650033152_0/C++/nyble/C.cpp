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
        int n,m,k,ans;
        cin>>n>>m>>k;
        if(k<=4)
            ans=k;
        else if(k==n*m)
        ans=n+n+2*(m-2);
        else
        {
            int s = n+n+2*(m-2);
            if(k>=(n*m-4))
                ans=s-4;
            else
            {
                if(k==5)ans=4;
                if(k==6)ans=5;
                if(k==7)ans=6;
                if(k==8)ans=6;
                if(k==9)ans=7;
                if(k==10)ans=8;
                if(k==11)ans=8;
                if(k==12)ans=9;
                 if(k==13)ans=10; if(k==14)ans=10; if(k==15)ans=11;
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
