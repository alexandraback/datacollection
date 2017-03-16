//Author: Jaydeep
//
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define vec vector<ll>
#define matrix vector<vector<ll> >
#define pritnf printf
#define pb push_back



int main()
{
	ll t,i=0,j,k,x,y,z,count=0,p,flag=0,ans=0,sum=0,l,n,t1,m;
	
	char s[200005];
	
	scanf("%lld",&t);
	
	t1=t;
	
	while(t--)
	{
	    
	    ll a[100][100]={0};
	    
	    
	    scanf("%lld%lld",&n,&m);
	    
	    
	    a[1][n]=1;
	    m--;
	    
	    
	    flag=0;
	    
	    for(i=1;i<n-2;i++)
	    {
	        
	        if(i==1)
	        {
	            
	            for(j=2;j<=n-1;j++)
	            {
	                a[1][j]=1;
	                a[j][n]=1;
	                
	                m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	                
	                
	            }
	            
	 
	        }
	        
	        
	        else if(i==2)
	        {
	            
	            for(j=2;j<=n-2;j++)
	            {
	                for(k=j+1;k<=n-1;k++)
	                {
	                    a[1][j]=1;
	                    a[j][k]=1;
	                    a[k][n]=1;
	                
	                    m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	                    
	                    
	                }
	                
	                if(flag==1)
	                    break;
	            }
	            
	            
	            
	            
	            
	        }
	        
	        else if(i==3)
	        {
	            
	            
	            if(n==5)
	            {
	                a[1][2]=1;
	                    a[2][3]=1;
	                    a[3][4]=1;
	                    a[4][5]=1;
	                    
	                    m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	                
	                
	                
	            }
	            else if(n==6)
	            {
	                
	                a[1][2]=1;
	                    a[2][3]=1;
	                    a[3][4]=1;
	                    a[4][6]=1;
	                    
	                    m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	                
	                
	                a[1][2]=1;
	                    a[2][3]=1;
	                    a[3][5]=1;
	                    a[5][6]=1;
	                    
	                    m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	                
	                
	                
	                a[1][2]=1;
	                    a[2][4]=1;
	                    a[4][5]=1;
	                    a[5][6]=1;
	                    
	                    m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	                
	                a[1][3]=1;
	                    a[3][4]=1;
	                    a[4][5]=1;
	                    a[5][6]=1;
	                    
	                    m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	                
	                
	            }
	            
	            
	            
	            
	            
	        }
	        
	        else if(i==4)
	        {
	            a[1][2]=1;
	                    a[2][3]=1;
	                    a[3][4]=1;
	                    a[4][5]=1;
	                    a[4][5]=1;
	                    m--;
	                
	                if(m==0)
	                {
	                    flag=1;
	                    break;
	                    
	                }
	            
	            
	            
	        }
	        
	        
	        
	        if(flag==1)
	            break;
	        
	        
	        
	        
	        
	        
	        
	        
	        
	        
	        
	        
	        
	       
	    }
	    
	    
	    pritnf("Case #%lld: ",t1-t);
	    
	    
	    if(m==0)
	    {
	        printf("POSSIBLE\n");
	        
	        
	        for(i=1;i<=n;i++)
	           {
	               for(j=1;j<=n;j++)
	                printf("%lld",a[i][j]);
	                
	                printf("\n");
	           }
	        
	    }
	   else
	   
	    	        printf("IMPOSSIBLE\n");

	    
	    
	    
	    
	    
	    
	    
		
		
	}
	
	
	return 0;
}
