#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	int tc, j,p,s,k,sum;
	scanf("%d",&tc);
	for(int i=1; i<=tc; i++){
		scanf("%d %d %d %d",&j,&p,&s,&k);
		set<pair<int,int> > jp,js,ps;
		set <pair<pair<int,int>,int> > a;
		for(int l=1; l<=j; l++)
			for(int m=1; m<=p; m++)
				for(int n=1; n<=(min(k,s));n++)
					if(js.find(make_pair(l,n))==js.end()&&ps.find(make_pair(m,n))==ps.end())
					{
						//jp.insert(make_pair(l,m));
						js.insert(make_pair(l,n));
						ps.insert(make_pair(m,n));
						a.insert(make_pair(make_pair(l,m),n)); 
						//printf("s %d %d %d\n", l,m,n);
					}
				//printf("end s\n");
			js.clear();
			ps.clear();
		for(int l=1; l<=j; l++)
			for(int m=1; m<=s; m++)

				for(int n=1; n<=min(k,p);n++)
					if(jp.find(make_pair(l,n))==jp.end()&&ps.find(make_pair(n,m))==ps.end())
					{
						//js.insert(make_pair(l,m));
					jp.insert(make_pair(l,n));
					ps.insert(make_pair(n,m));
					 a.insert(make_pair(make_pair(l,n),m)); 
						//printf("p %d %d %d\n", l,n,m);
					}
					jp.clear();
					ps.clear();

		for(int l=1; l<=s; l++)
			for(int m=1; m<=p; m++)
				for(int n=1; n<=min(k,j);n++)
					if(jp.find(make_pair(n,m))==jp.end()&&js.find(make_pair(n,l))==js.end())
					{
						jp.insert(make_pair(n,m));
					js.insert(make_pair(n,l));
					a.insert(make_pair(make_pair(n,m),l)); 
						//printf("j %d %d %d\n", n,m,l);
					}
		printf("Case #%d: %d\n",i,a.size() );
		//for(int l=0; l<a.size(); l++)
		for (std::set<pair<pair<int,int>,int> >::iterator it=a.begin(); it!=a.end(); ++it)
			printf("%d %d %d\n",it->first.first,it->first.second,it->second );
		//sum=j*p*(min(s,k));
		//sum+=s*p*(min(j,k));
		//sum+=j*s*(min(p,k));

	}
}