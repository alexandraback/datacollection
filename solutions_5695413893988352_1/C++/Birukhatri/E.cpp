/********************************************
*                                           *
*    Solved By : Bir Bahadur Khatri(B'ru)   *
*      Be Positive,be Happy.                *
*                                           *
*********************************************/

#define ff first
#define D double
#define sz size()
#define ss second
#define PB push_back
#define SQR(n) (n*n)
#define CHR getchar()
#define NL printf("\n")
#include<bits/stdc++.h>
#define ULL unsigned LL
#define PI 2.0*acos(0.0)
#define MP make_pair
#define LL long long int
#define S1(a) a=in<int>()
#define SL1(a) a=in<LL>()
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define S2(a,b) a=in<int>(),b=in<int>()
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define cp printf("***** here here here here *****\n");
#define trace1(x)                cerr << #x << ": " << x << endl;
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

using namespace std;
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }

///**********************************************************//

#define MD1 1000000007ULL
#define MD2 1000000009ULL
#define MD3 1000000021ULL
#define BS1 10000019ULL
#define BS2 10000079ULL
#define BS3 10000103ULL
#define PUL pair<ULL,ULL>

///         0123456789
#define MX  500007
#define MOD 1000000007
#define INF 2000000000
#define EPS 1e-9
/// ==========================================////

string a,b;
string aa,bb;

vector<string> A;
vector<string> B;

void Dekhi(int pos) {

    F(i,0,pos)
    {
        aa+=a[i];
        bb+=b[i];
    }

    aa+='0';
    bb+='1';
    pos++;
    int f=2;
//    trace2(aa,bb);
//    trace1(pos);
    for(int i=pos;i<a.sz;i++) {
        aa+=a[i];
        bb+=b[i];
        if(a[i]==b[i]&&a[i]=='?') {
            {
                bb[i]='0';
                aa[i]='9';
            }
        }
        else if(a[i]=='?') {
            aa[i]='9';
        }
        else if(b[i]=='?') {
            bb[i]='0';
        }
    }
    A.PB(aa);
    B.PB(bb);
//    trace2(aa,bb);
    pos--;
    aa.clear();
    bb.clear();
    F(i,0,pos)
    {
        aa+=a[i];
        bb+=b[i];
    }
    pos++;
    aa+='1';
    bb+='0';
    f=1;


   // trace2(aa,bb);

    for(int i=pos;i<a.sz;i++) {
        aa+=a[i],bb+=b[i];
        if(a[i]==b[i]&&a[i]=='?') {
             {
                aa[i]='0';
                bb[i]='9';
            }
        }
        else if(a[i]=='?') {
             {
                aa[i]='0';
            }
        }
        else if(b[i]=='?') {
            {
                bb[i]='9';
            }
        }
    }
//    trace2(aa,bb);
    A.PB(aa);
    B.PB(bb);
}

LL ToInt(string a) {
    LL n=0;
    F(i,0,a.sz)
    {
        n=n*10+(a[i]-'0');
    }
    return n;
}

int main()
{
    freopen("A.in","r",stdin),freopen("A1.out","w",stdout);

    int t;
    S1(t);
     for(int cs=1;cs<=t;cs++) {


        cin>>a>>b;

        int f=0;
        int n=a.sz;
        for(int i=0;i<n;i++) {
            if(a[i]==b[i]&&a[i]=='?') {
                if(f==0) {
                    Dekhi(i);
                    a[i]=b[i]='0';

                }
                else if(f==1) {
                    a[i]='0';
                    b[i]='9';
                }
                else {
                    b[i]='0';
                    a[i]='9';
                }
            }
            else if(a[i]=='?') {
                if(f==0) {
                    a[i]=b[i];
                }
                else if(f==1) {
                    a[i]='0';
                }
                else a[i]='9';
            }
            else if(b[i]=='?') {
                if(f==0) {
                    b[i]=a[i];
                }
                else if(f==1) {
                    b[i]='9';
                }
                else b[i]='0';
            }
            if(f==0) {
                if(a[i]>b[i]) f=1;
                else if(a[i]<b[i]) f=2;
            }
        }


        A.PB(a);
        B.PB(b);

        //cout<<A.sz<< " "<<B.sz<<endl;

//        trace2(a,b);

        LL gap=10000000000LL;
        string aaa="-";
        string ab="-";

        LL X,Y;

        F(i,0,A.sz)
        {
            F(j,0,B.sz) {
                LL x=ToInt( A[i] );
                LL y=ToInt( B[j] );
                LL abb=abs(x-y);

               // trace2(A[i],B[j]);
                if(gap>abb) {
                    aaa=A[i],ab=B[j];
                    gap=abb;
                    X=x,Y=y;
                }
                else if(gap==abb) {
                    if(  X>x ) {
                        aaa=A[i],ab=B[j];
                        X=x,Y=y;
                    }
                    else if(A[i]==aaa) {
                        if(y<Y) {
                            aaa=A[i],ab=B[j];
                            X=x,Y=y;
                        }
                    }
                }
            }
        }
        A.clear();
        B.clear();

        if(ab[ ab.sz-1 ]=='?') {
            trace2(a,b);
        }

        printf("Case #%d: ",cs);
        F(i,0,aaa.sz) {
            if(aaa[i]=='?') continue;
            cout<<aaa[i];
        }
        printf(" ");
        F(i,0,ab.sz) {
            if(ab[i]=='?') continue;
            cout<<ab[i];
        }
        NL;
    }


    return 0;
}
