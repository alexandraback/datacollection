#include<cstdio>
using namespace std;

// RangeList
int lis[1002];

// Check Palindrome
bool ispal(int n)
{
  int i,len=0;
  char seq[10];
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
  int tc,cs,i,A,B,lisc,sq,l,r,mid,beg,end;

  // Preprocess
  lisc=0;
  for(i=1;i*i<=1000;i++)
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
    scanf("%d%d",&A,&B);
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
