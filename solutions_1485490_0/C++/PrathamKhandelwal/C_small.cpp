#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

class Data
{
public:
	int type;
	long long count;
};

vector<Data> vn,vm;
long long solve(int a,int b)
{
	if(a == vn.size()) return 0;
	
	int i,j;
	long long k,ret;
	
	ret = k = 0;
	for(i=b;i<vm.size();i++){
		ret = max(ret, min(k,vn[a].count) + solve(a+1,i));
		if(vn[a].type == vm[i].type)
			k += vm[i].count;
	}
	ret = max(ret, min(k,vn[a].count));
	return ret;
}

int main(){
	int T,N,M;
	int i,j,k;
	long long x,y,z;
	Data D;
	
	j = 1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		
		vn.clear();
		vm.clear();
		for(i=0;i<N;i++){
			scanf("%lld%d",&z,&k);
			
			if(i == 0){
				D.count = z;
				D.type = k;
				continue;
			}
			
			if(k == D.type)
				D.count += z;
			else{
				vn.push_back(D);
				D.count = z;
				D.type = k;
			}
		}
		vn.push_back(D);

		for(i=0;i<M;i++){
			scanf("%lld%d",&z,&k);
			
			if(i == 0){
				D.count = z;
				D.type = k;
				continue;
			}
			
			if(k == D.type)
				D.count += z;
			else{
				vm.push_back(D);
				D.count = z;
				D.type = k;
			}
		}
		vm.push_back(D);
		
		long long ans = solve(0,0);
		if(vn.size() == 3 && vn[0].type == vn[2].type){
			for(i=0,z=0;i<vm.size();i++)
				if(vm[i].type == vn[0].type)
					z += vm[i].count;
			
			ans = max(ans, min(vn[0].count + vn[2].count, z));
		}
		printf("Case #%d: %lld\n",j,ans);
		j++;
	}
	return 0;
}
