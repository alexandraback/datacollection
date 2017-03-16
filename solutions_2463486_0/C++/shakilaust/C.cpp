
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 1000000
#define INF 1<<29
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
bool save[1005];
int cot[1005];
bool palindrome(char str[])
{
       int len=strlen(str),i,j;
       for(i=0,j=len-1;i<len/2;i++,j--)
          if(str[i]!=str[j]) return false;
       return true;

}
int cal(int num)
{       char str[200];
       int idx=0,p=num;
       while(num)
       {
              str[idx++]=num%10+'0';
              num/=10;
       }
       str[idx]='\0';
       if(palindrome(str)) {save[p]=1; }
}

int main()
{   //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    memo(save,0);
    int i,cs,t,A,B;
    FOR(i,1,1000) cal(i);
    int ct=0;
    for(i=1;i*i<=1000;i++)
    if(  save[i] && save[i*i]) cot[i*i]=++ct;
    for(i=1;i<=1000;i++)
    {
           if(!cot[i]) cot[i]=cot[i-1];
    }
    sc(t);
    FOR(cs,1,t)
    {
           cin>>A>>B;
           printf("Case #%d: %d\n",cs,cot[B]-cot[A-1]);
    }


}
