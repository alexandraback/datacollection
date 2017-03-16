#include <cstdio>
#include <iostream>
using namespace std;

const int TYPES = 201;
const int CHESTS = 20;

struct Chest {
	short type, kcnt[TYPES];
	bool opened;
};

short chests, kcnt[TYPES], ccnt[TYPES], order[CHESTS]; Chest chest[CHESTS];

inline bool check_sum(const int & loc){
	short kleft[TYPES], sum = 0;
	for (int x = 1; x < TYPES; ++x)
		kleft[x] = kcnt[x];
	for (int x = 0; x < chests; ++x){
		if (chest[x].opened) continue;
		for (int y = 1; y < TYPES; ++y)
			kleft[y] += chest[x].kcnt[y];
	}
	for (int x = 1; x < TYPES; ++x)
		sum += (ccnt[x] < kleft[x] ? ccnt[x] : kleft[x]);
	return (sum >= chests-loc);
}

inline void open_chest(const int & c, const int & loc){
	--kcnt[chest[c].type];
	for (int x = 1; x < TYPES; ++x)
		kcnt[x] += chest[c].kcnt[x];
	chest[c].opened = true;
	--ccnt[chest[c].type];
	order[loc] = c+1;
}

inline void close_chest(const int & c){
	++ccnt[chest[c].type];
	chest[c].opened = false;
	for (int x = 1; x < TYPES; ++x)
		kcnt[x] -= chest[c].kcnt[x];
	++kcnt[chest[c].type];
}

bool is_poss(int loc){
	if (loc == chests) return true;
	if (!check_sum(loc)) return false;
	for (int x = 0; x < chests; ++x){
		if (chest[x].opened) continue;
		if (kcnt[chest[x].type] == 0) continue;

		if (chest[x].kcnt[chest[x].type] > 0){
			open_chest(x, loc);
			if (is_poss(loc+1)) return true;
			close_chest(x);
			return false;
		}
		if (ccnt[chest[x].type] <= kcnt[chest[x].type]){
			open_chest(x, loc);
			if (is_poss(loc+1)) return true;
			close_chest(x);
			return false;
		}

		open_chest(x, loc);
		if (is_poss(loc+1)) return true;
		close_chest(x);
	}
	return false;
}

int main(){
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	int run, keys, type;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		for (int x = 0; x < TYPES; ++x) kcnt[x] = ccnt[x] = 0;
		cin >> keys >> chests;
		for (int x = 0; x < keys; ++x){
			cin >> type;
			++kcnt[type];
		}
		for (int x = 0; x < chests; ++x){
			for (int y = 0; y < TYPES; ++y) chest[x].kcnt[y] = 0;
			cin >> chest[x].type >> keys;
			++ccnt[chest[x].type];
			for (int y = 0; y < keys; ++y){
				cin >> type;
				++chest[x].kcnt[type];
			}
			chest[x].opened = false;
		}
		cout << "Case #" << a << ":";
		if (!is_poss(0)) cout << " IMPOSSIBLE" << endl;
		else {
			for (int x = 0; x < chests; ++x) cout << " " << order[x];
			cout << endl;
		}
	}
	return 0;
}
