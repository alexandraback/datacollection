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
#define max(a,b) ((a)>(b))?(a):(b)
FILE *on=fopen("on.txt","w");

using namespace std;
int v[100];
 
		int dp[11][11];
   int e,r,n,max1;
   void dpk(int pos,int en,int gain)
{
                   if(pos==n)
                   {
                             
                                   
                             max1=max(max1,gain);
                             return ;          
                   }
                   
                   
                   for(int i=0;i<=en;i++)
                   {
                                         if((en-i+r)<=e)
                                         dpk(pos+1,(en-i)+r,gain+v[pos]*i);        
                                         else
                                         dpk(pos+1,e,gain+v[pos]*i);
                   }
                   
                   return ;
}
int main(){
int tc;
cin>>tc;int y=0;
 while(tc--){y++;
	 cin>>e>>r>>n;
	 for(int i=0;i<n;i++)
                                    cin>>v[i];
                            
 
                            max1=0;
                            
                            dpk(0,e,0);  
		
   //if ( first > last ){break;}
	 fprintf(on,"Case #%d: %d\n",y,max1);
	 }
	 fclose(on);
	 return 0;
	}
	
