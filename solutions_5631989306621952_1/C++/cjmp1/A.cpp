#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
deque<char> ans;
char str[1011];
int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  int T; scanf("%d",&T);
  for(int i1 = 1 ; i1 <= T; i1++){
    ans.clear();
    printf("Case #%d: ",i1);
    scanf("%s",str); int len = strlen(str);
    ans.push_back(str[0]);
    for(int i = 1; i < len; i++){
      if((int)ans.front() <= (int)str[i]) ans.push_front(str[i]);
      else ans.push_back(str[i]);
    }
    for(int i = 0; i < len; i++) str[i] = 0;
    deque<char>::iterator it;
    for(it = ans.begin(); it != ans.end(); ++it){
      printf("%c",*it);
    }
    printf("\n");
  }
  return 0;
}