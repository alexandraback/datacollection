#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<fstream>
#include<sstream>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<iomanip>
#include<ctime>
#include<complex>
using namespace std;


#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define pb push_back
#define MP make_pair
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi (acos(-1.0))
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define eps 1e-15
#define MOD 1E9 +7
#define lim 1000
#define fst first
#define sec second
//TYO conversion
template<typename T>inline string toString(T a){ostringstream os("");os<<a;return os.str();}
template<typename T>inline ll toLong(T a){ll res;istringstream os(a);os>>res;return res;}
//MATHEMATICS
template<typename T>inline T  SQ(T a){return a*a;}
template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline ull bigmod(T a, T b, T m){if (b == 0)return 1;else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;else return (a % m*bigmod(a, b - 1, m)) % m;}
template<typename T>inline VS parse(T str){VS res;string s;istringstream os(str);while(os>>s)res.pb(s);return res;}
template<typename T>inline ull  dist(T A,T B){ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);return res;}
template<typename T>inline double cosAngle(T a,T b,T c){double res=a*a+b*b-c*c;res=res/(2*a*b);res=acos(res);return res;}
template<typename T>inline T power(T base,int po){T res=1;if(base==0)return 0; FOR(i,0,po)res*=base;return res;}
//BIT
template<typename T>inline bool isOn(T mask,T pos){return mask&(1<<pos);}
template<typename T>inline int Off(T mask,T pos){return mask^(1<<pos);}
template<typename T>inline int On(T mask,T pos){return mask|(1<<pos);}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0 };
// n, s , e, w
map<pair<int,int>,int >M;
int DX,DY;
void print_res(int x , int y , int move){
    if(x==0 && y==0)return ;
    int i,X,Y;
    for(i=0;i<4;i++){
        X=x-dx[i]*move;
        Y=y-dy[i]*move;
        pii p=MP(X,Y);
        if(M.find(p)!=M.end()){
            if(M[p]==move-1){


                print_res(X,Y,move-1);

                if(i==0)printf("N");
                if(i==1)printf("S");
                if(i==2)printf("E");
                if(i==3)printf("W");

                return ;
            }
        }
    }
}

void simulate(string str){

    int len=str.length();
    cout<<len<<endl;
    int i,ind;
    int x,y;
    x=y=0;
    for(i=0;i<len;i++){
        if(str[i]=='S')ind=1;
        if(str[i]=='N')ind=0;
        if(str[i]=='E')ind=2;
        if(str[i]=='W')ind=3;

        x+=dx[ind]*(i+1);
        y+=dy[ind]*(i+1);
    }

    //cout<<" final "<<x<<" "<<y<<endl;
    return ;
}

void  bfs(int XX , int YY){

        if(!XX && !YY)return ;
        queue<pii>q;
        pii p=MP(0,0);
        int move=1,mv=0;
        M[p]=0;
        q.push(p);
        int x,y,i,X,Y;
        while(!q.empty()){
            pii pp=q.front();

            mv=M[pp];

            x=pp.fst;
            y=pp.sec;

            if(x==XX && y==YY){

                print_res(XX,YY,mv);
                return ;
            }
            ++mv;

            for(i=0;i<4;i++){
                X=x+mv*dx[i];
                Y=y+mv*dy[i];
                pii pn=MP(X,Y);
                if(M.find(pn)!=M.end())continue;
                q.push(pn);
                M[pn]=mv;
            }
             q.pop();
        }

}



int main(){

    INFILE();
    OUTFILE();
   // simulate("SENSEWW");
    //simulate("SENSE");


    string str;
    int len ,i ,j,k,n;
    int ks,cas,total=0;
    int x,y;
    cin>>ks;
    FOR(cas,1,ks+1){
        cin>>x>>y;
        M.clear();
        cout<<"Case #"<<cas<<": ";
        DX=x;
        DY=y;
        bfs(x,y);
        puts("");
//        cin>>str;
//        simulate(str);
    }

    return 0;
}
/*
SENSEWW

SENSE
*/
