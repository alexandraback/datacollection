#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long int
using namespace std;

int main()
{ 
           freopen("abc.in","r",stdin);
           freopen("out1.txt","w",stdout);
           int t;
           cin>>t;
           int tt=0;
           while(t--)
           {
           	     tt++;
           	     int n;
           	     cin>>n;
           	     map<string,int> m1,m2;
           	     vector<pair<string,string> > v;
           	     for(int i=0;i<n;i++)
           	     {
           	     	   string a,b;
           	     	   cin>>a>>b;
           	     	   v.pb(mp(a,b));
           	     	  
				 }
				// cout<<"haan "<<endl;
				 int ans=0;
				 int mx=(1<<n)-1;
				 for(int i=1;i<mx;i++)
				 {
				 	int temp=0;
				 	m1.clear();
				 	m2.clear();
			//	 	cout<<"mas "<<i<<endl;
				 	  for(int j=0;j<n;j++)
				 	  {
				 	       if(i>>j&1)
							{
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
							   if(m1[v[j].ff]>0 && m2[v[j].ss]>0)
							   temp++;       	
							}	
					  }
					  ans=max(ans,temp);
				 }
				 cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;
}
