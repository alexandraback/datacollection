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

string S;
const int MAXN = 2000000;
int leftPos[MAXN];
int countPos[MAXN];
int main()
{
   //freopen("test.in","r",stdin);
   freopen("A-large.in","r",stdin);
   freopen("A-large.out","w",stdout);
   int T;
   cin>>T;
   for(int tc = 1; tc <= T; tc++) {
      string S;
      int n;
      cin>>S>>n;
      LL ret = 0;
      int m = S.size(), count=0, leftFound=m;
      for(int i = 0; i < m; i++) {
         if(isVowel(S[i])) {
            count=0;

         }else {
            count++;
            if(count >= n) {
               leftFound = i - n + 1;
            }
         }
         leftPos[i]=leftFound;

      }

      for(int i = 0; i < m; i++) {
         if(leftPos[i] == m) continue;
         LL left = leftPos[i];
         ret +=  left + 1;
      }

      cout<<"Case #"<<tc<<": "<<ret<<endl;
   }
   return 0;
}
