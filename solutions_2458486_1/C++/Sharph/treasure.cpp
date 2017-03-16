#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>
#include <cassert>

int main() {
	int T;
	std::cin >> T;
	
	for(int t = 0; t < T; ++t) {
		int K, N;
		std::cin >> K >> N;
		
		int keys[200] = {0};
		int opening_key[200];
		std::vector<int> keys_inside[200];
		bool opened[200] = {0};
		
		for(int i = 0; i < K; ++i) {
			int key;
			std::cin >> key;
			--key;
			++keys[key];
		}
		
		for(int i = 0; i < N; ++i) {
			int o, k;
			std::cin >> o >> k;
			--o;
			opening_key[i] = o;
			for(int j = 0; j < k; ++j) {
				int x;
				std::cin >> x;
				--x;
				keys_inside[i].push_back(x);
			}
		}
		
		auto ok = [&]() -> bool {
			int dkeys[200];
			memcpy(dkeys, keys, sizeof(int) * 200);
			
			for(int i = 0; i < N; ++i) {
				if(opened[i]) continue;
				
				--dkeys[opening_key[i]];
				for(int key : keys_inside[i]) {
					++dkeys[key];
				}
			}
			
			for(int i = 0; i < 200; ++i) {
				if(dkeys[i] < 0) return false;
			}
			
			bool found[200] = {0};
			std::queue<int> q;
			for(int i = 0; i < 200; ++i) {
				if(keys[i] > 0) {
					found[i] = true;
					q.push(i);
				}
			}
			while(!q.empty()) {
				int key = q.front();
				q.pop();
				
				for(int i = 0; i < N; ++i) {
					if(opened[i] || opening_key[i] != key) continue;
					for(int key2 : keys_inside[i]) {
						if(!found[key2]) {
							found[key2] = true;
							q.push(key2);
						}
					}
				}
			}
			
			for(int i = 0; i < N; ++i) {
				if(opened[i]) continue;
				
				if(!found[opening_key[i]]) return false;
			}
			
			return true;
		};
		
		std::cout << "Case #" << t + 1 << ":";
		if(!ok()) {
			std::cout << " IMPOSSIBLE";
		} else {
			for(int x = 0; x < N; ++x) {
				bool found = false;
				for(int i = 0; i < N; ++i) {
					if(opened[i]) continue;
					if(keys[opening_key[i]] == 0) continue;
					
					--keys[opening_key[i]];
					for(int key : keys_inside[i]) {
						++keys[key];
					}
					opened[i] = true;
					
					if(ok()) {
						found = true;
						std::cout << " " << i + 1;
						break;
					}
					
					++keys[opening_key[i]];
					for(int key : keys_inside[i]) {
						--keys[key];
					}
					opened[i] = false;
				}
				assert(found);
			}
		}
		std::cout << "\n";
	}
	
	return 0;
}
