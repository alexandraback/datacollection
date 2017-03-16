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

using namespace std;

#pragma comment(linker, "/STACK:36777216")

#define For(i,l,r) for (int i = l; i < r + 1; i ++)
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
#define pii pair<int,int>

const int Nmax = 200100;
const int Direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline void printTest() {
       static int test_number = 0;
       cout << "Case #";
       test_number ++;
       cout << test_number << ": ";
}
LL n;
LL dfs(LL x, LL n, LL len) {
   LL current_len = 0;
   for (LL i = x; i > 0 ;i /= 10)
       current_len ++;
   if (current_len < len) {
      LL sub = (current_len / 2ll);
      LL answer = 0;
      LL result = 1;
      for (LL i = 1;i <= sub ;i ++)
          result *= 10ll;
      answer += (result - 1);
      
      answer++;
      
      if (sub + sub < current_len)
         result *= 10ll;
      answer += (result - 1);
      return answer + dfs(x * 10LL, n, len);
   }
   LL answer = 0;//n - x;
   LL sub = current_len / 2ll;
   LL m = n;
   LL len2 = len;
   while (len2 > sub) {
         m /= 10;
         len2 --;
   }
   
   {
         LL n = 0;
         while (m > 0){
               n = (n * 10ll) + (m % 10);
               m /= 10ll;
         }
         m = n; 
   }
   
   answer += m;
   answer ++;
   
   sub = current_len - sub;
   m = 0;
   LL power = 1;
   LL N = n;
   for (LL i = 0; i < sub ;i ++) {
       m += (power * 1ll * (n % 10));
       power *= 10ll;
       n /= 10ll;
   }
   answer += m - 1;// if only rest is not equal to 000000
   
   return min(answer, N - x);
}
int main() {
    ios_base::sync_with_stdio(0);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    LL test;
    cin >> test;
    while (test --> 0){ 
          cin >> n;
          
          LL one = (n % 10 == 0);
          if (one)
             n --;
             
          LL len = 0;
          for (LL i = n ; i > 0; i/= 10)
              len ++;
          
          
          LL res = min(n , 10ll);
          if (n > 10ll)
             res += dfs(10ll, n, len);
          printTest();
          cout << res + one << endl;
    }
    return 0;
}
