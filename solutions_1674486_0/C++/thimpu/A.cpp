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

using namespace std;

//Type Definition
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;

#define INF (1<<28)
#define SIZE 110
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
#define X first
#define Y second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)

//For debugging
template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void debug(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void debug(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<"\t"<<e6<<endl;}
template<class T> void debug(vector< vector<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;} cout<<endl;}
template<class T> void debug(vector< basic_string<T> > e,int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j];cout<<endl;} cout<<endl;}
template<class T> void debug(T e[SIZE][SIZE],int row,int col){int i,j;REP(i,row) {REP(j,col) cout<<e[i][j]<<" ";cout<<endl;}}

//Important Functions
template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} //For Positive Negative No.
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return (int)R;}
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
//string monthName[]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//string dayName[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct pq{ int cost,node; pq(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const pq &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(pq a,pq b){ return a.cost < b.cost;} //Asc Sort by cost

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
typedef struct S{
   int color;
   vector<int> el;
}vertex;

int FW[2001][2001];

//int ExtreemDFS(int v,vertex *vertices,int numvertices){
//    if(v == numvertices){
//        return 1;
//    }
//
//    if(vertices[v].color == WHITE){
//         vertices[v].color = GRAY;
//         for(int i=0;i<vertices[v].el.size();i++){
//             int x = ExtreemDFS(vertices[v].el[i],vertices,numvertices);
//             if(x ==1) return 1;
//         }
//         vertices[v].color = BLACK;
//     }
//     return 0;
//}
//
//int checkcycle(int v,vector<int>path,vertex *vertices,int numvertices){
//    vector<int>::iterator it;
//    vector<int>::iterator x;
//    it = find (path.begin(), path.end(), v);
//    for(x =it;x<path.end();x++)
//        vertices[*x].color = WHITE;
//    for(x =it;x<path.end();x++){
//        if(ExtreemDFS(*x,vertices,numvertices))
//            return 1;
//    }
//    for(x =it;x<path.end();x++)
//        vertices[*x].color = GRAY;
//
//    return 0;
//
//}
//
//long DFS(int v,vertex *vertices,int numvertices,vector<int> path){
//    long paths = 0;
//    if(v == numvertices){
//            return 1;
//    }
//    if(vertices[v].color == GRAY) {
//         if(checkcycle(v,path,vertices,numvertices)) return -1;
//    }
//    if(vertices[v].color == WHITE){
//        vertices[v].color = GRAY;
//        path.push_back(v);
//        for(int i=0;i<vertices[v].el.size();i++){
//            long x = DFS(vertices[v].el[i],vertices,numvertices,path);
//            vertices[vertices[v].el[i]].color = WHITE;
//            if(x == -1) return -1;
//            paths += x;
//        }
//        vertices[v].color = BLACK;
//    }
//    return paths % 1000000000;
//}
//
//int numpaths(int numvertices,int numedges,vertex *vertices){
//    vector<int> path;
//    long numpaths = 0;
//    numpaths = DFS(1,vertices,numvertices,path);
//    //printf("%d",numpaths);
//    if(numpaths>=2) return 1;
//    return 0;
//}

/*
  for all k in 1 to n
     for all i in 1 to n
       for all j in 1 to n
            Aij = Aij + ( Aik * Akij).
            */

int main(){

    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    int t,cas=1,n;
    scanf("%d",&t);
    while(t--)
    {
            int edgecount=0;
            int  numverts,nodes,numedges;
            scanf("%d",&nodes);

            for(int i=1;i<=nodes;i++)
             for(int j=1;j<=nodes;j++)
                FW[i][j]=0;

            for(int i=1;i<=nodes;i++)
            {
                scanf("%d",&n);
                 for(int j=0;j<n;j++)
                 {
                      int b;
                      scanf("%d",&b);
                       FW[i][b]=1;
                       edgecount++;
                 }
            }
            for(int k=1;k<=nodes;k++)
                for(int i=1;i<=nodes;i++)
                    for(int j=1;j<=nodes;j++)
                     FW[i][j]=FW[i][j]+(FW[k][j]*FW[i][k]);


//
//                int a,b;
//            while(edgecount < numedges){
//                scanf("%d %d",&a,&b);
//                verts[a].el.push_back(b);
//                edgecount++;
//                }
//printf("%d",FW[1][nodes]);
              int chk=0;
             for(int k=1;k<=nodes;k++)
                for(int i=1;i<=nodes;i++)
                   if(FW[k][i]>=2){
                      chk=1;
                      break;}
            if(chk)
            printf("Case #%d: Yes\n",cas++);
            else printf("Case #%d: No\n",cas++);
    }
    return 0;
}
