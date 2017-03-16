#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

bool comp (int i, int j) { return (j<i);}

int T=1,TC;
int A,B;

int ipow(int x, int n)
{
  if (n==0)
    return 1;
  else
    return x*ipow(x,n-1);
}

void pop(int n, int & count)
{
  int s = int(ceil(log10(n)));
  set<int> S;
  for (int i=1;i<s;++i)
  {
    int back = ipow(10,i);
    int front = ipow(10,s-i);
    int x=n;
    int t;
    int ans;
    t=x%back;
    x/=back;
    ans=front*t+x;
    if (ans >= A && ans <= B && ans > n)
      S.insert(ans);
  }
  count += S.size();
}

int main()
{
  for (scanf("%d ",&TC);T<=TC;++T)
  {
    int count = 0;
    scanf("%d %d",&A,&B);
    for (int n=A;n<=B;++n)
    {
      pop(n,count);
    }


    printf("Case #%d: %d\n",T,count);
  }
  
  
}
