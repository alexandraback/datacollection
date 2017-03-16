#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <utility>
int main(){
	int T,i1;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(i1=0;i1<T;i1++){
		int A,B,K,i,j,res=0;
		cin>>A>>B>>K;
		for(i=0;i<A;i++)
			for(j=0;j<B;j++){
				/*if(i==j)
					res--;*/
				if((i&j)<K){
					res++;
					//cout<<(i&j)<<' '<<i<<' '<<j<<endl;

				}
			}
		cout<<"Case #"<<i1+1<<": "<<res<<endl;
	}

	return 0;

}