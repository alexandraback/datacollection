#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long int
int h[30];
using namespace std;
vector<string> v;
bool canpick(int num)
{
//	cout<<"can pic "<<num<<endl;
	    int s=v[num].length();
	    bool f=1;
	    for(int i=0;i<s;i++)
	    {
	    	 
	           if(h[v[num][i]-'A']>0)
			  {
			  //	  cout<<v[num][i]<<endl;
			  	  continue;
			  }
			   else 
			   {
			   	  f=0;
			   	  break;
				   }	
		}
//		cout<<"ret "<<f<<endl;
		return f;
}
void pick(int num)
{
	   int l=v[num].length();
	   for(int i=0;i<l;i++)
	   {
	   	   h[v[num][i]-'A']--;
	   }
}
int main()
{ 
           freopen("abc.in","r",stdin);
           freopen("out3.txt","w",stdout);
           int t;
           int tt=0;
           cin>>t;
           v.pb("ZERO");
           v.pb("ONE");
           v.pb("TWO");
           v.pb("THREE");
           v.pb("FOUR");
           v.pb("FIVE");
           v.pb("SIX");
           v.pb("SEVEN");
           v.pb("EIGHT");
            v.pb("NINE");
		   while(t--)
		   {
		   	tt++;
		   	//vector<int> res;
		     // vector<string> v;
		  //    int h[30];
		      memset(h,0,sizeof(h));
      	     string s;
           	     cin>>s;
           	     int l=s.length();
           	     for(int i=0;i<l;i++)
           	     {
           	     	  h[s[i]-'A']++;
				 }
		   vector<int> res;
		   int arr[]={0,2,8,4,5,6,9,3,1,7};
		   for(int i=0;i<10;)
		   {
		   //	cout<<"her   "<<endl;
		  // cout<<"try "<<arr[i]<<endl;
		   	          int sum=0;
		   	          for(int k=0;k<26;k++)
		   	          sum+=h[k];
		   	          if(sum==0)
		   	          break;
		   	//          cout<<"picj "<<arr[i]<<endl;
		   	          if(canpick(arr[i]))
		   	          {
		   	          	//cout<<"her "<<endl;
		   	//          	cout<<"cna pick "<<arr[i]<<endl;
		   	                  pick(arr[i]);
								res.pb(arr[i]);	
					  }
					  else i++;
					  
		    }
		    int sum=0;
		    for(int i=0;i<26;i++)
		    sum+=h[i];
		 //   cout<<"suj "<<sum<<endl;
		    sort(res.begin(),res.end());
		    int sz=res.size();
		    cout<<"Case #"<<tt<<":"<<" ";
		    for(int i=0;i<sz;i++)
		    cout<<res[i];
		    cout<<endl;
	    }
	    return 0;
}
