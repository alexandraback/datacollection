//Lasha Bukhnikashvili
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#define INF 1000001
#define Pi 3.14159265358
#define mod9 %1000000009
#define mod7 %1000000007
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
 long long T,i,j,y,l,r,ans;
 int t[10000001];
 bool polindrome (long long x){
      int q[100]={0},s=0;
      while (x!=0)
            q[++s]=x%10,x=x/10;
      for (j=1;j<=s/2;j++)
          if (q[j]!=q[s-j+1]) return 0;
      return 1;
 };
int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
   for (i=1;i<=10000000;i=i+10){
       if (polindrome(i))
          if (polindrome(i*i)) t[i]=1;
       if (polindrome(i+1))
          if (polindrome((i+1)*(i+1))) t[i+1]=1;
   };
   t[3]=1;
   for (i=1;i<=10000000;i++)
       t[i]=t[i-1]+t[i];
   cin>>T;
   y=1;
   while (y<=T){
         cin>>l>>r;
         if (sqrt(l)==int(sqrt(l))) l=int(sqrt(l)); else l=int(sqrt(l))+1;
         r=int(sqrt(r));
         if(l>r)ans=0; else ans=t[r]-t[l-1];
         cout<<"Case #"<<y<<": "<<ans<<endl;
         y++;
   };   
 return 0;
}

