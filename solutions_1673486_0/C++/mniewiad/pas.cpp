#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int MAX = 1000000;
int number;
double result=0.0;
int first, second;
double tablica[MAX];
double prefix[MAX];
double values[MAX];

int main(){
  scanf("%d", &number);
  for(int i=0; i<number; ++i){
    scanf("%d", &first);
    scanf("%d", &second);
    for(int j=0; j<first; ++j){
      scanf("%lf", &tablica[j]);
    }
    double temp = 1.0;
    for(int j=0; j<first; ++j){
      temp = temp*tablica[j];
      prefix[j] = temp;
      values[j] = prefix[j]*(first-2*(j+1)+second+1) + (1-prefix[j])*(first-2*(j+1)+2*second+2);
    }
    result = (double) (second+2);
    for(int j=0; j<first; ++j){
      result = min(result, values[j]);
      //printf("%lf\n", values[j]);
    }
    printf("Case #%d: %lf\n", i+1, result); 
  }
  return 0;
}
