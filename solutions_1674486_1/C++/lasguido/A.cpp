#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> ar[1001];
set<int> par_mem[1001];
bool par_mem_flag[1001];

set<int> searchParents(int vic){
	if (par_mem_flag[vic]){
		return par_mem[vic];
	}
	set<int> acc;
	set<int>::iterator ite;
	int sz = ar[vic].size();
	if (sz > 0){
		for (int i = 0 ; i <sz ; i ++){
			set<int> tmp = searchParents(ar[vic][i]);
			for (ite = tmp.begin() ; ite!=tmp.end() ; ite++){
				acc.insert(*ite);
			}
		}
	}else{
		acc.insert(vic);
	}
	par_mem[vic] = acc;
	par_mem_flag[vic] = true;
	return acc;
}

bool compare(set<int> a, set<int> b){
	set<int>::iterator ite;

	for (ite = b.begin() ; ite!=b.end() ; ite++){
		if (a.count(*ite)){
			return true;
		}
	}

	return false;
}

int main(){
	int t;
	cin >>t;

	for (int k = 1 ; k <= t ; k++){
		int n, sz, in;
		cin >>n;
		for (int i = 1 ; i <= n ; i++){
			par_mem_flag[i] = false;
			cin >>sz;
			vector<int> tmp;
			for (int j = 0 ; j < sz ; j ++){
				cin >>in;
				tmp.push_back(in);
			}
			ar[i] = tmp;
		}

		bool answ = false;

		for (int i = 1 ; i <= n && !answ ; i ++){
			sz = ar[i].size();
			if (sz > 1){
				for (int x = 0 ; x < sz && !answ; x++){
					for (int y = x+1 ; y < sz && !answ; y++){
						answ = compare(searchParents(ar[i][x]), searchParents(ar[i][y]));
					}
				}
			}
		}

		if (!answ){
			cout <<"Case #" <<k <<": No" <<endl;
		}else{
			cout <<"Case #" <<k <<": Yes" <<endl;
		}
	}

	return 0;
}