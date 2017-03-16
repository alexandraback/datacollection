#include"stdio.h"
#include"vector"
#include"set"
#include"map"
#include"algorithm"
#define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it!=(v).end(); it++)
using namespace std;
set<vector<char> > v;
map<vector<char>,set<int> > prods;
int K;
vector<int> process(vector<char>& v, int i, int idx) {
	vector<int> v2;
	if(v.size() == idx)
	{
		v2.push_back(i);
		return v2;
	}
	v2 = process(v, i, idx+1);
	vector<int> v3 = process(v, i*v[idx], idx+1);
	v2.insert(v2.end(),v3.begin(), v3.end());
	return v2;
}
void build(int mx, int num, vector<char> so_far) {
	if(num == 0){
		sort(so_far.begin(), so_far.end());
		v.insert(so_far);
		vector<int> v = process(so_far, 1, 0);
		set<int> s(v.begin(), v.end());
		prods[so_far] = s;
		return;
	}
	for(int i = 2; i<=mx ; i++){
		so_far.push_back(i);
		build(mx, num-1, so_far);
		so_far.pop_back();
	}
}
int main(){
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++) {
		int R, N, M;
		printf("Case #%d:\n", tt);
		scanf("%d%d%d%d", &R, &N, &M, &K);
		v.clear();
		vector<char> sf;
		build(M, N, sf);
		set<int> pr;
		while(R--){
			for(int i=0;i<K;i++){
				int kk;
				scanf("%d", &kk);
				pr.insert(kk);
			}
			int cnt = 1;
			vector<char> pos;
			FOREACH(it, prods) {
				if(includes(it->second.begin(), it->second.end(), pr.begin(), pr.end()) && (rand()%cnt++) == 0)
					pos = it->first;
			}
			FOREACH(x, pos){
				printf("%d", *x);
			}
			printf("\n");
			pr.clear();
		}
	}
}
