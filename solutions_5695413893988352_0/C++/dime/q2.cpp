#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long int
using namespace std;
string a,b;
int n,m;
ll lef=-1;
ll rt=-1;
ll ans=2*1000000000000000000;
void solve(ll n1,ll n2,int pos1,int pos2)
{
	       if(pos1==n && pos2==m)
	       {
	       	      if(ans>abs(n1-n2))
					 {
					 	  ans=abs(n1-n2);
					 	  lef=n1;
					 	  rt=n2;
					 }
					 return ;   
		   }
		   ll nn1=n1;
		   ll nn2=n2;
		   
		   if(a[pos1]=='?' && b[pos2]=='?')
		   {
		   	       for(int i=0;i<10;i++)
		   	       {
		   	       	  for(int j=0;j<10;j++)
		   	       	  {
		   	       	       solve(nn1*10+i,nn2*10+j,pos1+1,pos2+1);	
					  }
				  }
		   }
		   else if(a[pos1]=='?' || b[pos2]=='?')
		   {
		   	    if(a[pos1]=='?')
		   	    {
		   	    	  for(int i=0;i<10;i++)
		   	    	  {
		   	    	      solve(nn1*10+i,nn2*10+(b[pos2]-'0'),pos1+1,pos2+1);	
					  }
			    }
			    else
			    {
			    	    for(int i=0;i<10;i++)
			    	    {
			    	    	  solve(nn1*10+(a[pos1]-'0'),nn2*10+i,pos1+1,pos2+1);
						}
				}
		   }
		   else
		   {
		   	    solve(nn1*10+(a[pos1]-'0'),nn2*10+(b[pos2]-'0'),pos1+1,pos2+1);
		   }
}
int main()
{ 
           freopen("abc.in","r",stdin);
           freopen("out2.txt","w",stdout);
           
           int t;
           cin>>t;
           int tt=0;
           while(t--)
           {
           	 ans=2*1000000000000000000;
		     tt++;
		   cin>>a>>b;
           n=a.length();
           m=b.length();
            solve(0,0,0,0);
            char p1[10],p2[10];
            cout<<"Case #"<<tt<<": ";
            sprintf(p1,"%lld",lef);
            sprintf(p2,"%lld",rt);
            //cout<<"ll "<<lef<<" "<<rt<<endl;
           // cout<<"p1 "<<p1<<" "<<p2<<endl;
            int l1=strlen(p1);
            int l2=strlen(p2);
            for(int i=0;i<n-l1;i++)
            cout<<"0";
            cout<<p1<<" ";
            for(int i=0;i<n-l2;i++)
            cout<<"0";
            cout<<p2;
            cout<<endl;
       }
       return 0;
}
