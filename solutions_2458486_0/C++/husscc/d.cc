#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory.h>
#include <stack>

using namespace std;
#define REP1(i,n) for((i)=1;(i)<(int)(n);(i)++)
#define REP0(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define RITR(c,itr) for(__typeof((c).begin()) itr=(c).begin();(itr)!=(c).end();(itr)++)

int needs[201], keys[201], chests[201], ret[201], T, N, K;
unordered_map<int, int> got[201];
//int ccc = 0;

bool solve(int openidx, int retidx){
	if(retidx > N) return true;
	int i, j, k, l;
	stack<int> is;

	/*
	printf("---------%d---------\n", ccc++);
	REP1(i, N+1) cout<<ret[i]<<" ";
	cout<<endl;
	REP1(i, N+1) cout<<chests[i]<<" ";
	cout<<endl;
	printf("retidx = %d\n", retidx);
	*/

	for(; openidx <= N; openidx++){
		if(chests[openidx] < 0) continue;
		int toOpen = chests[openidx];
		if(keys[toOpen] > 0 && 
				(got[openidx].count(toOpen) || needs[toOpen] == keys[toOpen])
			){
			needs[toOpen]--; 
			keys[toOpen]--;
			RITR(got[openidx], itr) 
				keys[itr->first] += itr->second;
			chests[openidx] = -chests[openidx];
			ret[retidx] = openidx; 
			retidx++;

			is.push(openidx);
		}
		else break;
	}
	if(openidx > N) 
		return true;
	for(int tryidx = openidx; tryidx <= N; tryidx++){
		if(chests[tryidx] < 0) continue;
		int toOpen = chests[tryidx];
		if(keys[toOpen] > 0){
			int safe = 0;
			if(got[tryidx].count(toOpen) || needs[toOpen] == keys[toOpen])
				safe = 1;
			ret[retidx] = tryidx;
			needs[toOpen]--; 
			keys[toOpen]--;
			chests[tryidx] = -chests[tryidx];
			RITR(got[tryidx], itr) 
				keys[itr->first] += itr->second;
			if(solve(openidx, retidx+1)) return true;
			else{
				chests[tryidx] = -chests[tryidx];
				needs[toOpen]++; keys[toOpen]++;
				RITR(got[tryidx], itr) keys[itr->first] -= itr->second;
				if(safe) break;
			}
		}
	}
	
	while(!is.empty()){
		i = is.top();
		is.pop();
		chests[i] = -chests[i];
		needs[chests[i]]++;
		keys[chests[i]]++;
		RITR(got[i], itr) 
			keys[itr->first] -= itr->second;
	}
	return false;
}

int main(){
	//freopen("./in_", "r", stdin);
	cin>>T; int i, j, k, l;
	REP1(i, T+1){
		unordered_map<int, int> req, al;
		cin>>K>>N;
		memset(needs, 0, sizeof(needs));
		memset(keys, 0, sizeof(keys));
		memset(chests, 0, sizeof(chests));
		memset(ret, 0, sizeof(ret));
		REP0(j, K){
			cin>>l; 
			keys[l]++; 
			al[l]++;
		}
		REP1(j, N+1){
			cin>>l; needs[l]++;
			chests[j] = l;
			req[l]++;
			cin>>K;
			got[j].clear();
			REP0(k, K){
				cin>>l;
				got[j][l]++;
				al[l]++;
			}
		}
		l = 1;
		RITR(req, itr){
			if(!al.count(itr->first) || al[itr->first] < itr->second) l = 0;
			if(!l) break;
		}
		printf("Case #%d: ", i);
		if(!l || !solve(1, 1)) printf("IMPOSSIBLE");
		else{
			REP1(j, N+1) printf("%d ", ret[j]);
		}
		printf("\n");
	}
	return 1;
}