//gskhirtladze

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

long long a[500];
long long ansss,i,t1,t,now,n,j;

long long solve(long long sum,long long l,long long r)
 {
  while (sum>a[l] && l<=r)
   {
    sum+=a[l];
    l++;
   }
  if (l>r) return 0;
  if (sum == 1) return 20000000;
  return solve(sum*2-1,l,r)+1;
 }

main()
 {
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  
  cin>>t;
  for (t1=1;t1<=t;t1++)
   {
    cout<<"Case #"<<t1<<": ";
    cin>>now>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ansss=n;
    for (j=0;j<=n;j++)
     ansss=min(ansss,solve(now,1,n-j)+j);
    cout<<ansss<<endl;
   }
  
 }
