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
    int ans = 0;
    for(int i = 0 ; i < strlen(s) ;i++)
      for(int j = 0 ; j < strlen(s) ; j++){
	int aux = 0;
	for(int k = i ; k <= j ; k++){
	  if(!is_consoante(s[k])) aux = 0;
	  if(is_consoante(s[k])) aux++;
	  if(aux >= n){
	    ans++;
	    break;
	  }
	}

      }	
    printf("Case #%d: %d\n",t++,ans);
  }
  return 0;

}
