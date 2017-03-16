#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		int A,B;cin>>A>>B;
		int D=0,W=1; for(int k=A;k;k/=10)D++,W*=10;
		D--,W/=10;
//		cout<<D<<" "<<W<<" ";
		int ans=0;
		int cand[6];int cs;
		for(int n=A;n<=B;n++){
			int m=n;cs=0;
			for(int d=0;d<D;d++){
				m=(m%W)*10+m/W;
				if(m<A)continue;
				if(m>B)continue;
				if(n>=m)continue;
				cand[cs++]=m;
			}
			sort(cand,cand+cs);
			int ds=unique(cand,cand+cs)-cand;
			ans+=ds;			
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}