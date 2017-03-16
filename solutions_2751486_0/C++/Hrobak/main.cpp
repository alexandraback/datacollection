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


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
 ifstream cin("/home/misha/inuuu.in");
 ofstream cout ("/home/misha/ouuu");
 int T;
 cin >> T;
 for(int t=1; t <= T; t++){
  string s;
  cin >> s;
  int k;
  cin >> k;
  int asnw = 0;
  for(int i=0; i<s.length(); i++){

   for(int j=i; j<s.length(); j++){
    int tkt = 0;
    int cnt = 0;
    for(int p=i; p<=j; p++){
     if(s[p] == 'a' || s[p] == 'i' || s[p] == 'e' || s[p] == 'o' || s[p] == 'u') cnt = max(cnt, tkt), tkt = 0; else tkt++;
    }
    cnt = max(cnt, tkt);
    if(cnt >= k)asnw++;
   }
  }
  cout << "Case #" << t << ": " << asnw << endl;
 }
 return 0;
}
