#include<stdio.h>
#include<stdlib.h>

int number;
int result = 0;
int energy, regain, no;
int max, test_case;
const int MAX = 10002;
int array[MAX];

int main(){
  scanf("%d\n", &number);
  for(int i=0; i<number; ++i){
    test_case = i+1;
    scanf("%d", &energy);
    scanf("%d", &regain);
    scanf("%d", &no);
    max = 0;
    for(int i=0; i<no; ++i){
      scanf("%d", &array[i]);
      if(array[i] > max){
	max = array[i];
      }
    }
    result = 0;
    if(regain >= energy){
      for(int i=0; i<no; ++i){
	result += energy*array[i];
      }
    }
    else{
      for(int i=0; i<no; ++i){
	result+=regain*array[i];
      }
      result+=(energy-regain)*max;
    }
    printf("Case #%d: ", test_case);
    printf("%d\n", result);
  }
  return 0;
}
