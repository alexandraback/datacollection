#define uint somethingnotnameduint
#include <iostream>
#include <cstdint>
#undef uint

using namespace std;

using uint = uint64_t;

uint ipow(uint b,uint e){
	uint r=1;
	while(e-->0)r*=b;
	return r;
}

int main(){
	int T,tt;
	cin>>T;
	for(tt=1;tt<=T;tt++){
		cout<<"Case #"<<tt<<":";
		uint K,C,S;
		cin>>K>>C>>S;
		if(S<1||(K>=C&&S<K-C+1)){
			cout<<" IMPOSSIBLE"<<endl;
			continue;
		}
		if(K==1){
			cout<<" 1"<<endl;
			continue;
		}
		if(C==1){
			for(uint i=1;i<=K;i++)cout<<' '<<i;
			cout<<endl;
			continue;
		}
		const uint baseblocksz=ipow(K,C-1);
		uint blocksz=baseblocksz;
		uint left=0;
		for(uint i=0;i<K;i++){
			if(blocksz>1){
				left+=i*blocksz;
				blocksz/=K;
			} else {
				cout<<' '<<left+i+1;
				left=0;
				blocksz=baseblocksz;
			}
		}
		cout<<' '<<left+1<<endl;
	}
}
