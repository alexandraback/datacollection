#include <stdio.h>


int main(int argc, char *argv[])
{
  int casecount,c;
  scanf("%d",&casecount);
  
  int number,surprising,plimit;
  int score[101];
  int score_index;
  
  int i;
  for (i = 0; i < casecount; ++i){
    int output = 0;
    int candidate = 0;
    scanf("%d%d%d",&number,&surprising,&plimit);
    for(score_index = 0; score_index < number; ++score_index){
      scanf("%d",score+score_index);
    }
    
    for(score_index = 0; score_index < number; ++score_index){
      if (score[score_index] >= 3*plimit-2)
        output++;
      else if (score[score_index] >= 3*plimit-4 && score[score_index] >= plimit){
        candidate++;
      }
    }
    if (candidate >= surprising)
      output += surprising;
    else
      output += candidate;
    
    printf("Case #%d: %d\n",i+1,output);
  }
  return 0;
}

