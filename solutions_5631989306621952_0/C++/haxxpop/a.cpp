#include <stdio.h>
#include <string.h>

char s[100000];
char tab[100000];
int front,rear;
int main(){
  int t;
  scanf("%d",&t);
  for(int e = 0 ; e < t ; e++ ){
    scanf("%s",s);
    front = 10000;
    rear = front-1;
    int n = strlen(s);
    tab[++rear] = s[0];
    for(int i = 1 ; i < n ; i++ ){
      if( s[i] >= tab[front] ){
        tab[--front] = s[i];
      }else{
        tab[++rear] = s[i];
      }
    }
    tab[rear+1] = 0;
    printf("Case #%d: ",e+1);
    printf("%s\n",tab+front);
  }
}

