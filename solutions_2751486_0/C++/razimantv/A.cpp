# include <cstdio>

char isvowel[128],vowels[]="aeiou";
char inp[1000001];

int main()
{
  for(int i=0;i<5;i++)
    isvowel[vowels[i]]=1;

  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    int L;
    scanf("%s%d",inp,&L);

    long long ret=0;
    int lateststart=-1,cntcons=0;
    for(int i=0;inp[i];i++)
    {
      if(isvowel[inp[i]])cntcons=0;
      else cntcons++;

      if(cntcons>=L)lateststart=i-L+1;
      ret+=lateststart+1;
    }

    printf("Case #%d: %Ld\n",t,ret);
  }
  return 0;
}
