#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<set>
#include<iomanip>
#include<complex>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<bitset>
#include<memory.h>
#include<cassert>
#include<ctime>
 
 
#pragma comment(linker, "/stack:30000000")
 
using namespace std;
 
#define For(i,l,r) for (int i = l ;i < (int)(r + 1) ; ++ i )
#define ForI(it , s , T) for (T :: iterator it = s.begin(); it != s.end() ; ++ it )
#define LL long long
#define iinf 2000000000
#define linf 4000000000000000000LL
#define MOD  1000000007
#define Pi 3.1415926535897932384
#define bit(mask,i) ((mask>>i)&1)
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define pause cin.get();cin.get();
#define fir first
#define sec second
#define ln(x) log(x)
 
const int Direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int Nmax = 200100;

LL gcd(LL a,LL b)
{
          if (a == 0) return b;
          else
           return gcd(b%a,a);
}
int main()
{ 
   freopen("A-small-attempt0.in","r",stdin);
   freopen("output.txt","w",stdout);
   int test;
   cin >> test;
   LL p,q;
   string rub;
   getline(cin,rub);
   char ch;
   for (int tt = 1 ; tt <= test ;tt ++){
   p = q = 0;
   string s;
   getline(cin,s);
   int i = 0;
   for (;i < s.size() && s[i] != '/';  i ++)
    p = p * 10LL + (LL)(s[i] - '0');
    
   i ++;
   while (i < s.size())
    q =  q * 10LL + (LL)(s[i] - '0'), i ++;
    
   LL gt = gcd(p,q);
   p/=gt ,  q/=gt;
   
   LL r = q;
   while (r%2 == 0) r/=2;
   if (r != 1){
    printf("Case #%d: impossible\n",tt);
    continue;
   }
   LL Ans = 0;
   if (p == q)
         Ans = 0;
   else
   {
       LL gen = 1;
       for (gen = 1 ; ; gen ++)
       {
           pair<LL,LL> Cur(p,q);
           Cur.first = 2*Cur.first - Cur.second;
           if (Cur.first >= 0) break;
           if (q%2 == 0) q/=2; else p*=2;
       }
       Ans = gen;
   }
   printf("Case #%d: %I64d\n",tt,Ans);
   }
   return 0;
} 
