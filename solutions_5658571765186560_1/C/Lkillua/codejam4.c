#include<stdio.h>

int main()
{
  int t,q=1,x,r,c,p;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&x,&r,&c);
    p=r*c;
    if(r>c)
        r=(r+c)-(c=r);
    if(x>=7)
      printf("Case #%d: RICHARD\n",q);
    else if(x==5 &&  (r==3 && c==5))
      printf("Case #%d: RICHARD\n",q);
    else if(x==6 && ((c==3) || (r==3)))
      printf("Case #%d: RICHARD\n",q);
    else if(x>p)
      printf("Case #%d: RICHARD\n",q);
    else if(p%x!=0)
      printf("Case #%d: RICHARD\n",q);
    else if(p%x==0 && r>=x-1 && c>=x-1)
      printf("Case #%d: GABRIEL\n",q);
    else if(p%x==0 && (r>=4 || c>=4) && x>=5)
      printf("Case #%d: GABRIEL\n",q);

    else if(p%x==0 && ((r==3 && c==10)) && x==5)
      printf("Case #%d: GABRIEL\n",q);
    else if(p%x==0 && ((r==3 && c==15)) && x==5)
      printf("Case #%d: GABRIEL\n",q);
    else if(p%x==0 && ((r==3 && c==20)) && x==5)
      printf("Case #%d: GABRIEL\n",q);

    else
      printf("Case #%d: RICHARD\n",q);
    q++;
    }
    return 0;
}
