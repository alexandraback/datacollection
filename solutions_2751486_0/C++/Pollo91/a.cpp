#include<cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct sol {
  long long int end;
  long long int tot;
  int q;
};

#define MAX_L 1000005

bool voc(char c)
{
  return c=='a' || c=='e'|| c=='i' || c=='o' || c=='u';
}

int k,l;
char s[MAX_L];

sol mem[MAX_L];

int main()
{
  int t;

  scanf("%d",&t);
  for (int i=0; i<t; i++)
  {
    scanf("%s",s);
    scanf("%d\n",&k);
    l = strlen(s);
    //printf("%s\n",s);
    //printf("%d\n",k);
    //printf("%d\n",l);
    mem[l].q = 0;
    mem[l].end = 0;
    mem[l].tot = 0;
    for (int j=l-1; j>=0; j--)
    {
      mem[j].end = mem[j+1].end;
      mem[j].tot = mem[j+1].end + mem[j+1].tot;
      if (voc(s[j]))
      {
        mem[j].q = 0;
      }
      else
      {
        if (mem[j+1].q == k-1)
        {
          mem[j].q = k-1;
          mem[j].end = (l - (j+k-1));
        }
        else
        {
          mem[j].q = mem[j+1].q + 1;
        }
      }
      //printf("j %d\n",j);
      //printf("q %d end %d tot %d\n",mem[j].q,mem[j].end,mem[j].tot);
    }
    printf("Case #%d: %lld\n",i+1,mem[0].tot+mem[0].end);
  }
  return 0;
}
