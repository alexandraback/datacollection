#include<cstdio>
using namespace std;
typedef long long int llint;

// RangeList
llint lis[1002];

// Check Palindrome
bool ispal(llint n)
{
  int i,len=0;
  char seq[20];
  while(n)
  {
    seq[len++]=n%10;
    n/=10;
  }
  for(i=0;i<len/2;i++)
    if(seq[i]!=seq[len-i-1]) return false;
  return true;
}

// Main
int main(void)
{
  int tc,cs,lisc,l,r,mid,beg,end;
  llint i,A,B,sq,siz;

  // Preprocess
  lisc=0;
  siz=1e14;
  for(i=1;i*i<=siz;i++)
  {
    if(ispal(i))
    {
      sq=i*i;
      if(ispal(sq)) lis[lisc++]=sq;
    }
  }

  // Read Input
  scanf("%d",&tc);
  cs=1;
  while(tc--)
  {
    scanf("%lld%lld",&A,&B);
    printf("Case #%d: ",cs++);
    l=0,r=lisc-1;
    while(l<r)
    {
      mid=l+(r-l)/2;
      if(lis[mid]<A) l=mid+1;
      else r=mid;
    }
    if(lis[r]<A) puts("0");
    else
    {
      beg=r;
      l=0,r=lisc-1;
      while(l<r)
      {
        mid=l+(r-l+1)/2;
        if(lis[mid]>B) r=mid-1;
        else l=mid;
      }
      if(lis[l]>B) puts("0");
      else
      {
        end=l;
        printf("%d\n",end-beg+1);
      }
    }
  }
  return 0;
}
