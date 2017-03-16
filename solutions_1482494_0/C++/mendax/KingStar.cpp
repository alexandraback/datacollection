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

int main()
{
   vector< pair<int,int> > v;
   int t,a,b,ans,n;
   bool onechecked[2056],twochecked[2056];
   scanf("%d",&t);

   for(int test=1; test<=t; test++)
   {
      memset(onechecked,0,sizeof onechecked);
      memset(twochecked,0,sizeof twochecked);
      v.resize(0);

      scanf("%d",&n);
      for(int i=1; i<=n; i++)
      {
	 scanf("%d%d",&a,&b);
	 pair <int,int> temp(a,-1*b);
	 v.push_back(temp);
      }
      sort(v.begin(), v.end());
      for(int i=0;i<n;i++)
	 v[i].second*=-1;

      int finished = 0;
      int score = 0;
      int countstep = 0;
      while(1)
      {
	 while(1)
	 {
	    int whflag = 0;
	    for(int i=0; i<n; i++)
	    {
	       if(v[i].second <= score && twochecked[i]==0)
	       {
		  if(onechecked[i] == 0)
		     score += 2;
		  else
		     score++;
		  onechecked[i] = 1;
		  twochecked[i] = 1;
		  countstep++;
		  whflag = 1;
		  break;

	       }
	    }
	    if(whflag == 0)
	       break;
	 }
	 int check = 0;
	 for(int i=0; i<n; i++)
	 {
	    if(twochecked[i] == 0)
	    {
	       check = 1;
	       break;
	    }
	 }
	 if(check == 0)
	    break;
	 int flag = 0;
	 for(int i=0; i<n; i++)
	 {
	    if(onechecked[i] == 0 && v[i].first <= score)
	    {
	       flag = 1;
	       score++;
	       onechecked[i] = 1;
	       countstep++;
	       break;
	    }
	 }
	 if(flag == 0)
	 {
	    finished = 1;
	    break;
	 }

      }
      if(finished == 1)
	 printf("Case #%d: Too Bad\n",test);
      else
	 printf("Case #%d: %d\n",test,countstep);
   }
   return 0;
}


