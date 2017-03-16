#include <bits\stdc++.h>

using namespace std;

int n,x,r,c; 

void test(int nom)
{     cin>>x>>r>>c; //cout<<x<<" "<<r<<" "<<c<<" ";
      cout<<"Case #"<<nom<<": ";
	  if ((x>r&&x>c)||(min(r,c)==1&&x>2)||(min(r,c)==2&&x>3)||(min(r,c)==3&&x>4)||(min(r,c)==4&&x>5)||r*c%x!=0||x>6) 
		cout<<"RICHARD\n"; else cout<<"GABRIEL\n";
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>n; 
 for(int i=1;i<=n;++i) test(i);
}
