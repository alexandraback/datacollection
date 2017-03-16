#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int N,M,K;
int main(){
	freopen("I:\\gcj\\C-small-attempt1.in","r",stdin);
	freopen("I:\\gcj\\C-small-attempt1.out","w",stdout);
	int T;
	cin>>T;
	int res;
	for(int cs=1;cs<=T;++cs){
		cin>>N>>M>>K;

	//	cout<<N<<' '<<M<<' '<<K<<endl;
		if(N>M)
			swap(N,M);
		if(N==1){
			res=K;
		}else if(N==2){
			res=K;
		}else{
			if(K<=N*N-4){
				if(K<4){
					res=K;
				}else
					for(int i=3;i<=N;++i){
						if(K<=i*i-4){
							res=(i-2)*4;
							if(K<=i*i-4-i)
								res-=2;
							break;
						}
					}
			}else if(K<=N*M-4){
				for(int i=3;i<=M;++i){
					if(K<=N*i-4){
						res=(N-2)*2+(i-2)*2;
						break;
					}
				}
			}else
				res=2*(N-2+M-2)+K-(N*M-4);
		}


		cout<<"Case #"<<cs<<": "<<res<<endl;
	}
	return 0;
}
