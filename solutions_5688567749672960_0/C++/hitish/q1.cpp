#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pi;
#define MOD 1000000007
#define MAX 1000000000
#define For(i,n) for(int i=0;i<n;i++) 

int ans[50000000];
int func(int i)
{
 if(ans[i]!=0) return ans[i];
 int n=i;
int reverse=0; 
 if(i%10!=0)
{ 
 while (n != 0)
   {
      reverse = reverse * 10;
      reverse = reverse + n%10;
      n= n/10;
   }
 if(i>reverse)
  return min(func(i-1)+1,func(reverse)+1);
}
 
return func(i-1)+1;
}

int main()
{
int _t;
for(int i=0;i<=20;i++)
ans[i]=i;

for(int i=21;i<=1000000;i++)
{
 ans[i]=func(i);
}

cin>>_t;

for(int _i=1;_i<=_t;_i++)
{
int t;
cin>>t;
cout<<"Case #"<<_i<<": "<<ans[t]<<endl;
}


}    


