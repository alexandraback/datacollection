#include <cstdio>

bool canAlwaysWin(int X,int R,int C)
{
  switch(X)
    {
    case 1:
      return true;
    case 2:
      return R%2==0 || C%2==0;
    case 3:
      return (R==3 && C>=2) || (C==3 && R>=2);
    case 4:
      return (R==4 && C>=3) || (C==4 && R>=3);
    default:
      return true;
    }
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int t=1;t<=n;t++)
    {
      int X,R,C;
      scanf("%d %d %d",&X,&R,&C);
      bool rst = canAlwaysWin(X,R,C);
      printf("Case #%d: %s\n",t,rst?"GABRIEL":"RICHARD");
    }
}
