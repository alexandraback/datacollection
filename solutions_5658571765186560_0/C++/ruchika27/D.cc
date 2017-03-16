#include<stdio.h>


int main()
{
  int T, t;
  bool ANS[4][4][4] = 
    {
      {{false, false, false, false}, 
       {false, false, false, false}, 
       {false, false, false, false}, 
       {false, false, false, false}},
      
      {{true, false, true, false}, 
       {false, false, false, false}, 
       {true, false, true, false}, 
       {false, false, false, false}},
      
      {{true, true, true, true}, 
       {true, true, false, true}, 
       {true, false, false, false}, 
       {true, true, false, true}},

      {{true, true, true, true}, 
       {true, true, true, true}, 
       {true, true, true, false}, 
       {true, true, false, false}}
    };
  scanf("%d", &T);
  for(t=1; t<=T; t++)
    {
      int X, R, C;
      scanf("%d %d %d", &X, &R, &C);
      printf("Case #%d: %s\n", t, ANS[X-1][R-1][C-1]?"RICHARD":"GABRIEL");
    }
}
