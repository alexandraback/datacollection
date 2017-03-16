#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int T;
    int R,C,W,score;
    scanf("%d",&T);
    for(int i = 1;i<=T;++i){
          score = 0;
          scanf("%d%d%d",&R,&C,&W);
          if(W==1) score = C;
          else if(W==C) score = C;
          else if(C%W!=0)   score = (C/W)+(W-1)+1;
          else score = (C/W)+(W-1);
          printf("Case #%d: %d\n",i,score*R);
    }      
    return 0;
}
