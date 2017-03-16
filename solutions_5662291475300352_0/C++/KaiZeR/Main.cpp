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

inline void printTest(int ans = -1) {
       static int test_number = 0;
       cout << "Case #";
       test_number ++;
       cout << test_number << ": ";
       if (ans != -1) {
          cout << ans << endl;
       }
}
int m[Nmax], h[Nmax], d[Nmax];
int main() {
    ios_base::sync_with_stdio(0);
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int test;
    int n;
    cin >> test;
    while (test --> 0){ 
          cin >> n;
          int sumH = 0;
          for (int i = 1;i <= n ;i ++)
          {
              cin >> d[i] >> h[i] >> m[i];
              sumH += h[i];
          }
          assert(sumH <= 2);
          if (sumH <= 1) {
             printTest(0);               
             continue;
          }
          if (n == 1) {
             n = 2;
             d[2] = d[1];
             h[1] = h[2] = 1;
             m[2] = m[1] + 1;
          }
          if (d[1] > d[2]) {
             swap(d[1],d[2]);
             swap(h[1],h[2]);
             swap(m[1],m[2]);
          }
          if (d[1] == d[2]) {
             if (m[1] > m[2])
                swap(m[1], m[2]);
                   // t1 - faster
             double t2 = ((360 - d[2]) * 1.0 / 360) * (m[2]);
             double t1 = ((720 - d[1]) * 1.0 / 360) * m[1];
             
             //cout << t1 << " " << t2 << endl;
             if (t1 - 1e-8 < t2) {
                printTest(1);
             }
             else
                 printTest(0);
             continue;
          }
          /*
          if (m[1] > m[2]) {
             //2 - faster
             double t1 = ((360 - d[1]) * 1.0 / 360 ) * m[1];
             double t2 = ((720 - d[2]) * 1.0 / 360 ) * m[2];
             
             if (t2 - 1e-8 < t1) 
                printTest(1);
             else
                 printTest(0);
          }
          else {
               
          }*/
          
          double t1 = ((360 - d[1]) * 1.0 / 360 ) * m[1];
          double t2 = ((720 - d[2]) * 1.0 / 360 ) * m[2];
          
          if (t2 - 1e-8 < t1)
             printTest(1);
          else{ 
                t1 = ((720 - d[1]) * 1.0 / 360) * m[1];
                t2 = ((360 - d[2]) * 1.0 / 360) * m[2];
                if (t1 - 1e-8 < t2)
                   printTest(1);
                else
                    printTest(0);
          }
    }
    return 0;
}
