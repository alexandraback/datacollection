#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
struct lv{
	int a,b;
	bool operator<(const lv cp)const{
		if(b!=cp.b)
			return b<cp.b;
		return a<cp.a;
	}
};
int main(){
	int t;
	cin>>t;
	int st;
	lv ls[1009];
	int cp[1009];
	int nl;
	int lc;
	int tc;
	for(int z=1;z<=t;z++){
		cin>>nl;
		for(int i=0;i<nl;i++){
			cin>>ls[i].a>>ls[i].b;
			cp[i]=0;
		}
		sort(ls,ls+nl);
		st=0;
		lc=0;
		tc=0;
		bool fd;
		bool fl=false;
		while(st<nl*2){
			if(ls[tc].b<=st){
				lc++;
				st+=2-cp[tc];
				cp[tc]=2;
				tc++;
				continue;
			}
			fd=false;
			for(int i=nl-1;i>=0;i--){
				if(ls[i].a<=st && cp[i]==0){
					fd=true;
					st++;
					cp[i]=1;
					lc++;
					break;
				}
			}
			if(fd)
				continue;
			fl=true;
			cout<<"Case #"<<z<<": Too Bad"<<endl;
			break;
		}
		if(!fl)
			cout<<"Case #"<<z<<": "<<lc<<endl;
		//printf("Case #%d: ",z);
	}
	return 0;
}
