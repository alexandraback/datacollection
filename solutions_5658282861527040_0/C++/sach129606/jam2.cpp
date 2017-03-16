#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
typedef pair<int,int> ii;
int main()
{
freopen("inp.txt","r",stdin);
  freopen("out.txt","w",stdout);
 int t;
 cin>>t;
 int id=1;
  while(t--)
  {
  	 int a,b,k;
  	  cin>>a>>b>>k;
  	  int tot=0;
  	   for(int i=0;i<a;i++)
  	   {
  	   	 for(int j=0;j<b;j++)
  	   	  {
  	   	  	int l=i&j;
  	   	    //cout<<l<<" ";
  	   	     if(l<k)
  	   	   tot++;
  	      }
  	   }
  	cout<<"Case #"<<id<<": "<<tot<<endl;
  	id++;
  }	
	return 0;
	
}
