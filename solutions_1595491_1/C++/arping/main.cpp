#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int nmax[31],smax[31];
int main(){
	for(int k=0;k<=30;k++){
		nmax[k]=(k+2)/3;
		if(k>=2 && k<=28)smax[k]=(k+4)/3;
//		cout<<k<<" "<<nmax[k]<<" "<<smax[k]<<endl;		
	}
	int T;cin>>T;
	for(int m=1;m<=T;m++){
		int N,S,P;cin>>N>>S>>P;
		vector<int> d(N);for(int k=0;k<N;k++)cin>>d[k];
		sort(d.begin(),d.end(),greater<int>());
//for(int k=0;k<N;k++)cout<<d[k]<<endl;		
		int k=0;
		for(;k<N;k++){
			if(nmax[d[k]]>=P)continue;
			for(;S-- && k<N;k++){
				if(smax[d[k]]>=P)continue;
				break;
			}
			break;
		}
		cout<<"Case #"<<m<<": "<<k<<endl;
	}
	return 0;
}