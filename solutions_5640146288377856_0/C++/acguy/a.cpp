#include<iostream>
#include<cstdio>
using namespace std;
int main(void){
  int T;
  int R,C,W;
  cin>>T;
  for( int testcase=1;testcase<=T;testcase++){
    cin>>R>>C>>W;
    printf("Case #%d: %d\n",testcase, C/W*(R-1)+(C-1)/W+W);
  }
  return 0;
}

