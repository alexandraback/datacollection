#include <bits\stdc++.h>

using namespace std;
#define ll long long
int T;

void test(int nom)
{     ll t,c,d,v,s=1,k=0,m[101]; 
      cin>>c>>d>>v;
	  for(int i=0;i<d;i++) cin>>m[i]; m[d]=v+1;d++;
	  for(int i=0;i<d;i++) {if (s>v) break;
	   while (s<m[i]) {k++; s+=s*c; }
	   s+=m[i]*c;}
	  
	  cout<<"Case #"<<nom<<": "<<k<<'\n';
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 
 cin>>T; 
 for(int i=1;i<=T;++i) test(i);
}
