/**********************************
 *          Vinit Gandhi          *
 *  L. D. College of Engineering  *
 **********************************/
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define ll   long long
#define SIGN(x) (((x)>0)-((x)<0))
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a)   ((ll)(a).size())
#define FILL(a,x)   memset(a, (x), sizeof((a)));
#define IN(l,i,r)   ((l)<(i)&&(i)<(r))
#define LIN(l,i,r)  ((l)<=(i)&&(i)<(r))
#define INR(l,i,r)  ((l)<(i)&&(i)<=(r))
#define LINR(l,i,r) ((l)<=(i)&&(i)<=(r))
#define cmp_db(a,b) (abs(b-a)<eps)
#define is_int(a)   (cmp(a,0))
#define FOR(i,b,e,s)  for(i=(b);SIGN(s)*i<SIGN(s)*(e);i+=(s))
#define FORE(it,a)    for(auto &it : (a))
#define PRESENT(c,x)  ((c).find(x)!=(c).end())
#define CPRESENT(c,x) (find(ALL(c),x)!=(c).end())
#define nl         cout<<'\n'

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll mod=1e9+7;
const double pi=acos(-1.0);
const double eps=1e-6;
const int MAX_SIZE=100;
const int dX[]={-1, 1, 0, 0,-1, 1,-1, 1};
const int dY[]={ 0, 0,-1, 1, 1,-1,-1, 1};

template<class S, class T> ostream& operator<<(ostream& o,const pair<S,T>& a)  {o<<a.FI<<" "<<a.SE<<" "; return o;}
template<class S, class T> ostream& operator<<(ostream& o,const map<S,T>& a)   {FORE(it,a) o<<(it); return o;}
template<class S> ostream& operator<<(ostream& o,const vector<S>& a)           {FORE(it,a) o<<(it)<<" ";  o<<"\n"; return o;}
template<class S> ostream& operator<<(ostream& o,const vector<vector<S> >& a)  {FORE(it,a) o<<(it); return o;}
template<class S> ostream& operator<<(ostream& o,const set<S>& a)              {FORE(it,a) o<<(it)<<" "; o<<"\n"; return o;}
const ll MAX=55;
int grid[MAX][MAX];
int toBinary[MAX];
int main()
{
    IOS;
    int i, j, t, T;
    ll B, M;
    cin>>T;
    FOR(t, 0, T, 1)
    {
        FOR(i, 0, MAX, 1)
        {
            FOR(j, 0, MAX, 1)
                grid[i][j]=0;
        }
        cout<<"Case #"<<t+1<<": ";
        cin>>B>>M;
        if(M>(1<<(B-2)))
            cout<<"IMPOSSIBLE\n";
        else
        {
            cout<<"POSSIBLE\n";
            M--;
            FILL(toBinary,0);
            i=B-3;
            while(M)
            {
                toBinary[i]=(M&1);
                M>>=1;
                i--;
            }
            FOR(i, 0, B, 1)
            {
                if(toBinary[i])
                {
                    FOR(j, i+1, B, 1)
                        grid[i][j]=1;
                }
                grid[i][i+1]=1;
            }
            FOR(i, 0, B, 1)
            {
                FOR(j, 0, B, 1)
                {
                    cout<<grid[i][j];
                }
                nl;
            }
        }
    }
    return 0;
}
