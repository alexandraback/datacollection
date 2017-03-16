#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

struct Level{
	int id;
	int rating;
	int starsNeeded;
	int otherStarsNeeded;

	bool operator <(const Level& other) const{
		return starsNeeded > other.starsNeeded; //descending order
	}
};

bool compOnes(Level one, Level two){
	return one.otherStarsNeeded > two.otherStarsNeeded; //descending order
}

int main(){
	int T;
	scanf("%d\n", &T);
	for(int q = 1; q <= T; q++){
		int n;
		cin >> n;
		vector<Level> levs;
		for(int i = 0; i < n; i++){
			int one, two;
			cin >> one >> two;
			Level l1 = {i, 1, one, two};
			Level l2 = {i, 2, two, one};
			levs.push_back(l1);
			levs.push_back(l2);
		}
		sort(levs.begin(), levs.end());
		multiset<int> ids;
		vector<Level> lev_one, lev_two;
		int curLevel = 0;
		int turns = 0;
		while(true){
			while(!levs.empty()){
				Level l = levs[levs.size() - 1];
				if(l.starsNeeded <= curLevel){
					//printf("%d %d %d %d\n", curLevel, l.id, l.rating, l.starsNeeded);
					if(l.rating == 1)
						lev_one.push_back(l);
					else
						lev_two.push_back(l);
					levs.pop_back();
				} else break;
			}
			if(!lev_two.empty()){
				bool foundTwo = false;
				for(int i = 0; i < lev_two.size(); i++){
					if(ids.count(lev_two[i].id) == 0){
						foundTwo = true;
						curLevel += 2;
						ids.insert(lev_two[i].id);
						ids.insert(lev_two[i].id);
						//cout << "0->2: " << lev_two[i].id << endl;
						lev_two.erase(lev_two.begin() + i);
						break;
					}
				}
				if(!foundTwo){
					curLevel += 1;
					ids.insert(lev_two[0].id);
					//cout << "1->2: " << lev_two[0].id << endl;
					lev_two.erase(lev_two.begin());
				}
			} else if (!lev_one.empty()){
				sort(lev_one.begin(), lev_one.end(), compOnes);
				bool found = false;
				for(int i = 0; i < lev_one.size(); i++){
					if(ids.count(lev_one[i].id) == 0){
						curLevel += 1;
						ids.insert(lev_one[i].id);
						found = true;
						//cout << "0->1: " << lev_one[i].id << endl;
						lev_one.erase(lev_one.begin()+i);
						break;
					}
				} 
				if(!found) break;
			} else break;
			turns++;
			if(curLevel == 2 * n) break;
		}
		if(curLevel == 2 * n)
			printf("Case #%d: %d\n", q, turns);
		else
			printf("Case #%d: Too Bad\n", q);
	}
}
