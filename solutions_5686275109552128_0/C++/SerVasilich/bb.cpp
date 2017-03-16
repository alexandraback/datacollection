#include <bits\stdc++.h>

using namespace std;

int n,d,mi,ma,s,m[1001]; 

void test(int nom)
{     mi=1<<30; ma=0; cin>>d; for(int i=0;i<d;++i) {cin>>m[i]; ma=max(ma,m[i]);}
      for(int i=1;i<=ma;i++) {s=0;
       for(int j=0;j<d;j++) s+=(m[j]-1)/i;
	   mi=min(mi,i+s);}
      cout<<"Case #"<<nom<<": "<<mi<<'\n';
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>n; 
 for(int i=1;i<=n;++i) test(i);
}
