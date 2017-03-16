#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void myfunction(FILE* fp)
{
  int i,j;
  int linenum;
  float dist;
  int N;
  int A;
  float a;
  float speed;
  float pos1;
  float pos2;
  float besttime;
  float midtime;
  float midpos;
  float time1;
  float time2;
  fscanf(fp, "%d", &linenum);
  for(i=1; i<=linenum; i++){
    printf("Case #%d:\n", i);
    fscanf(fp, "%f", &dist);
    fscanf(fp, "%d", &N);
    fscanf(fp, "%d", &A);
    fscanf(fp, "%f", &time1);
    fscanf(fp, "%f", &pos1);
    if(N == 2){
      fscanf(fp, "%f", &time2);
      fscanf(fp, "%f", &pos2);
      speed = (pos2-pos1)/(time2-time1);
    }
    for(j=0; j<A; j++){
      fscanf(fp, "%f", &a);
      if(N == 2){
        midtime = (speed+sqrt(speed*speed+2*a*pos1))/a;
        midpos = midtime*midtime*a/2;
        if(midpos > dist) besttime = sqrt(dist*2/a);
        if(midpos <= dist) besttime = (dist-pos1)/speed;
      } else { besttime  = sqrt(dist*2/a);}
      printf("%f\n", besttime);
    }
  }
}



int main(int argc, char* argv[])
{
  FILE* fp = fopen(argv[1], "r");
  myfunction(fp);
  fclose(fp);
  return 0;
}
