#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<time.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<set>
#define Pi 3.14159265358
#define mod9 %1000000009
#define INF 1000000000LL
#define mod7 %1000000007
#define LL long long
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
 int i,n,x,y,a[1000001];
int main(){
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
    for (i=1;i<=1000000;i++)
        a[i]=INF;
    a[1]=1;
    for (i=1;i<=1000000;i++){
        a[i+1]=min(a[i+1],a[i]+1);
        x=i;
        y=0;
        while (x) y=y*10+x%10,x/=10;
        if (y<=1000000 && y>i) a[y]=min(a[y],a[i]+1);
//cout<<a[y]<<endl;
    }
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>x;
        cout<<"Case #"<<i<<": "<<a[x]<<endl;
    }
  return 0;
}
