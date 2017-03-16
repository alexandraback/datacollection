#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;
int BFF[1001];
int len[1001];
bool check[1001];

int main(){
   int n_case;
   cin >> n_case;
   for( int loop = 0 ; loop < n_case ; loop++ ){
      int N;
      cin >> N;
      for( int i = 0 ; i < N; i++ ){
         cin >> BFF[i];
         BFF[i]--;
      }
      int ans = -1;
      for( int i = 0 ; i <N; i++) len[i]=1;
      memset(check,false,sizeof(check));
      vector<int> finishes;
      for( int start= 0; start <N; start++){
         bool arrived[N];
         //cout << "try"<< start << endl;
         memset(arrived, false, sizeof(arrived) );
         int cur=start;
         arrived[cur]=true;
         int num=1;
         while( true ){
            //cout << cur << ", ";
            if( BFF[cur]==start ){
               //cout << "...loop" << endl;
               //cout << endl;
               ans=max(num,ans);      
               break;
            }
            if( arrived[BFF[cur]] ) break;
            int prev=cur;
            cur=BFF[cur];
            num++;
            arrived[cur]=true;
            if( BFF[cur]==prev ){
               len[prev]=max(len[prev],num-1);
               check[min(cur,prev)]=true;
               //cout <<"... end" << endl;
               break;
            }
         }
      }
      int tmp = 0;
      for( int i = 0 ; i < N; i++){
         if(check[i]==true){
            tmp+=len[i]+len[BFF[i]];
         }
      }
      ans = max(ans,tmp);

      cout << "Case #" << loop+1 << ": " <<ans<< endl;
   }
   return 0;
}
