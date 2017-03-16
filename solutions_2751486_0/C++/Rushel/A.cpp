#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <sstream>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>

using namespace std;
typedef long  long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

int isVowel(char c)
{
   if(c=='a' || c=='e' || c=='i' || c=='o' || c == 'u') return 1;
   return 0;
}
int main()
{
   freopen("A-small-attempt0.in","r",stdin);
   freopen("A-small.out","w",stdout);
   int T;
   cin>>T;
   for(int tc = 1; tc <= T; tc++) {
      string name;
      int n;
      cin>>name>>n;
      int m= name.size(),ret = 0;
      for(int i = 0; i < m; i++) {
         for(int j = i; j < m; j++) {
            int ok = 0;
            for(int k = i; k <= j; ) {
               if(isVowel(name[k])) {
                  k++;
                  continue;
               }
               int cnt = 0;
               while(k <= j && isVowel(name[k])==0) {
                  cnt++;
                  k++;
               }
               if(cnt>=n) {
                  ok = 1;
                  break;
               }
            }
            ret+=ok;
         }
      }
      cout<<"Case #"<<tc<<": "<<ret<<endl;
   }
   return 0;
}
