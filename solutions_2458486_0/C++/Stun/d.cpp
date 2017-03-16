#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#ifndef MAXKEY
#define MAXKEY 202
#endif

#ifndef MAXCH
#define MAXCH 202
#endif

int skip[MAXCH];
bool in[MAXCH];
std::vector<int> CH[MAXCH];
int T[MAXCH];
std::vector<int> R;
int keys[MAXKEY];
int remain[MAXKEY];
int K, N;
int cur;
bool BB[1050000];
void pick(int i, int L){
	R[L] = i;
	// skip[T[i]] = 0;
		
	in[i] = true;
	keys[T[i]]--;
	// remain[T[i]]--;
	for(int k = 0; k < CH[i].size(); k++) keys[CH[i][k]]++;
	
	cur |= (1<<i);
	BB[cur]=true;
}
void unpick(int i){
	for(int k = 0; k < CH[i].size(); k++) keys[CH[i][k]]--;			
	// remain[T[i]]++;	
	keys[T[i]]++;	
	in[i] = false;

	// skip[T[i]] = i+1;
	// skip[i] = remain[T[i]] - keys[T[i]];

	assert(cur & (1<<i));
	cur ^= (1<<i);	
}

bool sol(int L){
	// if (L > 0){
	// cout << R[0] + 1;
	// for(size_t i = 1; i < L; ++i) {
	// 	cout << " " << R[i] + 1;
	// }
	// cout << endl;
	
	for (int i = 0 ; i < N ; i++){
		// if (!in[i] && remain[T[i]] <= keys[T[i]]){
		// 	pick(i,L);
		// 	if (L == N-1) return true;
		// 	else if (sol(L+1)) return true;
		// 	unpick(i);
		// 	break;
		// }
		if (!in[i] && keys[T[i]] > 0 /* && skip[i] < (remain[T[i]]-keys[T[i]]) ){ */ && !BB[cur | (1<<i)]){
			pick(i,L);
			if (L == N-1) return true;
			else if (sol(L+1)) return true;
			unpick(i);
		}
	}
	return false;
}

int main(){
	int tcase;
	cin >> tcase;
	int k;	
	
	for(size_t casen = 0; casen < tcase; ++casen) { 
		cin >> K >> N;
		R.clear();
		R.resize(N);
		memset(skip, 0, sizeof(int)*MAXCH);
		memset(in, 0, sizeof(bool)*MAXCH);		
		memset(remain, 0, sizeof(int)*MAXCH);
		memset(keys, 0, sizeof(int)*MAXCH);
		
		memset(BB, 0,sizeof(bool) * 1048576);
		cur = 0;
		for(size_t i = 0; i < K; ++i) {
			cin >> k;
			keys[k]++;
		}
		
		for(size_t i = 0; i < N; ++i) {
			R[i] = -1;
			cin >> T[i];
			remain[T[i]]++;
			cin >> k;
			CH[i].resize(k);
			for(size_t j = 0; j < k; ++j) {
				cin >> CH[i][j];
			}
		}
		
		cout << "Case #" << casen + 1 << ": ";
		if (!sol(0)){
			cout << "IMPOSSIBLE" << endl;
		}else{
			cout << R[0] + 1;
			for(size_t i = 1; i < N; ++i) {
				cout << " " << R[i] + 1;
			}
			cout << endl;
		}
	}
	

	return 0;
}
