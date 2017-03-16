
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int square[64][64];
bool set_row[64], set_col[64], used[128];
vector<vector<int> > lists;


int N;

bool match_row(int row_id, int list_id){
	FOR(i,0,N)if(set_col[i]){
		if(lists[list_id][i] != square[row_id][i])return false;
	}
	return true;
}
bool match_col(int col_id, int list_id){
	FOR(i,0,N)if(set_row[i]){
		if(lists[list_id][i] != square[i][col_id])return false;
	}
	return true;
}
void set_r(int row_id, int list_id){
	set_row[row_id] = true;
	used[list_id] = true;
	FOR(i,0,N)square[row_id][i] = lists[list_id][i];
}
void set_c(int col_id, int list_id){
	set_col[col_id] = true;
	used[list_id] = true;
	FOR(i,0,N)square[i][col_id] = lists[list_id][i];
}
void unset_r(int row_id, int list_id){
	set_row[row_id] = false;
	used[list_id] = false;
}
void unset_c(int col_id, int list_id){
	set_col[col_id] = false;
	used[list_id] = false;
}
bool rek(){
	int todo = 0;
	int unmatched = 0;
	FOR(i,0,N)if(!set_row[i]){
		++todo;
		int matches = 0;
		FOR(j,0,sz(lists))if(!used[j]){
			if(match_row(i,j)){
				matches++;
			}
		}
		if(matches == 0)unmatched++;
	}
	FOR(i,0,N)if(!set_col[i]){
		++todo;
		int matches = 0;
		FOR(j,0,sz(lists))if(!used[j]){
			if(match_col(i,j)){
				matches++;
			}
		}
		if(matches == 0)unmatched++;
	}
	if(unmatched > 1)return false;
	if(todo == 1){
		FOR(i,0,N)FOR(j,0,N-1)if(square[i][j] >= square[i][j+1])return false;
		FOR(i,0,N)FOR(j,0,N-1)if(square[j][i] >= square[j+1][i])return false;
		return true;
	}
	FOR(j,0,sz(lists))if(!used[j]){
		int matches = 0;
		int id1 = -1, id2 = -1;
		FOR(i,0,N)if(!set_row[i]){
			if(match_row(i,j)){
				matches++;
				assert(id1 == -1);
				id1 = i * 2;
				swap(id1,id2);
			}
		}
		FOR(i,0,N)if(!set_col[i]){
			if(match_col(i,j)){
				matches++;
				assert(id1 == -1);
				id1 = i * 2 + 1;
				swap(id1,id2);
			}
		}
		if(matches == 0)return false;
		if(matches == 1 || (matches == 2 && j + 1 < sz(lists) && lists[j+1] == lists[j])){
			if(id2&1){
				set_c(id2>>1,j);
				if(rek())return true;
				unset_c(id2>>1,j);
				return false;
			} else {
				set_r(id2>>1,j);
				if(rek())return true;
				unset_r(id2>>1,j);
				return false;
			}
		}
	}
	FOR(j,0,sz(lists))if(!used[j]){
		int matches = 0;
		int id1 = -1, id2 = -1;
		FOR(i,0,N)if(!set_row[i]){
			if(match_row(i,j)){
				matches++;
				assert(id1 == -1);
				id1 = i * 2;
				swap(id1,id2);
			}
		}
		FOR(i,0,N)if(!set_col[i]){
			if(match_col(i,j)){
				matches++;
				assert(id1 == -1);
				id1 = i * 2 + 1;
				swap(id1,id2);
			}
		}
		if(id2&1){
			set_c(id2>>1,j);
			if(rek())return true;
			unset_c(id2>>1,j);
		} else {
			set_r(id2>>1,j);
			if(rek())return true;
			unset_r(id2>>1,j);
		}
		if(id1&1){
			set_c(id1>>1,j);
			if(rek())return true;
			unset_c(id1>>1,j);
		} else {
			set_r(id1>>1,j);
			if(rek())return true;
			unset_r(id1>>1,j);
		}
		return false;
	}
	return false;
}
void calc(){
	cin >> N;
	lists = vector<vector<int> >(2*N-1,vector<int>(N));
	FOR(i,0,sz(lists))FOR(j,0,N)cin >> lists[i][j];
	sort(all(lists));
	FOR(i,0,N)FOR(j,0,N)square[i][j] = -1;
	FOR(i,0,N)set_row[i] = false;
	FOR(i,0,N)set_col[i] = false;
	FOR(i,0,N*2)used[i] = false;
	if(lists[0][0] == lists[1][0]){
		FOR(i,0,N)square[0][i] = lists[0][i];
		FOR(i,0,N)square[i][0] = lists[1][i];
		set_row[0] = true;
		set_col[0] = true;
		used[0] = true;
		used[1] = true;
	} else {
		int largest = 0;
		int id1 = -1, id2 = -1;
		FOR(i,0,sz(lists)){
			if(lists[i][N-1] > largest){
				largest = lists[i][N-1];
				id1 = i;
				id2 = -1;
			} else if(lists[i][N-1] == largest) {
				assert(id2 == -1);
				id2 = i;
			}
		}
		FOR(i,0,N)square[N-1][i] = lists[id1][i];
		FOR(i,0,N)square[i][N-1] = lists[id2][i];
		set_row[N-1] = true;
		set_col[N-1] = true;
		used[id1] = true;
		used[id2] = true;
	}
	assert(rek());
	FOR(i,0,N){
		if(!set_row[i]){
			FOR(j,0,N)cout << " " << square[i][j];
			cout << endl;
		}
		if(!set_col[i]){
			FOR(j,0,N)cout << " " << square[j][i];
			cout << endl;
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1){
		cout << "Case #" << tc << ":";
		calc();
	}
	return 0;
}
