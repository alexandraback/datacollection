#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

double area[1010];

void preprocess() {
  for (int i = 0;i <= 1010;i++) {
    area[i] = M_PI*i*i;
  }

  for (int i = 0;i < 10;i++) {
    //printf("radius = %d area = %lf\n",i,area[i]);
  }
}

int process(unsigned long long int r,unsigned long long int t) {
    unsigned long long int ink = t;
    unsigned long long int idx = r+1;
    double needed;
    unsigned long long int count;
    count = 0;
    do {

        needed = idx*2-1;
        //printf("ring from %3d to %3d ink = %10.2lf needed = %10.2lf\n",idx+1,idx,ink,needed);
        if (needed > ink) { break; }
        ink -= needed;
        idx+= 2;
        count++;
    } while(true);
    return count;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    //freopen("ex.in","r",stdin);
    preprocess();
    int T;
    scanf("%d",&T);
    //printf("There is %d tests\n",T);
    for (int i = 1;i <= T;i++) {
        unsigned long long int t,r,ans;
        scanf("%llu %llu",&r,&t);
        ans = process(r,t);
        printf("Case #%d: %llu\n",i,ans);

    }


    return 0;
}
