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
  scanf("%d",&T);

  for(int i=1;i<T+1;++i){
    float C,F,X;
    scanf("%f %f %f",&C,&F,&X);

    float time = 0.0;
    float rate = 2.0;

    while(true){
      float timeNextFarm = C/rate;
      float timeToWin = X/rate;
      rate += F;
      float timeFarmAndWin = timeNextFarm + X/rate;

      if(timeToWin > timeFarmAndWin){
        time += timeNextFarm;
      }else{
        time += timeToWin;
        break;
      }
    }

    printf("Case #%d: %f\n",i,time);
  }
}    
