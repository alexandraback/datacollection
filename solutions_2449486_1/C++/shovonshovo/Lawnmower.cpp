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
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define eps 1e-9
#define MOD 1E9 +7
#define lim 4
#define lim 4
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

int arr[105][105];
int ok[105][105];
int typ[105];
vector<int>v[105];
int r,c;
void init(){
    FOR(i,1,101)v[i].clear();
    memset(typ,0,sizeof typ);

    FOR(i,1,r+1){
        FOR(j,1,c+1){
            scanf("%d",&arr[i][j]);
            v[arr[i][j] ].pb(i);
            v[arr[i][j] ].pb(j);
        }
    }
}

bool chk(int x, int y , int val){

    int i,j;
    i=1;
    bool st=1;
    for(i=1;i<=c;i++){
        if(arr[x][i]<=val)continue;
        else st=0;
    }
    if(st)return 1;

    st=1;
    for(i=1;i<=r;i++){
        if(arr[i][y]<=val)continue;
        else st=0;
    }

    if(st)return 1;
}

int main()
{
    INFILE();
    OUTFILE();

    int ks,cas;
    int i,j,k;
    int x,y;
    scanf("%d",&ks);
    for(cas=1;cas<=ks;cas++){
        scanf("%d%d",&r,&c);

        init();
        bool st=1;
        for(i=1;i<=100;i++){
            int sz=v[i].size();
            for(j=0;j<sz;j+=2){
                x=v[i][j];
                y=v[i][j+1];

                if(chk(x,y,i))continue;
                else {st=0;break;}
            }
        }

     printf("Case #%d: ",cas);
     if(st)puts("YES");
     else puts("NO");

    }

    return 0;
}
