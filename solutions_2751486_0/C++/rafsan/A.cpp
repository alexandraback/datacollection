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
#define INFILE() freopen("A-small-attempt0.in","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define IN scanf
#define OUT printf
#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 10007
#define LIM 4

//TYPE conversion
template<typename T>inline string toString(T a){ostringstream os("");os<<a;return os.str();}
template<typename T>inline LL toLong(T a){LL res;istringstream os(a);os>>res;return res;}
//MATHEMATICS
template<typename T>inline T  SQ(T a){return a*a;}
template<typename T>inline T GCD(T a, T b){if (b == 0)return a;else return GCD(b, a % b);}
template<typename T>inline ULL BIGMOD(T a, T b, T m){if (b == 0)return 1;else if (b % 2 == 0)return SQ(BIGMOD(a, b / 2, m)) % m;else return (a % m*BIGMOD(a, b - 1, m)) % m;}
template<typename T>inline VS PARSE(T str){VS res;string s;istringstream os(str);while(os>>s)res.PB(s);return res;}
template<typename T>inline ULL  DIST(T A,T B){ULL res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);return res;}
template<typename T>inline double cosAngle(T a,T b,T c){double res=a*a+b*b-c*c;res=res/(2*a*b);res=acos(res);return res;}
template<typename T>inline T POWER(T base,int po){T res=1;if(base==0)return 0;FOR(i,0,po)res*=base;return res;}
//BIT
template<typename T>inline bool IS_ON(T mask,T pos){return mask&(1<<pos);}
template<typename T>inline int OFF(T mask,T pos){return mask^(1<<pos);}
template<typename T>inline int ON(T mask,T pos){return mask|(1<<pos);}
//MOVEMENT INSIDE GRID
template<typename T>inline bool INSIDE_GRID(int R,int C,int ro,int clm){if(R>=0&&C>=0&&R<ro&&C<clm)return 1;return 0;}

//int dx[]= {0,0,1,-1};
//int dy[]= {-1,1,0,0};
char str[1000010];
bool vowel(char ch)
{
    if(ch=='a')return 1;
    if(ch=='e')return 1;
    if(ch=='i')return 1;
    if(ch=='o')return 1;
    if(ch=='u')return 1;
    return 0;
}
int main()
{
    int ks,ind,last,len,n,cnt;
    LL res=0;
    INFILE();
    OUTFILE();
    cin>>ks;
    FOR(cas,1,ks+1)
    {
        cin>>str>>n;
        ind=0;
        res=cnt=last=0;
        len=strlen(str);
        while(ind<len)
        {
            if(vowel(str[ind]))cnt=0;
            else cnt++;
            if(cnt==n)
            {
                res+=1+(1+ind-n-last)+(len-ind-1);
                res+=(LL)(ind+1-n-last)*(LL)(len-ind-1);
                cnt--;
                last=(ind+1-n)+1;
            }
            ind++;
        }
        cout<<"Case #"<<cas<<": "<<res<<endl;
    }
    return 0;
}
/*

*/
