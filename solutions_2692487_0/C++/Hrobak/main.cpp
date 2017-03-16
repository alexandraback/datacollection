#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>
#include <iterator>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
 ifstream cin("/home/misha/fook.in");
 ofstream cout("/home/misha/aaaoook");
 int T;
 cin >> T;
 for(int t=1; t<=T; t++){
  int k, n;
  cin >> k >> n;
  long long x[111];
  for(int i=0; i<n; i++) cin >> x[i];

  if(k == 1){
   cout << "Case #" << t << ": ";
   cout << n << "\n";
   continue;
  }

  sort(x, x+n);
  long long s = k;
  int in = 0;
  while((in < n) && (s > x[in])) s += x[in], in++;
  if(in == n) cout << "Case #" << t << ": " << "0" << endl; else{
   int vidp = n - in;
   int c = 0;
   for(int i=in; i<n; i++){
    vidp = min(vidp, c + n - i);
    int tempcnt = 0;
    while(s <= x[i]) s += s - 1, tempcnt++;
         s += x[i];
    vidp = min(vidp, c + n - i + tempcnt - 1);
    c += tempcnt;
   }
   cout << "Case #" << t << ": ";
   cout << vidp << endl;
  }
 }
 return 0;
}

