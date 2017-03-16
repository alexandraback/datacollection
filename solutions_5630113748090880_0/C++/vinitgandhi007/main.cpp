/*
 * Vinit Gandhi
 * L.D. College of Engineering
 */
#include <bits/stdc++.h>
#if __cplusplus>199711L
    #define typeof decltype
#endif
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define ll   long long
#define ld   long double
#define SIGN(x) (((x)>0)-((x)<0))
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a)   ((ll)(a).size())
#define FILL(a,x)   memset(a, (x), sizeof((a)));
#define IN(l,i,r)   ((l)<(i)&&(i)<(r))
#define LIN(l,i,r)  ((l)<=(i)&&(i)<(r))
#define INR(l,i,r)  ((l)<(i)&&(i)<=(r))
#define LINR(l,i,r) ((l)<=(i)&&(i)<=(r))
#define cmp_db(a,b) (abs(b-a)<eps)
#define is_int(a)   (cmp_db(a,0))
#define FOR(i,b,e,s)  for(i=(b);SIGN(s)*i<SIGN(s)*(e);i+=(s))
#define FORE(it,a)    for(typeof((a).begin())it=(a).begin();it!=(a).end();it++)
#define PRESENT(c,x)  ((c).find(x)!=(c).end())
#define CPRESENT(c,x) (find(ALL(c),x)!=(c).end())
#define nl         cout<<'\n'

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll mod=1e9+7;
const ld pi=acos(-1.0);
const ld eps=1e-9;
const int MAX_SIZE=50;
const int dX[]={-1, 1, 0, 0,-1, 1,-1, 1};
const int dY[]={ 0, 0,-1, 1, 1,-1,-1, 1};

template<class S, class T> ostream& operator<<(ostream& o,const pair<S,T>& a)  {o<<a.FI<<" "<<a.SE; return o;}
template<class S, class T> ostream& operator<<(ostream& o,const map<S,T>& a)   {FORE(it,a) o<<(*it)<<"\n"; return o;}
template<class S> ostream& operator<<(ostream& o,const vector<S>& a)           {FORE(it,a) o<<*it<<" "; return o;}
template<class S> ostream& operator<<(ostream& o,const vector<vector<S> >& a)  {FORE(it,a) {o<<(*it)<<"\n";} return o;}
template<class S> ostream& operator<<(ostream& o,const set<S>& a)              {FORE(it,a) o<<*it<<" "; return o;}
const ll MAX=55;
int main()
{
    IOS;
    int i, j, k, N, T, h;
    cin>>T;
    FOR(i, 0, T, 1)
    {
        map<int, int> m;
        vi ans;
        cout<<"Case #"<<i+1<<": ";
        cin>>N;
        FOR(j, 0, 2*N-1, 1)
        {
            FOR(k, 0, N, 1)
            {
                cin>>h;
                m[h]++;
            }
        }
        FORE(it, m)
        {
            if((it->SE)%2)
            {
                ans.PB(it->FI);
            }
        }
        sort(ALL(ans));
        FOR(j, 0, SZ(ans), 1)
        {
            cout<<ans[j]<<" ";
        }
        nl;
    }
    return 0;
}
