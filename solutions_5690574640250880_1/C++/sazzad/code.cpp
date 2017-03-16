
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <limits>
#include <utility>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace std;

const int INF=(1<<30)-1;
const long long LINF=(1ll<<62)-1;
const int DIRX[]={-1,0,0,1,-1,-1,1,1}, DIRY[]={0,-1,1,0,-1,1,-1,1};
const double ERR=1e-11, PI=(2*acos(0.0));

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
template<class T> inline T MIN(T a,T b) {return ((a<b)?(a):(b));}
template<class T> inline T MAX(T a,T b) {return ((b<a)?(a):(b));}
template<class T> inline T ABS(T a) {return ((a<0)?(-a):(a));}
template<class T> inline void checkMIN(T& a,T b) {if(b<a) a=b;}
template<class T> inline void checkMAX(T& a,T b) {if(a<b) a=b;}
template<class T> inline T SQR(T x) {return (x*x);}
template<class T> inline T GCD(T a,T b) {T c; while((c=a%b)!=0)a=b,b=c; return b;}
template<class T> inline T fastPow(T Base,T Power) {T Result=1; while(Power>0){if(Power&1)Result*=Base; Power>>=1; Base*=Base;} return Result;}
template<class T> inline T fastModPow(T Base,T Power,T Mod) {T Result=1;while(Power>0){if(Power&1)Result=(Result*Base)%Mod; Power>>=1; Base=(Base*Base)%Mod;} return (Result%Mod);}
inline int compDouble(double x,double y) {double d=x-y; if(d-ERR>0.0) return 1; else if(d+ERR<0.0) return -1; else return 0;}

#define ALL(X)       (X).begin(),(X).end()
#define Size(X)      ((int)(X).size())
#define MEM(X,with)  memset((X),(with),sizeof(X))
#define EACH(X,itr)  for( __typeof((X).begin()) itr=(X).begin(); itr!=(X).end(); itr++)
#define Contains(X,item)    ((X).find(item)!=(X).end())
#define Contains_n(X,item)	(find((X).begin(),(X).end(),(item))!=(X).end())

typedef unsigned long long ULL;
typedef long long      LL;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL>     VL;
typedef vector<int>    VI;
typedef pair<int,int>  Pii;

#define N 52
char b[N][N];

int main()
{
//	freopen("in.txt","r",stdin);
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	int r, c, m, t, i, j, k, tt;
	int cases;scanf("%d",&cases);
	for(int caseno=1;caseno<=cases;caseno++) {
        scanf("%d%d%d",&r,&c,&m);
        t=r*c-m;
        printf("Case #%d:\n",caseno);
        
        bool imp=false;
        MEM(b,'.');
        b[1][1]='c';
        
        if(m==0) ;
        else if(t==1) {
            MEM(b,'*');
            b[1][1]='c';
        }
        else if(r==1 || c==1) {
            if(r==1) {
                for(j=c,k=m;k>0;j--,k--) {
                    b[1][j]='*';
                }
            }
            else {
                for(i=r,k=m;k>0;i--,k--) {
                    b[i][1]='*';
                }
            }
        }
        else if(r==2 || c==2) {
            if(m&1 || t==2) imp=true;
            else if(r==2) {
                for(j=c,k=m;k>0;j--,k-=2) {
                    b[1][j]=b[2][j]='*';
                }
            }
            else {
                for(i=r,k=m;k>0;i--,k-=2) {
                    b[i][1]=b[i][2]='*';
                }
            }
        }
        else {
            if(t==2 || t==3 || t==5 || t==7) imp=true;
            else if(t<=9) {
                MEM(b,'*');
                b[1][1]='c';
                b[1][2]=b[2][1]=b[2][2]='.';
                if(t>=6) b[3][1]=b[3][2]='.';
                if(t>=8) b[1][3]=b[2][3]='.';
                if(t==9) b[3][3]='.';
            }
            else {
                k=m;
                for(i=r;i>3;i--) {
                    for(j=c;j>0;j--) {
                        b[i][j]='*';
                        k--;
                        if(k<1) goto GO_1;
                    }
                }
                for(j=c;j>3;j--) {
                    for(i=3;i>0;i--) {
                        b[i][j]='*';
                        k--;
                        if(k<1) goto GO_2;
                    }
                }
                goto GO_N;
                
                GO_1:;
                if(j==2) {
                    b[i][j]='.';
                    b[i-1][c]='*';
                }
                goto GO_N;
                
                GO_2:;
                if(i==2) {
                    b[i][j]='.';
                    b[3][j-1]='*';
                }
                goto GO_N;
            }
        }
        
        GO_N:;
        if(imp) printf("Impossible\n");
        else {
            k=t=tt=0;
            for(int i=1;i<=r;i++,puts("")) {
                for(int j=1;j<=c;j++) {
                    printf("%c",b[i][j]);
                    switch (b[i][j]) {
                        case '*': k++;
                            continue;
                        case 'c': t++;
                            continue;
                        case '.': tt++;
                            continue;
                        default: {cerr<<caseno<<endl; exit(1);}
                    }
                }
            }
            if(k!=m) {cerr<<caseno<<endl; exit(2);}
            if(t!=1 || b[1][1]!='c') {cerr<<caseno<<endl; exit(3);}
            if(k+t+tt!=r*c) {cerr<<caseno<<endl; exit(4);}
        }
	}
	
	return 0;
}
