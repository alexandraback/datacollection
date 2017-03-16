#include <bits\stdc++.h>

using namespace std;

int n;

void test(int nom)
{     int m,c=0,s=0;  string k; 
      cin>>m>>k;
	  for(int i=0;i<=m;++i) { 
	   s+=max(0,i-c-s); c+=k[i]-48;}
	  cout<<"Case #"<<nom<<": "<<s<<'\n';
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>n; 
 for(int i=1;i<=n;++i) test(i);
}
