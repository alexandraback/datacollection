#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int bff[1010];
bool seen[1010];

int main(){
	int TC, c = 1;
	scanf("%d",&TC);
	while (TC--){
		memset(bff,0,sizeof bff);
		memset(seen,0,sizeof seen);
		int N, id;
		scanf("%d",&N);
		for (int i = 1; i <= N; i++){
			scanf("%d ",&id);
			bff[i] = id;
		}
		int longest_chain = 0;
		for (int i = 1; i <= N; i++){
			set<int> in_chain;
			int current_chain = 1;
			int current_id = i;
			int next_id = bff[i];
			while (!seen[next_id]){
				in_chain.insert(current_id);
				seen[current_id] = true;
				current_id = bff[current_id];
				next_id = bff[current_id];
				current_chain++;
			}
			bool searching = true;
			while (searching){
				bool found = false;
				for (int j = 0; j < N; j++){
					if (current_id == bff[j]){
						if (in_chain.count(j) == 0){
							in_chain.insert(j);
							current_chain++;
							found = true;
							break;
						}
					}
				}
				if (!found)
					searching = false;
				
			}
			
			if (current_chain > longest_chain)
				longest_chain = current_chain;
		}
		printf("Case #%d: %d\n",c++,longest_chain);
	}	
}
