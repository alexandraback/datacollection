#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
const int MN = 500;
int K,N;
int needk[MN];
vector<int> hask[MN];
int counts[MN];
bool hashad[MN];
int M = 0;
int rem[MN];
bool done[MN];
bool hasself[MN];
vector<int> kes[MN];
vector<int> rkes[MN];

vector<int> dstack;
bool ddone[MN];
void dfs(int n) {
	ddone[n] = 1;
	for(int t : kes[n]) {
		if (!ddone[t]) dfs(t);
	}
	dstack.push_back(n);
}
int comp[MN];
int csize[MN];
int C;
void dfs2(int n, int c) {
	ddone[n] = 1;
	comp[n] = c;
	++csize[c];
	for(int t : rkes[n]) {
		if (!ddone[t]) dfs2(t, c);
	}
}
void scc() {
//	cout<<"scc\n";
	memset(ddone,0,sizeof(ddone));
	dstack.clear();
	for(int i=0; i<M; ++i) if (!ddone[i]) dfs(i);
	memset(ddone,0,sizeof(ddone));
	C=0;
	while(!dstack.empty()) {
		int x = dstack.back();
		dstack.pop_back();
		if (ddone[x]) continue;
		csize[C] = 0;
		dfs2(x, C++);
	}
}

int producer[MN][MN];
bool cdfs(int k, int dest) {
//	cout<<"cdfs "<<k<<' '<<dest<<'\n';
	ddone[k] = 1;
	for(int t : kes[k]) {
		if (t==dest || (!ddone[t] && cdfs(t, dest))) {
			int p = producer[k][t];
			assert(!done[p]);
			done[p] = 1;
			--counts[needk[p]];
			for(auto i : hask[p]) {
				hashad[i] = 1;
				++counts[i];
			}
			return 1;
		}
	}
	return 0;
}

bool possible() {
//	cout<<"possible start\n";
	for(int i=0; i<M; ++i) hashad[i] = counts[i]>0;
	while(1) {
#if 0
		cout<<"possible loop\n";
		cout<<"keys: ";for(int i=0; i<M; ++i) cout<<counts[i]<<' ';cout<<'\n';
		cout<<"have: ";for(int i=0; i<N; ++i) cout<<done[i]<<' ';cout<<'\n';
#endif

		bool added = 0;
		memset(rem,0,4*M);
		for(int i=0; i<N; ++i) if (!done[i]) ++rem[needk[i]];

		for(int i=0; i<N; ++i) if (!done[i]) {
			int k = needk[i];
//			cout<<"testing "<<k<<' '<<rem[k]<<' '<<counts[k]<<'\n';
			if (rem[k]<=counts[k] || (counts[k] && hasself[i])) {
//				cout<<"ok\n";
				done[i] = 1;
				--counts[k];
				--rem[k];
				for(int j : hask[i]) {
					hashad[j] = 1;
					++counts[j];
				}
				added = 1;
			}
		}
		if (added) continue;

		for(int i=0; i<M; ++i) kes[i].clear(), rkes[i].clear();
		for(int i=0; i<N; ++i) if (!done[i]) {
			int n = needk[i];
			for(int j : hask[i]) {
				kes[n].push_back(j);
				producer[n][j] = i;
			}
		}
		for(int i=0; i<M; ++i) {
			sort(kes[i].begin(),kes[i].end());
			kes[i].erase(unique(kes[i].begin(),kes[i].end()), kes[i].end());
		}
		for(int i=0; i<M; ++i)
			for(int j : kes[i])
				rkes[j].push_back(i);

		scc();
//		cout<<"components: "<<C<<'\n';
		memset(ddone,0,sizeof(ddone));
		for(int i=0; i<M; ++i) {
//			if (done[i]) continue;
//			cout<<"trying key "<<i<<" : "<<counts[i]<<' '<<hashad[i]<<' '<<comp[i]<<'\n';
			if (!counts[i] && !hashad[i]) continue;
			int c = comp[i];
			if (csize[c]==1) continue;
//			cout<<"travelling cycle of key "<<i<<' '<<csize[c]<<'\n';
			csize[c] = 1;

			bool res = cdfs(i, i);
			assert(res);
			added = 1;
		}

		if (!added) break;
	}
	bool all = 1;
	for(int i=0; i<N; ++i) all &= done[i];
	return all;
}

bool tdone[MN];
int tcounts[MN];

void take(int i) {
//	cout<<"taking "<<i<<' '<<hask[i].size()<<'\n';
	int idx = needk[i];
	assert(counts[idx]);
	--counts[idx];
	done[i] = 1;
	for(int j : hask[i]) {
		++counts[j];
//		cout<<" key "<<j<<'\n';
	}
}

int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		cin>>K>>N;
		M=0;
		memset(counts,0,sizeof(counts));
		for(int i=0; i<K; ++i) {
			int x;
			cin>>x;
			++counts[x];
			M = max(M, x);
//			cout<<"start key "<<x<<' '<<counts[x]<<'\n';
		}
		for(int i=0; i<N; ++i) {
			int c;
			cin>>needk[i]>>c;
//			cout<<"keycount "<<i<<' '<<c<<" ; "<<needk[i]<<'\n';
			hask[i].resize(c);
			hasself[i] = 0;
			for(int j=0; j<c; ++j) {
				int x;cin>>x;
				hask[i][j]=x;
				M = max(M, x);
				hasself[i] |= x == needk[i];
//				cout<<"hask "<<i<<' '<<j<<" : "<<hask[i][j]<<'\n';
			}
		}
		++M;


		memset(done,0,sizeof(done));
		vector<int> res;
		while((int)res.size()<N) {
			for(int i=0; i<N; ++i) {
				if (done[i] || !counts[needk[i]]) continue;

				memcpy(tdone,done,sizeof(done));
				memcpy(tcounts,counts,sizeof(counts));
				take(i);

				bool ok = possible();

				memcpy(done,tdone,sizeof(done));
				memcpy(counts,tcounts,sizeof(counts));

				if (ok) {
//					cout<<"ok, really take "<<i<<'\n';
					take(i);
					res.push_back(i);
					goto next;
				}
			}
			break;
next:;
		}
		cout<<"Case #"<<a<<":";
		if ((int)res.size()<N) cout<<" IMPOSSIBLE\n";
		else {
			for(int i=0; i<N; ++i) cout<<' '<<1+res[i];
			cout<<'\n';
		}
	}
}
