#include <stdio.h>

int recycled(int val,int radix){
  int lb = val%10;
  val /= 10;
  return lb*radix + val;
}

int main(int argc, char *argv[])
{
  int casecount;
  scanf("%d",&casecount);
  int A,B;
  int i;
  for (i = 0; i < casecount; ++i){
    scanf("%d%d",&A,&B);
    int radixlength = 0,radix = 1;
    int temp = A;
    while(temp != 0){
      radixlength++;
      radix *= 10;
      temp /= 10;
    }
    radix /= 10;

    int data_recycled,data;
    int result=0;
    for(data = A; data <= B; data++){
      data_recycled = data;
      int j;
      int dumpbuf[10];
      int d_index = -1;
      int dump = 0;
      for(j = 0; j < radixlength -1; j++){
        data_recycled = recycled(data_recycled,radix);
        if (data_recycled > data && data_recycled <= B ){
          int k;
          for(k = 0; k <= d_index; k++){
            if(dumpbuf[k] == data_recycled){
              dump = 1;
              break;
            }
          }
          if(!dump){
            dumpbuf[++d_index] = data_recycled;
            result++;
          }
        }
      }
    }
    printf("Case #%d: %d\n",i+1,result);
  }
  return 0;
}
