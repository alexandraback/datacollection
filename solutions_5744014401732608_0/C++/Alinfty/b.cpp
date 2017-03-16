#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		int B;
		long long int M;
		int map[50][50]={0,};
		cin>>B>>M;
		cout<<"Case #"<<t<<": ";
		if((1LL<<(B-2))<M){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		else cout<<"POSSIBLE"<<endl;
		int i=0;
		for(i=0;i<=B-1;i++){
			if((1LL<<i)>M) break;
		}
		i--;
		M-=(1LL<<i);
		int j;
		for(j=B-i-2;j<B;j++){
			for(int k=0;k<B;k++){
				if(j<k) map[j][k]=1;
				else map[j][k]=0;
			}
		}
		for(j=0;j<B-i-2;j++){
			for(int k=0;k<B;k++){
				if(j+1==k) map[j][k]=1;
				else map[j][k]=0;
			}
		}
		j=B-i-2;
		for(int k=0;k<i;k++){
			if(M>=(1LL<<(i-1-k))){
				M-=(1LL<<(i-1-k));
				map[0][j+k+1]=1;
			}
		}
		for(int x=0;x<B;x++){
			for(int y=0;y<B;y++){
				cout<<map[x][y];
			}
			cout<<endl;
		}
	}
	return 0;
}
