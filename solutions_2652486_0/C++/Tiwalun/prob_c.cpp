#include<iostream>
#include<cstdio>

const int prim[3] = { 2, 3, 5 };
const int nprim = 3;
const int N = 3;
const int R = 100;
const int K = 7;

void solve(int set[K]) {
  int min[nprim];
  int max[nprim];

  //std::printf("Solving set...\n");

  for (int i = 0; i < nprim; i++) {
    min[i] = 0;
    max[i] = N;
  }

  for (int k = 0; k < K; k++) {

      if (set[k] == 1) continue;

      int tmin[nprim] = { 0, 0, 0 };
      int tmax[nprim] = { N, N, N };

      //printf("Checking product %i\n", set[k]);

      for (int i = 0; i < nprim; i++) {
        while (set[k] % prim[i] == 0) {
          tmin[i] += 1;
          set[k] /= prim[i];

          if (set[k] == 1) break;
        }
      }

      for (int i = 0; i < nprim; i++) {
        min[i] = std::max(min[i], tmin[i]);
        max[i] = std::min(max[i], tmax[i]);

        //printf("%i: min: %i, max: %i\n", prim[i], min[i], max[i]);
      }
  }

  int nLeft = N;

  if (min[2] > 0) {
    nLeft -= min[2];
    for (int i = 0; i < min[2]; i++) printf("5");
  }

  if (min[1] > 0) {
    nLeft -= min[1];
    for (int i = 0; i< min[1]; i++) printf("3");
  }

  if (nLeft == 0) {
    printf("\n");
    return;
  }

  //printf("Carts with 2 or 4: %i\n", nLeft);

  if (nLeft == 1) {
    if (min[0] == 2) printf("4");
    else printf("2");

    nLeft--;

  } else if (nLeft == 2){

    if (min[0] == 2) printf("22");
    else { 
      if (min[0] == 3) {
      printf("24");
      } else {
        printf("44");
      }
    }

    nLeft -= 2;

  } else {
    if (min[0] == 3) { 
      printf("222");
    } else {
      if (min[0] == 4) { printf("224"); }
      else { 
        if (min[0] == 5) printf("244"); 
        else printf("444");
      }
    }
  }

  printf("\n");


}

int main() {
  int probs;
  std::cin >> probs;

  std::cin >> probs >> probs >> probs >> probs;


  int min[3];
  int max[3];

  int set[K];

  std::printf("Case #1:\n");

  for (int i = 0; i < R; i++) {
    for (int k = 0; k < K; k++) {
      std::cin >> set[k];
    }

    solve(set);
  }
  return 0;
}
