#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<map>
#include<cmath>
using namespace std;
int main()
{
  freopen("jam1c_a_que.txt","r",stdin);
  freopen("jam1c_a_ans.txt","w",stdout);
  int t,count;
  cin>>t;
  for(count=1;count<=t;count++) {
    cout<<"Case #"<<count<<": ";
    int a[15],i,j,n,m,w;
    cin>>n>>m>>w;
    cout<<(m/w)+w-1+((m%w==0)?(0):(1))+(n-1)*(m/w)<<"\n";
  }
  return 0;
}
