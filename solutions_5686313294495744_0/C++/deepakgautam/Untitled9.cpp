#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long int
using namespace std;
#define debug 0
int main()
{ 
           freopen("abc.txt","r",stdin);
           freopen("out1.txt","w",stdout);
           int t;
           cin>>t;
           int tt=0;
           while(t--)
           {
           	     tt++;
           	     if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
           	     int n;
           	     cin>>n;
           	      if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
           	     map<string,int> m1,m2;
           	     vector<pair<string,string> > v;
           	     for(int i=0;i<n;i++)
           	     {
           	     	   string a,b;
           	     	    if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
           	     	   cin>>a>>b;
           	     	   v.pb(mp(a,b));
           	     	  
				 }
				  if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
				// cout<<"haan "<<endl;
				 int ans=0;
				 int mx=(1<<n)-1;
				 for(int i=1;i<mx;i++)
				 {
				 	 if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
				 	int temp=0;
				 	m1.clear();
				 	m2.clear();
				 	 if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
			//	 	cout<<"mas "<<i<<endl;
				 	  for(int j=0;j<n;j++)
				 	  {
				 	       if(i>>j&1)
							{
								 if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
						//		cout<<"inside at "<<j<<endl;
							    m1[v[j].ff]++;
								m2[v[j].ss]++;
						//		cout<<"my "<<v[j].ff<<" "<<v[j].ss<<endl;       	
							}	
					  }
					  for(int j=0;j<n;j++)
				 	  {
				 	       if((i>>j&1)==0)
							{
								 if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
							   if(m1[v[j].ff]>0 && m2[v[j].ss]>0)
							   temp++;       	
							}	
					  }
					   if(debug)
           	     {
           	     	 for(int i=0;i<=10;i++)
           	     	  {
           	     	  	 cout<<"ok";
						  }
					}
					  ans=max(ans,temp);
				 }
				 cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;
}
