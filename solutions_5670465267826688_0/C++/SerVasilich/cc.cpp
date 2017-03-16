#include <bits\stdc++.h>

using namespace std;

int n,o[4][4]={104,105,106,107,105,-104,107,-106,106,-107,-104,105,107,106,-105,-104}; 

void test(int nom)
{     int l,t,x,c=1,f=0;  string k; 
      cin>>l>>x>>k;   
	  t=k[0]; if (t==105) f=1;
	  for(int i=1;i<l*x;++i) {t=o[t-104][k[i%l]-104]; if (t<0) {c=-c; t=-t;}
       if (!f&&t*c==105) f=1; if (f==1&&t*c==107) f=2; 
	   //if (f==2&&t*c==-104) if ((x*l)%(i+1)==0 && (x*l)/(i+1)%2==1) {f=3;break;}   
	  }
	  cout<<"Case #"<<nom<<": ";
	  if (f==2 && t*c==-104) cout<<"YES\n";  else cout<<"NO\n";
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>n; 
 for(int i=1;i<=n;++i) test(i);
}
