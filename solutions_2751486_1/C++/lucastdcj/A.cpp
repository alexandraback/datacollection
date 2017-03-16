#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define TAM 1123123

bool is_consoante(char c){

  if(c == 'a') return false;
  if(c == 'e') return false;
  if(c == 'i') return false;
  if(c == 'o') return false;
  if(c == 'u') return false;
  return true;
}

int main(){
  int n;
  int nt,t;
  char s[TAM];
  scanf(" %d",&nt);
  t = 1;
  while(nt--){
    scanf(" %s %d",s,&n);
    long long int ans = 0;
    long long int aux = 0;
    long long int fim = 0;
    for(int i = 0 ; i < strlen(s) ;i++){
      if(is_consoante(s[i])) aux++;
      else aux = 0;
      if(aux >= n){
	
	ans += (long long int)(strlen(s) - i)*(long long int)(i - n + 1 - fim + 1);
	fim = i - n + 2;      
	aux =  n-1;
      }
      //printf("%d\n",ans);
    }
     
    printf("Case #%d: %lld\n",t++,ans);
  }
  return 0;

}
