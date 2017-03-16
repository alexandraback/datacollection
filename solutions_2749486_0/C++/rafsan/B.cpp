/*
uva :
author : rafsan
algo :
*/
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>
#include<functional>
#include<istream>
#include<iterator>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b-1);i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define PCC pair<char,char>
#define PIC pair<int,char>
#define PCI pair<char,int>
#define FST first
#define SEC second
#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)
#define RADIANS(x) (((1.0 * x * PI) / 180.0))
#define DEGREES(x) (((x * 180.0) / (1.0 * pi)))
#define SINE(x) (sin(RADIANS(x)))
#define COSINE(x) (cos(RADIANS(x)))
#define SETBIT(x, i) (x |= (1 << i))
#define TANGENT(x) (tan(RADIANS(x)))
#define ARCSINE(x) (DEGREES((asin(x))))
#define RESETBIT(x, i) (x &= (~(1 << i)))
#define ARCCOSINE(x) (DEGREES((acos(x))))
#define ARCTANGENT(x) (DEGREES((atan(x))))
#define INFILE() freopen("B-small-attempt0.in","r",stdin)
#define OUTFILE()freopen("outBsmall.txt","w",stdout)
#define IN scanf
#define OUT printf
#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 10007
#define LIM 4



int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
set<PII>st;
queue<pair<int,pair<int,int > > >q;
map<PII,pair<int,pair<int,int> > >parent;
pair<int,pair<int,int> >tmp;

void print(int x,int y)
{
   // cout<<x<<"-------->"<<y<<endl;
    if(x==0&&y==0)return ;
   pair<int,pair<int,int> > tmp1=parent[MP(x,y)];
    print(tmp1.FST,tmp1.SEC.FST);

    if(tmp1.SEC.SEC==0)printf("N");
    if(tmp1.SEC.SEC==1)printf("S");
    if(tmp1.SEC.SEC==2)printf("E");
    if(tmp1.SEC.SEC==3)printf("W");
   // cout<<tmp.FST<<tmp.SEC.FST<<"-->";
}
int main()
{
    int ks,ind,last,len,n,cnt,nx,ny,x,y;
    INFILE();
    OUTFILE();
    cin>>ks;

    FOR(cas,1,ks+1)
    {
        st.clear();
        parent.clear();
        cin>>x>>y;
        cout<<"Case #"<<cas<<": ";
        while(!q.empty())q.pop();

        q.push(MP(0,MP(0,1)));
        st.insert(MP(0,0));
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            if(tmp.FST==x&&tmp.SEC.FST==y)
            {
                //cout<<"got him\n";
                break;
            }
           // cout<<tmp.FST<<" "<<tmp.SEC.FST<<endl;
            //getchar();
            for(int i=0; i<4; i++)
            {
                nx=tmp.FST+tmp.SEC.SEC*(dx[i]);
                ny=tmp.SEC.FST+tmp.SEC.SEC*(dy[i]);
                if(st.find(MP(nx,ny))==st.end())
                {
                    //cout<<"   "<<nx<<" "<<ny<<endl;

                    q.push(MP(nx,MP(ny,tmp.SEC.SEC+1)));
                    st.insert(MP(nx,ny));
                    parent[MP(nx,ny)]=MP(tmp.FST,MP(tmp.SEC.FST,i));

                }
            }
           // cout<<"___________________________________\n";

        }
        print(x,y);
        cout<<endl;
    }
    return 0;
}
/*

*/
