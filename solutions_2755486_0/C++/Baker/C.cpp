//#pragma comment(linker, "/STACK:60000000")

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <assert.h>

using namespace std;

//Type Definition
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;

#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define Clear(x,with) memset(x,with,sizeof(x))
#define SZ(x) (int)x.size()
#define pb push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define setBit(mask,i) (mask|two(i))
#define contain(S,X) (((S)&two(X))!=0)
#define fs first
#define sc second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());
#define Find(x,y) ((int)x.find(y))

//For debugging
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;

//Important Functions
template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} //For Positive Negative No.
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return (int)R;}
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct edge{ int cost,node; edge(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const edge &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(edge a,edge b){ return a.cost < b.cost;} //Asc Sort by cost

#define INF (1<<28)
#define SIZE 3500000

struct data
{
    int day,left,right,strn;
    data(int d=0,int l=0,int r=0,int s=0)
    {
        day = d;
        left = l;
        right = r;
        strn = s;
    }
};
data ele[3500000];
vector<ll>points;
map<ll,int> ID;

ll tree[4*SIZE],upd[4*SIZE];

void initialize(int node,int left,int right)
{
    tree[node] = upd[node] = 0;
    if(left==right) return;
    int mid = (left+right)/2;
    initialize(node*2,left,mid);
    initialize(node*2+1,mid+1,right);
}

void pushDown(int node,int left,int right)
{
    tree[node] = max(tree[node],upd[node]);
    if(right-left)
    {
        upd[node*2] = max(upd[node*2],upd[node]);
        upd[node*2+1] = max(upd[node*2+1],upd[node]);
    }
    upd[node] = 0;
}

void pushUp(int node)
{
    tree[node] = min(tree[node*2],tree[node*2+1]);
}

void update(int node,int left,int right,int l,int r,ll val)
{
    if(upd[node]) pushDown(node,left,right);
    if(l<=left && right<=r)
    {
        upd[node] = val;
        pushDown(node,left,right);
        return;
    }
    if(left>r || right<l) return;
    int mid = (left+right)/2;
    update(node*2,left,mid,l,r,val);
    update(node*2+1,mid+1,right,l,r,val);
    pushUp(node);
}

ll query(int node,int left,int right,int l,int r)
{
    if(upd[node]) pushDown(node,left,right);
    if(right<l || left>r) return twoL(50);
    if(l<=left && right<=r) return tree[node];
    int mid = (left+right)/2;
    ll p1 = query(node*2,left,mid,l,r);
    ll p2 = query(node*2+1,mid+1,right,l,r);
    return min(p1,p2);
}

bool comp(data p,data q)
{
    return p.day<q.day;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    int i,j,test,Case=1,N,cnt;
    int d,n,w,e,s,del_d,del_p,del_s;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&N);
        cnt = 0;
        points.clear();
        for(i=0;i<N;i++)
        {
            scanf("%d %d %d %d %d %d %d %d",&d,&n,&w,&e,&s,&del_d,&del_p,&del_s);
            ele[cnt++] = data(d,w*2,e*2,s);
            points.pb(w*2);
            points.pb(w*2+1);
            points.pb(e*2);
            points.pb(e*2+1);
            while(--n) {
                d = d+del_d;
                w += del_p;
                e += del_p;
                s += del_s;
                ele[cnt++] = data(d,w*2,e*2,s);
                points.pb(w*2);
                points.pb(w*2+1);
                points.pb(e*2);
                points.pb(e*2+1);
            }
        }
        int totalAttack = cnt;

        sort(&ele[0],&ele[cnt],comp);
        Sort(points); ID.clear();
        Unique(points);
        for(i=0;i<SZ(points);i++)
        {
            ID[points[i]] = i;
        }
        N = i;
        initialize(1,0,N-1);

//        debug("cnt:",cnt);
        int ans = 0;
        for(i=0;i<cnt;i++)
        {
            int curDay = ele[i].day;
            vector<int>toUpd;
            for(j=i;j<cnt;j++)
            {
                if(ele[j].day==curDay)
                {
                    ll mn = query(1,0,N-1,ID[ele[j].left],ID[ele[j].right]);
//                    debug(curDay,ID[ele[j].left],ID[ele[j].right],mn,ele[j].strn);
                    if(mn<ele[j].strn){
                        ans++;
                        toUpd.pb(j);
                    }
                }
                else break;
            }
            i = j-1;
            for(j=0;j<SZ(toUpd);j++)
            {
                int ind = toUpd[j];
                update(1,0,N-1,ID[ele[ind].left],ID[ele[ind].right],ele[ind].strn);
            }
        }

        printf("Case #%d: %d\n",Case++,ans);

    }


    return 0;
}
