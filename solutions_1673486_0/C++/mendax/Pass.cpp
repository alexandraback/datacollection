/* Author :  Jay Pandya */

// Standard includes
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<limits.h>
#include<string.h>

//Data Structures
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>

//Macros
#define all(c) c.begin(),c.end() //all element in container c

#define tr(container, it) \
   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //to iterate in container

#define stringswap(swstingA, swstringB) \
   swstringA.swap(swstringB) //to swap string

#define present(container, element) (container.find(element) != container.end()) //to check whether a element is in a set or a map
#define cpresent(container, element) (find(all(container),element) != container.end()) //to check whether  a element is in container like vector

#define print(x) cout<<#x<<" is "<<x<<endl;//for printing
#define sz(a) int((a).size()) 
#define pb push_back 
#define vi vector<int>; 
#define vvi  vector<vi>; //2D string 
#define ii pair<int,int>; 
#define mp(typeA,typeB)  make_pair<typeA,typeB> //maing pair

//macros for limits

#define MAX 1123456
#define LLI long long int
#define ULLI unsigned long long int

using namespace std;
double mymin(double a, double b)
{
   if(a <= b)
      return a;
   else
      return b;
}

long double p[100010];
long double ans,al,q[100010];

int main()
{
   int t,a,b;
   scanf("%d",&t);

   for(int test=1; test<=t; test++)
   {   
      scanf("%d %d",&a,&b);
      q[0]=1.0;
      al = 1.0;
      for(int i=1; i<=a; i++)
      {   
	 scanf("%Lf",&p[i]);
	 al *= p[i];
	 q[i] = q[i-1]*p[i];
      }   
      ans = mymin(b+2, al*(b-a+1) + (1-al)*(2*b-a+2));
      for(int k=1; k<a; k++)
	 ans = mymin(ans, q[a-k]*(2*k+b-a+1) + (1-q[a-k])*(2*k+2*b-a+2));
      ans = mymin(ans, a+b+1); 
      printf("Case #%d: %Lf\n",test,ans);
   }   
   return 0;
}

