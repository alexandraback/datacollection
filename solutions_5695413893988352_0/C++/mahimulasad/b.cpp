#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>
using namespace std;

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define PI acos(-1.0)
#define SQ(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define MAX_INT 2147483647
#define inf 1<<30
#define FOR(i,a,b) for(i=(a);i<=(b);i++)
#define FORV(i,a,b) for(i=(a);i>=(b);i--)
#define REP(i,n) for(i=0;i<(n);i++)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define nl printf("\n")
#define set(A,x) memset(A,x,sizeof(A))
#define in(x) scanf("%d",&x)
#define inll(x) scanf("%lld",&x)
#define LL long long
//#define LL __int64
#define MX 10000

template<class T>inline T _abs(T n){return n<0?-n:n;}
template<class T>inline T _gcd(T a, T b){return b==0?a:_gcd(b,a%b);}
template<class T>inline T _lcm(T a, T b){return a/_gcd(a,b)*b;}

int setb(int N,int pos){return N= N | (1<<pos);}
int resetb(int N,int pos){return N= N & ~(1<<pos);}
bool checkb(int N,int pos){return (bool)(N & (1<<pos));}

string ch_to_str(char ch)
{
    string ret="";
    ret+=ch;
    return ret;
}
int to_int(string s)
{
    int ret=0;
    for(int i=0;i<s.size();i++)
        ret = ret*10 + s[i]-'0';
    return ret;
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output_b_small.txt","w",stdout);
    int test,cases=0;
    string c,j;
    in(test);
    while(test--)
    {
        cin>>c;

        vector<string>a,b,d;


        if(c[0]=='?')
        {
            a.pb("0");
            a.pb("1");
            a.pb("2");
            a.pb("3");
            a.pb("4");
            a.pb("5");
            a.pb("6");
            a.pb("7");
            a.pb("8");
            a.pb("9");
        }
        else
            a.pb(ch_to_str(c[0]));

        for(int i=1;i<c.size();i++)
        {
            if(c[i]=='?')
            {
                vector<string>temp;
                for(int j=0;j<a.size();j++)
                {
                    temp.pb(a[j]+"0");
                    temp.pb(a[j]+"1");
                    temp.pb(a[j]+"2");
                    temp.pb(a[j]+"3");
                    temp.pb(a[j]+"4");
                    temp.pb(a[j]+"5");
                    temp.pb(a[j]+"6");
                    temp.pb(a[j]+"7");
                    temp.pb(a[j]+"8");
                    temp.pb(a[j]+"9");
                }
                a= temp;
            }
            else
            {
                for(int j=0;j<a.size();j++)
                    a[j]+=ch_to_str(c[i]);
            }
        }
        b=a;
        //2nd number
        a.clear();
        cin>>c;
        if(c[0]=='?')
        {
            a.pb("0");
            a.pb("1");
            a.pb("2");
            a.pb("3");
            a.pb("4");
            a.pb("5");
            a.pb("6");
            a.pb("7");
            a.pb("8");
            a.pb("9");
        }
        else
            a.pb(ch_to_str(c[0]));

        for(int i=1;i<c.size();i++)
        {
            if(c[i]=='?')
            {
                vector<string>temp;
                for(int j=0;j<a.size();j++)
                {
                    temp.pb(a[j]+"0");
                    temp.pb(a[j]+"1");
                    temp.pb(a[j]+"2");
                    temp.pb(a[j]+"3");
                    temp.pb(a[j]+"4");
                    temp.pb(a[j]+"5");
                    temp.pb(a[j]+"6");
                    temp.pb(a[j]+"7");
                    temp.pb(a[j]+"8");
                    temp.pb(a[j]+"9");
                }
                a= temp;
            }
            else
            {
                for(int j=0;j<a.size();j++)
                    a[j]+=ch_to_str(c[i]);
            }
        }
        d=a;

        int min=9999;
        string s1,s2;
        for(int i=0;i<b.size();i++)
            for(int j=0;j<d.size();j++)
            {
                int m= to_int(b[i]);
                int n= to_int(d[j]);
                if(_abs(m-n)<min)
                {
                    min= _abs(m-n);
                    s1= b[i];
                    s2= d[j];
                }
            }
        cout<<"Case #"<<++cases<<": "<<s1<<" "<<s2<<endl;
    }


    return 0;
}
