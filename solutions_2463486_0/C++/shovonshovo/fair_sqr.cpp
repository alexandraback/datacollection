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
#define lim 1000

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


ll gun[20];


int mid=500;
    int arr[20];



int main()
{
    vector<ll>v;
    INFILE();
    OUTFILE();
    int i,j;
    ll x;
    int cnt=0;
    FOR(i,1,10000001){

        x=i;
        j=0;
        bool st=1;
        while(x!=0){
            arr[j]=(x%10);

            j++;
            x/=10;
        }




        x=0;

        j--;
        while(x<j){



            if(arr[x]==arr[j]){
                x++;j--;
            }
            else {
                st=0;
                break;
            }
        }


        if(!st)continue;
        x=i;
        x*=x;
        j=0;

        while(x!=0){
            arr[j]=(x%10);
            j++;
            x/=10;
        }

        x=0;
        j--;
        while(x<j){
            if(arr[x]==arr[j]){
                x++;j--;
            }
            else {
                st=0;
                break;
            }
        }

        if(st){
        ll x=i;
        x*=x;
        v.pb(x);

        }


    }

    int ks,cas;
    ll a,b;
    scanf("%d",&ks);
    FOR(cas,1,ks+1){
        int res=0;
        scanf("%lld%lld",&a,&b);
        FOR(i,0,39){
            if(v[i]>=a && v[i]<=b)res++;
        }
        printf("Case #%d: %d\n",cas,res);
    }

    return 0;
}
