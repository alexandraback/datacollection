#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
#define rep(i,k) for(int i=0;i<(int)(k);i++)
#define foreach(i,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define forinc(i,a,b) for(int i=(a);i<(int)(b);i++)
#define fordec(i,a,b) for(int i=(a);i>(int)(b);i--)

int main(int argc, char *argv[]) {
 //  freopen("A-small-attempt0.in", "r", stdin);
//   freopen("A-small-attempt1.in", "r", stdin);
//   freopen("A-small-attempt2.in", "r", stdin);
   freopen("A-large.in", "r", stdin);
   freopen("out.txt", "w", stdout);

   int T, A, N;
   cin >> T;
   rep(icase, T)
   {
       cin >> A >> N;
       vector<int> data(N,0);
       rep(i, N) cin >> data[i];
       sort(data.begin(),data.end());

       int nowSize = A;
       int bestAns = N;
       int curAdd = 0;

       rep(i, N)
       {
           int curAns1 = curAdd + N - i; // remove all later.
           bestAns = min(bestAns, curAns1);

           if(nowSize == 1) goto DONE;

           while(nowSize <= data[i]) { nowSize += nowSize-1; curAdd++; }
           if(nowSize <= data[N-1]) nowSize += data[i];


       }

       bestAns = min(bestAns, curAdd);
DONE:
       cout << "Case #" << icase+1 << ": " << bestAns << endl;
   }

   return 0;
}
