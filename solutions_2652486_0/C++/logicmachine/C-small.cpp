#include <iostream>
#include <vector>
#include <set>

using namespace std;

int check(const vector<int> &a, const vector<int> &received){
	int N = a.size();
	set<int> possible;
	for(int i = 0; i < (1 << N); ++i){
		int prod = 1;
		for(int j = 0; j < N; ++j){
			if(i & (1 << j)){ prod *= a[j]; }
		}
		possible.insert(prod);
	}
	bool accept = true;
	for(int i = 0; accept && i < received.size(); ++i){
		if(possible.find(received[i]) == possible.end()){ accept = false; }
	}
	if(accept){
		for(int i = 0; i < N; ++i){ cout << a[i]; }
		cout << endl;
	}
	return accept ? 1 : 0;
}

int recur(int i, int N, int M, vector<int> &a, const vector<int> &received){
	if(i == N){ return check(a, received); }
	int lower = 2, sum = 0;
	for(int j = lower; sum == 0 && j <= M; ++j){
		a.push_back(j);
		sum += recur(i + 1, N, M, a, received);
		a.pop_back();
	}
	return sum;
}

int main(){
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		cout << "Case #" << caseNum << ":" << endl;
		int R, N, M, K;
		cin >> R >> N >> M >> K;
		for(int i = 0; i < R; ++i){
			vector<int> received(K), work;
			for(int j = 0; j < K; ++j){ cin >> received[j]; }
			if(recur(0, N, M, work, received) == 0){
				cout << string(N, '2') << endl;
			}
		}
	}
	return 0;
}

