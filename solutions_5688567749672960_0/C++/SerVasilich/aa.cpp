#include <bits\stdc++.h>

using namespace std;

int T;

void test(int nom)
{     int n,c=1,t=1,tt,r; cin>>n; map<int,int> m; set <int> s[2]; set<int>::iterator it; s[0].insert(1); m[1]=1;
      while (m[n]==0) {s[c].clear(); c=1-c; t++; 
	   for(it=s[c].begin();it!=s[c].end();it++) 
	   {tt=(*it); tt++;
	    if (m[tt]==0) {m[tt]=t; s[1-c].insert(tt);}
	    r=0; tt--; while(tt>0) {r=r*10+tt%10; tt/=10;} 
		if (m[r]==0) {m[r]=t; s[1-c].insert(r);}
	   }
	  }
	  cout<<"Case #"<<nom<<": "<<m[n]<<'\n';
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 
 cin>>T; 
 for(int i=1;i<=T;++i) test(i);
}
