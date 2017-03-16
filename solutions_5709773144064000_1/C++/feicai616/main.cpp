#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

#define MOD 1000000007

int casen;

double c,f,x;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	scanf("%d",&casen);
    for (int casei=1;casei<=casen;casei++){
       scanf("%lf%lf%lf",&c,&f,&x);
       double minn=x/2;
       double sheng=0;
       double ff=2;
       double day=0;
       printf("Case #%d: ",casei);
       for (int i=1;i<=x;i++){
          if (sheng<c){
              day+=c/ff;
              ff=ff+f;
              minn=min(minn,day+(x)/ff);
          }else{
              sheng=sheng-c;
              ff=ff+f;
              minn=min(minn,day+(x-sheng)/ff);
          }
       }
        printf("%.10lf\n",minn);
    }
}
