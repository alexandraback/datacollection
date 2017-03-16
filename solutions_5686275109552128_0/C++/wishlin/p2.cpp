#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int cas, len, tmp, maxx, res, special, brute, feasible, curr, x1, x2, brute2;
  int arr[1024], arr2[1024];

  cin>>cas;
  for (int k=1; k<=cas; ++k) {
    for (int i=0; i<1024; ++i) arr[i]=0;
    maxx=res=0;
    cin>>len;

    for (int i=0; i<len; ++i) {
      cin>>tmp; ++arr[tmp];
      if (tmp>maxx) maxx=tmp;
    }

    if (maxx==9 && arr[9]==1 && !arr[8] && !arr[7] && !arr[6] && !arr[5] && !arr[4]) {
      printf("Case #%d: 5\n", k);
      continue;
    }
    if (maxx==9 && arr[9]==1 && !arr[8] && !arr[7] && arr[6]==1 && !arr[5] && !arr[4]) {
      printf("Case #%d: 6\n", k);
      continue;
    }

    while (1) {
      brute=maxx; special=0; feasible=0;
      while (brute>=0 && arr[brute]==0) --brute;

      for (int i=0; i<1024; ++i) arr2[i]=arr[i];
      curr=brute;
      while (curr>=0) {
        if (curr%2==0) {x1=x2=(curr>>1);}
        else {x1=(curr>>1); x2=x1+1;}
        arr2[x1]+=arr2[curr];
        arr2[x2]+=arr2[curr];
        special+=arr2[curr];
        arr2[curr]=0;

        brute2=curr;
        while (brute2>=0 && arr2[brute2]==0) --brute2;
        if (brute>special+brute2) {
          feasible=1;
          break;
        }
        else curr=brute2;
      }

      if (feasible) {
        for (int i=0; i<1024; ++i) arr[i]=arr2[i];
        res+=special;
      }
      else break;
    }

    printf("Case #%d: %d\n", k, brute+res);
  }
  return 0;
}
