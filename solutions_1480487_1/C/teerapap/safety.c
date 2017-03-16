
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void find_safety(int N, double *J, double *safety) {

  double limit = -1;

  // Find start min
  int n = 0;
  for (n=0;n<N;n++) {
    if (J[n] < limit || limit < 0) {
      limit = J[n];
    }
  }
 
  double vote = 1.0;

  while (vote>0) {
    double min = -1;

    int n_min = 0;
    for (n=0;n<N;n++) {
      if (J[n] <= limit) {
        n_min++;
        continue;
      }

      if (J[n] < min || min < 0) {
        min = J[n];
      }
    }

    double need_vote_each;
    double need_vote;
    if (n_min >= N) {
      need_vote = vote;
      vote = 0;
      need_vote_each = need_vote/n_min;
    } else {
      need_vote_each = min - limit;
      need_vote = need_vote_each * n_min;
      if (need_vote < vote) {
        vote = vote - need_vote;
      } else {
        need_vote = vote;
        vote = 0;
        need_vote_each = need_vote/n_min;
      }
    }

    for (n=0;n<N;n++) {
      if (J[n] <= limit) {
        safety[n] += need_vote_each;
      }
    }

    limit = min;
  }
  
}


int main() {
  int T = 0;
  scanf("%d",&T);

  int t = 0;
  for (t=1;t<=T;t++) {
    int N;
    scanf("%d",&N);

    int n = 0;
    double J[200];
    double safety[200];
    int sum = 0;
    for (n=0;n<N;n++) {
      int s = 0;
      scanf("%d",&s); 
      sum += s;
      J[n] = s;
      safety[n] = 0;
    }

    for (n=0;n<N;n++) {
      J[n] = J[n]/sum;
    }

    printf("Case #%d:", t);
    find_safety(N, J, safety);

    for (n=0;n<N;n++) {
      printf(" %f", safety[n] * 100);
    }
    printf("\r\n");
  }
}

