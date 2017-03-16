#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(arr,e) for (typeof((arr).begin()) e=(arr).begin();e!=(arr).end();++e)
#define fsubset(subset,set) for (int subset=set&(set-1);subset;subset=(subset-1)&set)
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end());
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf
#define pdb(prcs,x) printf("%."#prcs"f",(abs(x)<1e-##prcs)?0.0:x)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)

#define lowbit(i) (i&(-i))

typedef long long int LL;
typedef pr<int,int> pii;
typedef pr<LL,LL> pll;
typedef pr<double,double> pdd;
typedef pr<string,int> psi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<char,int> mci;
typedef que<int> qi;
typedef prq<int> pqi;
typedef vector<int> veci;
typedef vector<bool> vecb;
typedef vector<string> vecs;
typedef vector<double> vecdb;

const int oo=(~0u)>>1;
const LL lloo=(~0ull)>>1;
const int INF = 0x7f7f7f7f;
const double dboo=1e+20;
const double eps=1e-8;
const double pi=acos(-1.0);
const int MOD=1000000007;

LL getLL(char * str)
{
    LL num = 0;
    LL wei = 1;
    int len = strlen(str);
    for (int i = len - 1; i >= 0 ; --i)
    {
        num += (str[i] - '0')*wei;
        wei *= 10;
    }
    return num;
}
char data[190000];
LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
void getpq(int tt)
{
    int p = 1;
    while(data[p] != '/') p++;
    data[p] = 0;
    LL fenzi = getLL(data+1);
    LL fenmu = getLL(&data[p+1]);
    LL fuck = gcd(fenzi,fenmu);

    fenzi /= fuck;
    fenmu /= fuck;

    if(fenmu != lowbit(fenmu))
    {
        pf("Case #%d: impossible\n",tt);
        return ;
    }
    while(fenzi != 1)
    {
        fenmu /= 2;
        fenzi /= 2;
    }
    int cnt = 1;
    while(fenmu != 2)
        fenmu /= 2,cnt++;
    pf("Case #%d: %d\n",tt,cnt);

}
int T;

int main(int argc, char *argv[])
{
    sf("%d",&T);
    ft(tt,1,T)
    {
        sf("%s",data + 1);
        getpq(tt);
    }
    return 0;
}