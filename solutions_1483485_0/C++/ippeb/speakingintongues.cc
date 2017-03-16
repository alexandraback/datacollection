#include <cstdio>
#include <iostream>
using namespace std;

const char Q[]="ynficwlbkuomxsevzpdrjgthaq";
char A[1<<8];


int T;
char S[1000];

int main(){
  for (int i='a'; i<='z'; i++) A[Q[i-'a']]=i;
  
  scanf("%d ",&T);
  for (int i=1; i<=T; i++){
    fgets(S,1000,stdin);
    int s=strlen(S);
    printf("Case #%d: ",i);
    for (int j=0; j<s; j++){
      if (S[j]=='\n') break;
      else if (S[j]>='a' && S[j]<='z') printf("%c",A[S[j]]);
      else printf("%c",S[j]);
    }
    printf("\n");
  }
}

