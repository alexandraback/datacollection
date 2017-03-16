#include<stdio.h>
#include<iostream>
#include<algorithm>
#define N 1000005
using namespace std;


int a[N]={0,};

int reverse(int n)
{
    int ans = 0;

  //  printf("%d  ",n);
    while(n)
    {
        ans = ans*10 + n%10;
        n /= 10;
    }
  //  printf("%d\n",ans);
    return ans;
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    a[1]=1;
    for(int i = 2; i<N; i++)
    {
        int rev = reverse(i);
        if(rev>=i || i%10==0) a[i] = a[i-1]+1;
        else a[i] = min(a[rev],a[i-1])+1;

      //  printf("%d %d\n",i,a[i]);
    }

    int T;
    scanf("%d",&T);
    for(int t = 0; t<T; t++)
    {
        int n;
        cin>>n;
       // cout<<n;
        printf("Case #%d: %d\n",t+1,a[n]);
    }
    return 0;
}
