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
#include <cstring>
#include <ctime>
using namespace std;
#define   sqr(a)         ((a)*(a))
#define   rep(i,a,b)  for(int i=(a);i<(int)(b);i++)
#define   per(i,a,b)  for(int i=((a)-1);i>=(int)(b);i--)
#define   PER(i,n)     per(i,n,0)
#define   REP(i,n)     rep(i,0,n)
#define   FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define   clr(a)      memset((a),0,sizeof (a))
#define   SZ(a)         ((int)((a).size()))
#define   CLEAR(a, v)    memset((a), (v), sizeof(a))
#define   ALL(v)          (v).begin(), (v).end()
#define   mabs(a)       ((a)>0?(a):(-(a)))
#define   PB push_back
#define   FI     first
#define   SE     second
#define   MP     make_pair
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef long long int64;
#define   inf         1000000001
#define  MAXN     55
#define  eps      1e-6
FILE *fin;
FILE *fout;
int N,M;
set<pair<int,int> >sp;
string s[MAXN],ed,ans;
char cs[MAXN];
void checkit(vector<int> &vi)
{
    vector<int> vt;vt.PB(vi[0]);
    string ret=s[vi[0]];
    rep(i,1,SZ(vi))
    {
        while(!vt.empty()&&sp.count(MP(vt.back(),vi[i]))==0) vt.pop_back();
        if(vt.empty()) return;
        vt.PB(vi[i]);ret+=s[vi[i]];
    }
    if(ans==ed) ans=ret;
    else checkmin(ans,ret);
}
int main()
{
   	fin=fopen("C-small-attempt1.in","r");
	fout=fopen("output.txt","w");
	int T;
	fscanf(fin,"%d",&T);
    int rounds;
	for (rounds=1;rounds<=T;rounds++)
	{
        fscanf(fin,"%d%d",&N,&M);
        REP(i,N)
        {
            fscanf(fin,"%s",cs); s[i]=string(cs);
        }
        sp.clear();
        REP(i,M)
        {
            int u,v;fscanf(fin,"%d%d",&u,&v); u--,v--; sp.insert(MP(u,v)),sp.insert(MP(v,u));
        }
        cs[0]='z'+1,cs[1]=0; ed=string(cs);
        ans=ed;
        vector<int> vi;REP(i,N) vi.PB(i);
        do
        {
            checkit(vi);
        }while(next_permutation(ALL(vi)));

            printf("Case #%d: %s\n",rounds,ans.c_str());
            fprintf(fout,"Case #%d: %s\n",rounds,ans.c_str());

    }
}
