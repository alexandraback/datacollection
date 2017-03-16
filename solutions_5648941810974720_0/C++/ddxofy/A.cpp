/*
 * =====================================================================================
 *
 *       Filename: A
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016-04-30-22.15.40, Saturday
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
string NUM;
vector<int> cell_no;
int CNT[500];

int main(int argc, const char **argv)
{
    //ios::sync_with_stdio(false);
    freopen("/home/mkg/Desktop/Round 1B 2016/A-small-attempt0.in","r",stdin);
    freopen("/home/mkg/Desktop/Round 1B 2016/A-small-attempt0.out","w",stdout);

    //double st=clock(),en;
    int Test;
    cin>>Test;
    REP(kase,1,Test)
    {
        cin>>NUM;
        cell_no.clear();
        int L = SZ(NUM);
        mem(CNT,0);
        REP(i,0,(L-1))
        {
            CNT[NUM[i]]++;
        }
        if(CNT['X'])
        {
            while(CNT['X'])
            {
                CNT['X']--;
                CNT['S']--;
                CNT['I']--;
                cell_no.pb(6);
            }
        }
        if(CNT['U'])
        {
            while(CNT['U'])
            {
                CNT['U']--;
                CNT['F']--;
                CNT['O']--;
                CNT['R']--;
                cell_no.pb(4);
            }
        }
        if(CNT['W'])
        {
            while(CNT['W'])
            {
                CNT['T']--;
                CNT['W']--;
                CNT['O']--;
                cell_no.pb(2);
            }
        }
        if(CNT['Z'])
        {
            while(CNT['Z'])
            {
                CNT['Z']--;
                CNT['E']--;
                CNT['O']--;
                CNT['R']--;
                cell_no.pb(0);
            }
        }
        if(CNT['G'])
        {
            while(CNT['G'])
            {
                CNT['G']--;
                CNT['H']--;
                CNT['E']--;
                CNT['T']--;
                CNT['I']--;
                cell_no.pb(8);
            }
        }
        if(CNT['O'])
        {
            while(CNT['O'])
            {
                CNT['O']--;
                CNT['N']--;
                CNT['E']--;
                cell_no.pb(1);
            }
        }
        if(CNT['R'])
        {
            while(CNT['R'])
            {
                CNT['R']--;
                CNT['T']--;
                CNT['H']--;
                CNT['E']--;
                CNT['E']--;
                cell_no.pb(3);
            }
        }
        if(CNT['F'])
        {
            while(CNT['F'])
            {
                CNT['F']--;
                CNT['I']--;
                CNT['V']--;
                CNT['E']--;
                cell_no.pb(5);
            }
        }
        if(CNT['V'])
        {
            while(CNT['V'])
            {
                CNT['V']--;
                CNT['S']--;
                CNT['N']--;
                CNT['E']--;
                CNT['E']--;
                cell_no.pb(7);
            }
        }
        if(CNT['N'])
        {
            while(CNT['N'])
            {
                CNT['N']--;
                CNT['I']--;
                CNT['N']--;
                CNT['E']--;
                cell_no.pb(9);
            }
        }
        sort(BE(cell_no));
        cout<<"Case #"<<kase<<": ";
        for(auto &a : cell_no) cout<<a;
        cout<<endl;
    }
    //en=clock();
    //cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}


