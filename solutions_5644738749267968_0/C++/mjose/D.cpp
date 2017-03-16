#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

int main(){

  int T;
  scanf("%d", &T);

  for(int i=1;i<T+1;++i){
    int N;
    scanf("%d",&N);

    vector<float> naomi;
    vector<float> ken;

    for(int j=0;j<N;++j){
      float temp;
      scanf("%f",&temp);
      naomi.push_back(temp);
    }

    sort(naomi.begin(),naomi.end());

    for(int j=0;j<N;++j){
      float temp;
      scanf("%f",&temp);
      ken.push_back(temp);
    }

    sort(ken.begin(),ken.end());
    vector<float> ken2(ken);

    int dWar = 0;
    for(int d = 0;d<N;++d){
      if(naomi[d] < ken[0]){
        ken.erase(ken.begin() + ken.size()-1);
      }else{
        ken.erase(ken.begin());
        ++dWar;
      }
    }
 
    int war = 0;
    for(int w = 0; w<N; ++w){
      int orig = ken2.size();
      for(int r= 0; r<ken2.size(); ++r){
        if(naomi[w] < ken2[r]){
          ken2.erase(ken2.begin() + r);
          break;
        }
      }

      if(ken2.size() == orig){
        ken2.erase(ken2.begin());
        ++war;
      }
    }

    printf("Case #%d: %d %d\n",i,dWar,war);
  }
}
