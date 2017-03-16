#include <bits\stdc++.h>

using namespace std;
#define ll long long
int T;

void test(int nom)
{     ll r,c,w,k; 
      cin>>r>>c>>w; k=(c-1)/w+1;
	  cout<<"Case #"<<nom<<": "<<k*r+w-1<<'\n';
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 
 cin>>T; 
 for(int i=1;i<=T;++i) test(i);
}
