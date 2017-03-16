#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9+7
deque<char> q;
int main()
{
 // freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ll t;
  cin>>t;
  for(ll test=1;test<=t;test++)
  {
     string s;
     cin>>s;
     q.push_back(s[0]);
     int i=1;char a;
     while(i<s.length())
     {
     	a=q.front();
     	if(s[i]>=a)
     	 q.push_front(s[i]);
     	 
     	else q.push_back(s[i]); 
     	i++;
     }
      cout<<"Case #"<<test<<": ";
      while(!q.empty())
	  {
	  	 cout<<q.front();
	  	 q.pop_front();
	  } 
	  q.clear();
	  cout<<endl;
}
  return 0;
}
