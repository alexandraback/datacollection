// Shashank Jain
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#define LL long long int
using namespace std;
int E,R,N,ans;
LL v[100]; 
LL dp[12][12];
void run(int pos,int j,int gain)
{
	int i;      	
	if(pos==N)
     	{
                ans=max(ans,gain);
                return ;          
        }
                   
        for(i=0;i<=j;i++)
        {
                if((j-i+R)<=E)
                  	run(pos+1,(j-i)+R,gain+v[pos]*i);        
                else
                        run(pos+1,E,gain+v[pos]*i);
         }
}
int main()
{
	int tc,k,i;  
	scanf("%d",&tc);
        k=1;
	while(k<=tc)
	{       
                    
               	scanf("%d %d %d",&E,&R,&N);            
                for(i=0;i<N;i++)
			scanf("%lld",&v[i]);
               
                ans=0; 
                run(0,E,0);            
		printf("Case #%d: %d\n",k,ans);
		k++;     
                           
         }
         return 0;    
}
 
 
