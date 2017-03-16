/*
 * =====================================================================================
 *
 *       Filename: C_small
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016-04-30-23.27.07, Saturday
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Md. Khairullah Gaurab (),
 *   Organization:  Shahjalal University of Science and Technology
 *
 * =====================================================================================
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<Long, Long> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<DD> VD;
typedef vector<Long> VL;
typedef vector<VL> VVL;

const int INF = 2000000000;
const int MOD = 1000000007;
const Long L_MAX = 9223372036854775807;
const int I_MAX = 2147483647;


#define sf scanf
#define pf printf
#define mem(a,b)          memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b)        for(int i=a; i<=b; ++i)
#define REPI(i,a,b,c)     for(int i=a; i<=b; i+=c)
#define REPR(i,a,b)       for(int i=b; i>=a; --i)
#define REPRD(i,a,b,c)    for(int i=b; i>=a; i-=c)
#define REPB(i,a)         for(int i=a; ;i++)
#define REPRB(i,a)        for(int i=a; ; i--)
#define mp(a,b)   make_pair(a,b)
#define fs        first
#define sc        second
#define SZ(s)     ((int)s.size())
#define PI        3.141592653589793
#define lim       1007
#define tlim      (1<<((int)ceil(log2(lim))+1))
#define unq(vec)  stable_sort(vec.begin(),vec.end());\
				  vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)     a.begin(),a.end()
#define rev(a)    reverse(BE(a))
#define sorta(a)  stable_sort(BE(a))
#define sortc(a, comp)  sort(BE(a),comp)

//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};//knight move
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};//8 move
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};//4 move

string first[17],last[17];
int n,memo[1<<16];

int REC(int mask)
{
    if(__builtin_popcount(mask)==n)return 0;
    if(memo[mask]!=-1)return memo[mask];
    int ret=0;
    for(int i=0; i<n; i++)
    {
        if(!(mask&(1<<i)))
        {
            bool ff=0,fl=0;
            for(int j=0; j<n; j++)
            {
                if(mask&(1<<j))
                {
                    if(first[i]==first[j])ff=1;
                    if(last[i]==last[j])fl=1;
                }
            }
            if(ff&&fl)ret=max(ret,1+REC(mask|(1<<i)));
            else ret=max(ret,REC(mask|(1<<i)));
        }
    }
    return memo[mask]=ret;
}



int main(int argc, const char **argv)
{
    //ios::sync_with_stdio(false);
    freopen("/home/mkg/Desktop/Round 1B 2016/C-small-attempt0.in","r",stdin);
    freopen("/home/mkg/Desktop/Round 1B 2016/C-small-attempt0.out","w",stdout);
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>first[i]>>last[i];
        }
        mem(memo,-1);
        cout<<"Case #"<<z<<": "<<REC(0)<<"\n";
    }
    //double st=clock(),en;
    //en=clock();
    //cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}


