#include<stdio.h>
#include<string.h>
#define ll long long
char cal(char a,char b)
{
    if(b==0)
      return 0;
    if(a=='i' && b=='j')
      return 'k';
    if(a=='j' && b=='k')
      return 'i';
    if(a=='k' && b=='i')
      return 'j';
    if(a=='j' && b=='i')
      return 'K';
    if(a=='k' && b=='j')
      return 'I';
    if(a=='i' && b=='k')
      return 'J';
    if(a=='i' && b=='i')
      return 'L';
    if(a=='j' && b=='j')
      return 'L';
    if(a=='k' && b=='k')
      return 'L';


   if(a=='I' && b=='j')
      return 'K';
    if(a=='J' && b=='k')
      return 'I';
    if(a=='K' && b=='i')
      return 'J';
    if(a=='J' && b=='i')
      return 'k';
    if(a=='K' && b=='j')
      return 'i';
    if(a=='I' && b=='k')
      return 'j';
    if(a=='I' && b=='i')
      return 'l';
    if(a=='J' && b=='j')
      return 'l';
    if(a=='K' && b=='k')
      return 'l';

    if(a=='l' && b=='i')
      return 'i';
    if(a=='l' && b=='j')
      return 'j';
    if(a=='l' && b=='k')
      return 'k';
    if(a=='L' && b=='i')
      return 'I';
    if(a=='L' && b=='j')
      return 'J';
    if(a=='L' && b=='k')
      return 'K';

}
int main()
{
  ll int t,q,l,x,f,i,j,len;
  char text[10010],k;
  scanf("%lld",&t);
  q=1;
  while(t--)
  {
      scanf("%lld%lld",&l,&x);
      scanf("%s",text);
      f=0;
      for(i=0;i<l;i++)
      {
          for(j=1;j<x;j++)
            text[i+(j*l)]=text[i];
      }
      text[i+((x-1)*l)]=0;
      len=strlen(text);
      k=text[0];
      for(i=0;i<len;i++)
      {
          if(k=='i' && f==0)
          {
              f=1;
              i++;
              k=text[i];
          }
          if(k=='j' && f==1)
          {
              f=2;
              i++;
              k=text[i];
          }
          if(k=='k' && f==2 && i==len-1)
          {
              f=3;
              i++;
              k=text[i];
          }
          k=cal(k,text[i+1]);
      }
      if(f==3)
        printf("Case #%d: YES\n",q);
      else
        printf("Case #%d: NO\n",q);
      q++;
  }

  return 0;
}
