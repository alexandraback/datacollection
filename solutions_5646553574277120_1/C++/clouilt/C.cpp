#include <iostream>
#include <algorithm>
using namespace std;
int T,C,D,V;

int main(){
	int had[103];
	cin>>T;
	for(int cs=1; cs<=T; ++cs){
		cin>>C>>D>>V;
		int res=0;
		long long sum=0;
		long long needm=1;
		for(int i=0;i<D;++i)
			cin>>had[i];

		int d=0;
		while(sum*C < V){
			if(d <D && had[d] <= needm){
				sum+=had[d];
				needm=sum*C+1;
				++d;
			}else{
				++res;
				sum+=needm;
				needm=sum*C+1;
			}
		}
		cout<<"Case #"<<cs<<": "<<res<<endl;
	}
	return 0;
}
