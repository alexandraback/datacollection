#include <cstdio>
#include <set>
using namespace std;
int tmp_num[10];
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		int counter=0;
		for(int j = a; j <= b; ++j){
			int index=0;
			int tmp=j;
			while(tmp>0){
				tmp_num[index]=tmp%10;
				tmp/=10;
				++index;
			}
			set<int> done;
			for(int k = 1; k < index; ++k){
				if(tmp_num[index-1-k]==0)
					continue;
				if(tmp_num[index-1-k]<tmp_num[index-1])
					continue;
				int num=0;
				for(int l = 0; l < index; ++l){
					num*=10;
					num += tmp_num[(index-1-k-l+index)%index];
				}
				if(num<=j||num>b)
					continue;
				done.insert(num);
			}
			counter += done.size();
		}
		printf("Case #%d: %d\n", i+1, counter);
	}
	return 0;
}
