#include<stdio.h>
#include<string.h>
int num[200];
int ct[10];
int main(){
  int t;
  char s[3000];
  scanf("%d",&t);
  for(int e = 0 ; e < t ;e++  ){
    for(int i = 'A' ; i <= 'Z' ; i++ ) num[i] = 0;
    scanf("%s",s);
    int n = strlen(s);
    for(int i = 0 ; i < n ; i++ ) num[s[i]]++;
    
    ct[0] = num['Z'];
    num['E'] -= num['Z'];
    num['R'] -= num['Z'];
    num['O'] -= num['Z'];
    num['Z'] -= num['Z'];

    ct[2] = num['W'];
    num['T'] -= num['W'];
    num['O'] -= num['W'];
    num['W'] -= num['W'];

    ct[4] = num['U'];
    num['F'] -= num['U'];
    num['O'] -= num['U'];
    num['R'] -= num['U'];
    num['U'] -= num['U'];

    ct[1] = num['O'];
    num['N'] -= num['O'];
    num['E'] -= num['O'];
    num['O'] -= num['O'];

    ct[3] = num['R'];
    num['T'] -= num['R'];
    num['H'] -= num['R'];
    num['E'] -= num['R'];
    num['E'] -= num['R'];
    num['R'] -= num['R'];

    ct[6] = num['X'];
    num['S'] -= num['X'];
    num['I'] -= num['X'];
    num['X'] -= num['X'];

    ct[8] = num['G'];
    num['E'] -= num['G'];
    num['I'] -= num['G'];
    num['H'] -= num['G'];
    num['T'] -= num['G'];
    num['G'] -= num['G'];

    ct[5] = num['F'];
    num['I'] -= num['F'];
    num['V'] -= num['F'];
    num['E'] -= num['F'];
    num['F'] -= num['F'];

    ct[9] = num['I'];
    num['N'] -= num['I'];
    num['N'] -= num['I'];
    num['E'] -= num['I'];
    num['I'] -= num['I'];

    ct[7] = num['S'];

    printf("Case #%d: ",e+1);
    for(int i = 0 ; i < 10 ; i++ ){
      for(int j = 0; j < ct[i]; j++ ){
        printf("%d",i);
      }
    }
    printf("\n");
  }
}
