#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

#define KMAX 201

class Prefix {
public:
	int mask;

	Prefix() { mask = 0; }
	Prefix(int k) { mask = 1 << k; }
	Prefix(const Prefix& prefix, int k) { mask = prefix.mask | (1 << k); }

	bool operator==(const Prefix& prefix) const { return this->mask == prefix.mask; }
	void show() const {
		int temp = mask, k = 0;
		while (temp > 0) {
			if (temp & 1 == 1) cout << k << "|";
			k++; temp >>= 1;
		}
		cout << endl;
	}
};

struct hash_prefix
{
    size_t operator()(const Prefix& p) const
    {
    	hash<int> H;
    	return H(p.mask);
    }
};

struct equal_prefix
{
	bool operator()(const Prefix& s1, const Prefix& s2) const
  	{
    	return s1.mask == s2.mask;
  	}

};

class Chest {
public:
	int id, lock;
	vector<int> keys;
	bool visited;

	Chest(int id) { this->id = id; visited = false; }
	bool isGoodChest() { return keys[lock] > 0; }

	void givekeys(int* nkeys) {
		for(vector<int>::iterator it = keys.begin(); it != keys.end(); it++)
			nkeys[*it]++;
	}

	void takebackkeys(int* nkeys) {
		for(vector<int>::iterator it = keys.begin(); it != keys.end(); it++)
			nkeys[*it]--;
	}
};

typedef vector<Chest>::iterator ChestIT;

int T, K, N;
vector<Chest> chests;


bool suc;
int keys[KMAX];
vector<ChestIT> opened;
hash_set<Prefix, hash_prefix, equal_prefix> searched;
void dfs(Prefix& prefix) {
	/*
	for (int i = 0; i < opened.size(); i++)
		cout << opened[i]->id << "|";
	cout << endl;
	for (int i = 0; i < KMAX; ++i)
		if (keys[i] > 0) cout << " " << i << ":" << keys[i];
	cout << endl;
	*/

	if (opened.size() == N) {
		suc = true;
		return;
	}

	for (ChestIT it = chests.begin(); it != chests.end(); it++) {
		if (!it->visited && keys[it->lock] > 0) {
			Prefix newprefix = Prefix(prefix, it->id);
			if (searched.find(newprefix) != searched.end()) continue;
			searched.insert(newprefix);

			it->visited = true;
			opened.push_back(it);
			--keys[it->lock];
			it->givekeys(keys);

			dfs(newprefix);
			if (suc) return;
			//else if (it->isGoodChest()) return;

			it->visited = false;
			opened.erase(opened.end() - 1);
			++keys[it->lock];
			it->takebackkeys(keys);
		}
	}
}

int main() {
	int Ki, key;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &K, &N);
		memset(keys, 0, sizeof(keys));
		for (int i = 0; i < K; ++i) {
			scanf("%d", &key);
			++keys[key];
		}

		chests.clear();
		for (int i = 1; i <= N; ++i) {
			Chest chest = Chest(i);
			scanf("%d%d", &(chest.lock), &Ki);
			for (int k = 0; k < Ki; ++k) {
				scanf("%d", &key);
				chest.keys.push_back(key);
			}
			chests.push_back(chest);
		}

		/*
		for (int i = 0; i < KMAX; ++i)
			if (keys[i] > 0) cout << " " << i << ":" << keys[i];
		cout << endl;
		for (int i = 0; i < N; ++i)
			cout << " " << chests[i].id << ":" << chests[i].lock;
		cout << endl;
		*/

		suc = false;
		opened.clear();
		searched.clear();

		Prefix p;
		dfs(p);

		/*
		hash_set<Prefix, hash_prefix, equal_prefix>::iterator it = searched.begin();
		for (; it != searched.end(); it++)
			it->show();
		*/

		cout << "Case #" << t << ":";
		if (!suc) cout << " IMPOSSIBLE" << endl;
		else {
			for (vector<ChestIT>::iterator it = opened.begin(); it != opened.end(); it++)
				cout << " " << (*it)->id;
			cout << endl;
		}
	}

}