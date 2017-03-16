#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int cases;
	scanf("%d", &cases);
	for(int z=1; z<=cases; z++){
		long long a, n;
		scanf("%lld %lld", &a, &n);
		priority_queue<int, vector<int>, greater<int> > list;
		for(int i=0; i<n; i++){
			int temp;
			scanf("%d", &temp);
			list.push(temp);
		}
		int pos = -1;
		int mov = 0;
		while(true){
			while(list.size() > 0 && list.top() < a){
				a += list.top();
				list.pop();
			}
			int temp = mov+list.size();
			if(pos == -1 || temp < pos){
				pos = temp;
			}
			if(list.size() > 0){
				mov++;
				a += a-1;
				if(a-1 == 0){
					break;
				}
			}else{
				break;
			}
		}
		printf("Case #%d: %d\n", z, pos);
	}

	return 0;
}