#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){
  int T, J, P, S, K;
  scanf("%d", &T);
  for(int t = 1; t<=T; t++){
    scanf("%d %d %d %d", &J, &P, &S, &K);
    printf("Case #%d: ", t);
    if(S <= K){
      printf("%d\n", J * P * S);
      for(int j=1; j<=J; j++){
        for(int p=1; p<=P; p++){
          for(int s=1; s<=S; s++){
            printf("%d %d %d\n", j, p, s);
          }
        }
      }
    }
    else if(P <= K){
      printf("%d\n", J * P * K);
      for(int j=1; j<=J; j++){
        for(int p=1; p<=P; p++){
          for(int k=1; k<=K; k++){
            printf("%d %d %d\n", j, p, k);
          }
        }
      }
    }
    else if(K < J){
      if(K == 2){
        printf("%d\n", 18);
        printf("1 1 1\n");
        printf("1 1 2\n");
        printf("1 2 1\n");
        printf("1 2 3\n");
        printf("1 3 2\n");
        printf("1 3 3\n");
        printf("2 1 1\n");
        printf("2 1 3\n");
        printf("2 2 2\n");
        printf("2 2 3\n");
        printf("2 3 1\n");
        printf("2 3 2\n");
        printf("3 1 2\n");
        printf("3 1 3\n");
        printf("3 2 1\n");
        printf("3 2 2\n");
        printf("3 3 1\n");
        printf("3 3 3\n");
      }
      else{
        if(S == 2 || (S == 3 && P == 2)){
          printf("%d\n", 4);
          printf("1 1 1\n");
          printf("1 2 2\n");
          printf("2 1 2\n");
          printf("2 2 1\n");
        }
        else if(P == 3 && J == 2){
          printf("%d\n", 6);
          printf("1 1 1\n");
          printf("1 2 3\n");
          printf("1 3 2\n");
          printf("2 1 2\n");
          printf("2 2 1\n");
          printf("2 3 3\n");
        }
        else{
          printf("%d\n", 9);
          printf("1 1 1\n");
          printf("1 2 2\n");
          printf("1 3 3\n");
          printf("2 1 2\n");
          printf("2 2 3\n");
          printf("2 3 1\n");
          printf("3 1 3\n");
          printf("3 2 1\n");
          printf("3 3 2\n");
        }
      }
    }
    else if(J <= K && K < P){
      if(K == 1){
        printf("%d\n", P);
        for(int p=1; p<=P; p++)
          printf("1 %d %d\n", p, p);
      }
      else{
        printf("%d\n", J * 6);
        for(int j=1; j<=J; j++){
          printf("%d 1 1\n", j);
          printf("%d 1 2\n", j);
          printf("%d 2 1\n", j);
          printf("%d 2 3\n", j);
          printf("%d 3 2\n", j);
          printf("%d 3 3\n", j);
        }
      }
    }
  }
  return 0;
}
