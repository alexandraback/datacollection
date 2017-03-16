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
const int MAX_SIZE=50;
const int dX[]={-1, 1, 0, 0,-1, 1,-1, 1};
const int dY[]={ 0, 0,-1, 1, 1,-1,-1, 1};

template<class S, class T> ostream& operator<<(ostream& o,const pair<S,T>& a)  {o<<a.FI<<" "<<a.SE<<" "; return o;}
template<class S, class T> ostream& operator<<(ostream& o,const map<S,T>& a)   {FORE(it,a) o<<(it); return o;}
template<class S> ostream& operator<<(ostream& o,const vector<S>& a)           {FORE(it,a) o<<(it)<<" ";  o<<"\n"; return o;}
template<class S> ostream& operator<<(ostream& o,const vector<vector<S> >& a)  {FORE(it,a) o<<(it); return o;}
template<class S> ostream& operator<<(ostream& o,const set<S>& a)              {FORE(it,a) o<<(it)<<" "; o<<"\n"; return o;}
const ll MAX=30;
int main()
{
    IOS;
    int i, j, T, val; //1 for C>J 0 for C==J -1 for C<J;
    cin>>T;
    string C, J;
    FOR(i, 0, T, 1)
    {
        val=0;
        cout<<"Case #"<<i+1<<": ";
        cin>>C>>J;
        FOR(j, 0, SZ(C), 1)
        {
            if(C[j]=='?')
            {
                if(J[j]=='?')
                {
                    C[j]='0';
                    J[j]='0';
                    if(val==-1)
                        C[j]='9';
                    else if(val==1)
                        J[j]='9';
                }
                else
                {
                    if(val==0)
                        C[j]=J[j];
                    else if(val==-1)
                        C[j]='9';
                    else
                        C[j]='0';
                }
            }
            else if(J[j]=='?')
            {
                if(val==0)
                    J[j]=C[j];
                else if(val==-1)
                    J[j]='0';
                else
                    J[j]='9';
            }
            else
            {
                if(C[j]<J[j])
                    val=-1;
                else if(C[j]>J[j])
                    val=1;
            }
        }
        cout<<C<<" "<<J<<"\n";
    }
    return 0;
}
