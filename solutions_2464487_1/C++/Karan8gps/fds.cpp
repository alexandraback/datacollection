#include <cstdio>
#include <cstring>
#include<cstdlib>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
#define ll long long
#define MOD 1000000007
FILE *on=fopen("on.txt","w");
//using namespace std;
using namespace std;
int main(){
int tc;
cin>>tc;int y=0;
 while(tc--){y++;
	 long long r,t;
	 cin>>r>>t;
	 unsigned long long sco=0,count=0;unsigned long long first,last,middle;
	first = 0;
   last = 2*MOD;
   if(r>MOD){
             last =t;
   middle = (first+last)/r;}
   else middle=(first+last)/2;
 
   while( first <= last )
   {	long long m=middle;
      if ( (2*r+1)*m +(2*m*(m-1)) < t )
         first = middle + 1;    
      else if ( (2*r+1)*m +(2*m*(m-1)) == t ) 
      {
         //printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   
   //if ( first > last ){break;}
	 fprintf(on,"Case #%d: %d\n",y,middle);
	 }
	 fclose(on);
	 return 0;
	}
	
