#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

using namespace std;

int E,R,N;
int v[2000];
int oldb[10000020];
int newb[10000020];

void readData() {
    scanf("%d %d %d",&E,&R,&N);
    for (int i = 0;i < N;i++) {
        scanf("%d",&v[i]);
    }

    /*
    printf("E = %d R = %d N = %d\n",E,R,N);
    for (int i = 0;i < N;i++) {
        printf("v[%d] = %d\n",i+1,v[i]);
    }
    */

}

int process() {
    //init condition
    for (int i = 0;i <= E;i++) {
        oldb[i] = 0;
        newb[i] = 0;
    }

    for (int i = 1;i <= N;i++) {  // for each activity
        int best;

        //iterate over all possible energy
        // we cannot have less than R energy
        // j is the energy AFTER we perform act i.
        for (int j = R;j <= E+R;j++) {
          best = INT_MIN;

          //iterate over how much we spent on act. i
          // k is the energy before we spent
          // j-R is the energy after we spent
          for (int k = j-R;k <= E;k++) {
            int spent;
            spent = k - (j-R);
            best = max(best,oldb[k] + spent * v[i-1]);
          }
          newb[min(E,j)] = max(best,newb[min(E,j)]);
        }

        //copy newb to oldb
        //printf("after act %d\n",i);


        for (int j = 0;j <= E;j++) {
            //printf("b[%d] = %d\n",j,newb[j]);
            oldb[j] = newb[j];
        }


    }

    //find ans
    int ans = INT_MIN;
    for (int i = 0;i <= E;i++) {
      if (oldb[i] > ans) ans = oldb[i];
    }
    return ans;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    //freopen("ex.in","r",stdin);
    int T;
    scanf("%d",&T);
    //printf("There is %d tests\n",T);
    for (int i = 1;i <= T;i++) {
        readData();
        int ans;
        ans = process();
        printf("Case #%d: %d\n",i,ans);
     }


    return 0;
}
