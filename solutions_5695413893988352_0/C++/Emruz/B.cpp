/**************************************
 *    BISMILLAHIR RAHMANIR RAHIM      *
 *         MD: EMRUZ HOSSAIN          *
 *            CUET-CSE-12             *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ULL;

#define     mem(x,y)   memset(x,y,sizeof(x))
#define     PB(x)      push_back(x)
#define     POB()      pop_back()
#define     SZ(a)      a.size()
#define     len(a)     strlen(a)
#define     SQR(a)     (a*a)
#define     all(v)     v.begin(),v.end()
#define     fr(i,a,b)  for(i=a;i<=b;i++)
#define     rfr(i,a,b) for(i=a;i>=b;i--)
#define     sf  scanf
#define     pf  printf
#define     mkp make_pair
#define     fs  first
#define     sd  second

#define     getx() getchar()
//#define     getx() getchar_unlocked()

#define     inf  1<<25
#define     sz   20002
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Swap(T &a,T &b) {T tmp=a;a=b;b=tmp;}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}
double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
template<class T>inline bool readfast(T &x)
{
    int c=getx();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getx();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getx())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1}; //move in 8 direction
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2}; //move of knight

////code of sieve
//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}

 /*****************************Code start from here**************************/
int l,pre_ans1,pre_ans2,diff;
vector<char>v,v2,ans1,ans2;
char ss1[20],ss2[20];
void calculate(void)
{
    int num1=0,num2=0,i;
    for(i=0;i<v.size();i++)
    {
        num1*=10;
        num1+=v[i]-'0';
        num2*=10;
        num2+=v2[i]-'0';
    }
    if(abs(num1-num2)<=diff)
    {
        if(abs(num1-num2)==diff)
        {
            if(pre_ans1>num1)
            {
                ans1=v;
                ans2=v2;
                pre_ans1=num1;
                pre_ans2=num2;
            }
            else if(pre_ans1==num1&&pre_ans2>num2)
            {
                ans1=v;
                ans2=v2;
                pre_ans1=num1;
                pre_ans2=num2;
            }

        }
        else
        {
            diff=abs(num1-num2);
            ans1=v;
            ans2=v2;
            pre_ans1=num1;
            pre_ans2=num2;
        }
    }
}
void rec2(int idx)
{
    if(idx==l)
    {
        calculate();
        return;
    }
    if(ss2[idx]=='?')
    {
        for(int i=0;i<10;i++)
        {
            v2.push_back(i+'0');
            rec2(idx+1);
            v2.pop_back();
        }
    }
    else
    {
        v2.push_back(ss2[idx]);
        rec2(idx+1);
        v2.pop_back();
    }
}
void rec1(int idx)
{
    if(idx==l)
    {
        rec2(0);
        return;
    }
    if(ss1[idx]=='?')
    {
        for(int i=0;i<10;i++)
        {
            v.push_back(i+'0');
            rec1(idx+1);
            v.pop_back();
        }
    }
    else
    {
        v.push_back(ss1[idx]);
        rec1(idx+1);
        v.pop_back();
    }
}
int main()
{
       // freopen("output.txt","w",stdout);
        //freopen("B-small-attempt0.in","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,q,r,t,cnt,sm,tmp;
   sf("%d",&t);
   for(x=1;x<=t;x++)
   {
       sf("%s %s",&ss1,&ss2);
       l=strlen(ss1);
       diff=inf;
       pre_ans1=inf;
       pre_ans2=inf;
       ans1.clear();
       ans2.clear();
       v.clear();
       v2.clear();
       rec1(0);
       pf("Case #%d: ",x);
       for(i=0;i<ans1.size();i++)
        pf("%c",ans1[i]);
       pf(" ");
       for(i=0;i<ans2.size();i++)
        pf("%c",ans2[i]);
       pf("\n");
   }

    return 0;
}




