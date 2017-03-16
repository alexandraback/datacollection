#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;
typedef long long LL;
const int MAXN = 4, MAXM = 101;
LL memo[MAXN][MAXM];
int boxSize, toySize;
int boxType[MAXN], toyType[MAXM];
LL bArray[MAXN],bType[MAXN];
LL boxArray[MAXN], toyArray[MAXM];
int curState = 0;
LL doit(int box, int toy)
{
   if(box==boxSize||toy==toySize) {
      return 0;
   }
   LL &ret = memo[box][toy];
   if(ret!=-1) return ret;

   ret = 0;
   ret = doit(box+1,toy);
   for(int start = toy; start < toySize; start++) {
      if(toyType[start]==boxType[box]) {

         LL curBoxes = boxArray[box];
         //cerr<<curBoxes<<endl;
         LL total = 0;
         //if(box==0)curBox
         for(int end = start; end < toySize; end++) {
            if(curBoxes >= 0 && boxType[box]==toyType[end]) {
            //   cerr<<end<<" "<<curBoxes<<" "<<total<<endl;
               total+= min(curBoxes,toyArray[end]);
               LL cur = doit(box + 1, end+1) + total;
               ret=max(ret,cur);
               curBoxes -= min(curBoxes,toyArray[end]);

            }
         }
         break;
      }

   }
   return ret;
}


LL solve(int N)
{
   LL ret = 0;
   for(int state = 1; state < (1<<N); state++) {
     // if(state!=7)continue;

      vector<int> boxIndex;
      boxIndex.clear();
      for(int i = 0; i < N; i++) {
         if(state&(1<<i)) {
            boxIndex.push_back(i);
         }
      }

      vector<LL> boxA, boxT;
      boxA.clear();
      boxT.clear();


      boxA.push_back(bArray[boxIndex[0]]);
      boxT.push_back(bType[boxIndex[0]]);


      for(int i = 1; i < boxIndex.size(); i++) {
         int size = boxA.size();
         if(boxT[size-1]==bType[boxIndex[i]]) {
            boxA[size-1]+=bArray[boxIndex[i]];
         }
         else {
            boxA.push_back(bArray[boxIndex[i]]);
            boxT.push_back(bType[boxIndex[i]]);
         }

      }
       boxSize = boxA.size();

      for(int i = 0; i < boxA.size(); i++) {
         boxArray[i] = boxA[i];
         boxType[i] = boxT[i];
      }


           //  if(state==5)cerr<<boxArray[i]<<" "<<boxType[i]<<<<endl;


      memset(memo,-1,sizeof(memo));
      LL cur = doit(0,0);
      //cerr<<cur<<endl;
      ret = max(ret,cur);


   }
   return ret;
}

int main()
{
   freopen("C-small-attempt0.in","r",stdin);
   freopen("C.out","w",stdout);
   int T,N,M;

   //scanf("%d",&T);
   cin>>T;
   for(int tc=1;tc<=T;tc++) {
      //scanf("%d %d",&N,&M);
      cin>>N>>M;
      for(int i = 0; i < N; i++) {
         cin>>bArray[i]>>bType[i];
      }




      for(int i = 0; i < M; i++) {
         cin>>toyArray[i]>>toyType[i];
      }
  //    cerr<<toyType[0]<<endl;

      toySize = M;

     // memset(memo,-1,sizeof(memo));

      LL ret = solve(N);
     // LL ret = doit(0,0);

      cout<<"Case #"<<tc<<": "<<ret<<endl;
    //  printf("Case #%d: \n",ret);
   }

   return 0;
}
