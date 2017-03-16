#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX = 10000000;
int results[MAX];
int act_result;
int number, test_case;
int value, length, counter;
int word[MAX];
char* word2;
int array[5];

bool check_consonants(int arg){
  bool val = true;
  for(int k=0; k<5; ++k){
    if(arg == array[k]){
      val = false;
    }
  }
  return val;
}

int main(){
  scanf("%d", &number);
  word2 = (char*)malloc(sizeof(char)*MAX);
  array[0] = 97;
  array[1] = 101;
  array[2] = 105;
  array[3] = 111;
  array[4] = 117;
  for(int i=0; i<number; ++i){
    test_case = i+1;
    scanf("%s", word2);
    length = (int) strlen(word2);
    for(int j=0; j<length; ++j){
      word[j] = (int) word2[j];
    }
    scanf("%d", &value);
    counter = 0;
    act_result = -1;
    for(int j=0; j<length; ++j){
      if(check_consonants(word[j])){
	counter++;
      }
      else{
	counter = 0;
      }
      if(counter == value){
	act_result = j+1-value;
	counter--;
      }
      if(j>0){
	results[j] = results[j-1]+act_result+1;
      }
      else{
	results[0] = act_result+1;
      }
    }
    printf("Case #%d: ", test_case);
    printf("%d\n", results[length-1]);
  }
}
