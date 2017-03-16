#include <iostream>
#include <vector>

int main(){
	int cases;
	std::cin >> cases;

	for(int i=0; i<cases; i++){
		int kids;
		std::cin >> kids;
		std::vector<int> bff;
		std::vector<int> friendCount;
		std::vector<int> supports;
		std::vector<bool> checked;
		for(int j=0; j<kids; j++){
			friendCount.push_back(0);
			supports.push_back(0);
			checked.push_back(false);
		}
		for(int j=0; j<kids; j++){
			int x;
			std::cin >> x;
			bff.push_back(x-1);
			friendCount[x-1] = friendCount[x-1]+1;
		}

		std::vector<int> toRemove;

		for(int j=0; j<kids; j++){
			if(friendCount[j]==0){
				toRemove.push_back(j);
			}
		}

		while(!toRemove.empty()){
			int x = toRemove.back();
			toRemove.pop_back();

			checked[x]=true;
			friendCount[bff[x]]-=1;
			if(supports[x]+1 > supports[bff[x]]){
				supports[bff[x]]=supports[x]+1;
			}

			if(friendCount[bff[x]]==0){
				toRemove.push_back(bff[x]);
			}
		}

		int max=0;
		int couples=0;

		for(int j=0; j<kids; j++){
			if(checked[j]){
				continue;
			}
			int count=0;
			int current=j;
			while(!checked[current]){
				count++;
				checked[current]=true;
				current=bff[current];
			}

			if(count==2){
				couples+=supports[j]+supports[bff[j]]+2;
			}
			if(count>max){
				max=count;
			}
		}

		if(couples>max){
			max=couples;
		}

		std::cout << "Case #" << i+1 << ": " << max << std::endl;
	}
	return 0;
}
		

