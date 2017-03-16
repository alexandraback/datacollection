/*
 * =====================================================================================
 *
 *       Filename: B_small
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016-04-30-22.45.00, Saturday
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


string AA, BB, ssa, ssb;
int diff, lena, lenb, ResA, ResB;

void REC(int posa, int posb, int A, int B)
{
    if(posa==lena && posb==lena)
    {
        int ldiff = abs(A-B);
        if(ldiff<diff)
        {
            diff = ldiff;
            ResA = A;
            ResB = B;
        }
        else if(ldiff==diff)
        {
            if(ResA>A) ResA = A;
            if(ResB>B) ResB = B;
        }
        return ;
    }
    REP(i,0,9)
    {
        REP(j,0,9)
        {
            int toA = (posa<lena && AA[posa]=='?')? i: (AA[posa]-'0');
            int toB = (posb<lena && BB[posb]=='?')? j: (BB[posb]-'0');
            REC(posa+(posa<lena?1:0), posb+(posb<lena?1:0),(A*10+toA), (B*10+toB));
        }
    }

}

int main(int argc, const char **argv)
{
    //ios::sync_with_stdio(false);
    freopen("/home/mkg/Desktop/Round 1B 2016/B-small-attempt0.in","r",stdin);
    freopen("/home/mkg/Desktop/Round 1B 2016/B-small-attempt0.out","w",stdout);
    int Test;
    cin>>Test;
    REP(kase,1,Test)
    {
        cin>>AA>>BB;
        lena = SZ(AA);
        lenb = SZ(BB);
        if(lena<lenb)
        {
            string to ="";
            REP(i,0,(lenb-lena)) to += "0";
            to = to + AA;
            AA = to;
        }
        if(lenb<lena)
        {
            string to ="";
            REP(i,0,(lena-lenb)) to += "0";
            to = to + BB;
            BB = to;
        }
        if(lena<lenb) lena = lenb;
        else lenb = lena;
        diff = ResA = ResB = 100000000;
        REC(0,0,0,0);
        ssa = to_string(ResA);
        ssb = to_string(ResB);
        if(lena!=SZ(ssa))
        {
            string to ="";
            REP(i,0,(lena-SZ(ssa))-1) to += "0";
            to = to + ssa;
            ssa = to ;
        }
        if(lena!=SZ(ssb))
        {
            string to ="";
            REP(i,0,(lena-SZ(ssb))-1) to += "0";
            to = to + ssb;
            ssb = to ;
        }
        cout<<"Case #"<<kase<<": "<<ssa<<" "<<ssb<<endl;
    }
    //double st=clock(),en;
    //en=clock();
    //cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}


