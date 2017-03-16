#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

static int R, N, M, K;
static vector<map<int,int>> dp;
static vector<vector<int>> nums;

static void generate(int i, vector<int> &vec, map<int,int> &mm, int curVal){
	if(i==(int)vec.size()){
		mm[curVal]++;
		return;
	}

	generate(i+1, vec, mm, curVal);
	generate(i+1, vec, mm, curVal*vec[i]);
}

static void choose(int curn, vector<int> &vec, int startFrom){
	if(curn==0){
		map<int, int> mm;
		generate(0, vec, mm, 1);
		dp.push_back(mm);
		nums.push_back(vec);
		return;
	}

	for(int i=startFrom; i<=M; ++i){
		vec.push_back(i);
		choose(curn-1, vec, i);
		vec.pop_back();
	}
}

static void doComp(){
	cin >> R >> N >> M >> K;
	dp.clear();
	nums.clear();
	vector<int> tmp;
	choose(N, tmp, 2);

	tmp.resize(K);
	for(int i=0; i<R; ++i){
		for(int j=0; j<K; ++j){
			cin >> tmp[j];
		}
		for(size_t j=0; j<dp.size(); ++j){
			bool ok = true;
			for(int k=0; k<K; ++k){
				if(!dp[j].count(tmp[k])){
					ok = false;
					break;
				}
			}
			if(ok){
				for(int k=0; k<N; ++k){
					cout << nums[j][k];
				}
				cout << endl;
				break;
			}
		}
	}
}

int main(){
	int C;
	cin >> C;
	for(int c=1; c<=C; ++c){
		cout << "Case #" << c << ":" << endl;
		doComp();
	}
	return 0;
}
