#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename Cfg>
struct HashTable {
public:
	typedef Cfg Config;
	typedef typename Config::Key Key;
	typedef typename Config::Index Size, Index;

	Key emptyKey() const { return config.emptyKey(); }

	Index hash(const Key &key) const { return config.hash(key); }

	bool equals(const Key &key1, const Key &key2) const { return config.equals(key1, key2); }
	bool isEmptyKey(const Key &key) const { return config.isEmptyKey(key); }

public:
	HashTable(Config config = Config(), Size minCapacity = 0): table(NULL), tableSize(0), numElements(0), config(config) {
		reserve(minCapacity);
	}

	HashTable(const HashTable &that): table(NULL), tableSize(0), numElements(0), config(that.config) {
		*this = that;
	}

	HashTable &operator=(const HashTable &that) {
		if(this == &that) return *this;
		numElements = 0;	//reallocateでコピーさせないために
		reserve(that.numElements);
		clear();
		copyTable(that.table, that.table + that.tableSize);
		numElements = that.numElements;
		return *this;
	}

	~HashTable() {
		delete[] table;
		table = NULL;
	}

	void swap(HashTable &that) {
		std::swap(table, that.table);
		std::swap(tableSize, that.tableSize);
		std::swap(numElements, that.numElements);
	}

	void clear() {
		for(Key *p = table, *pEnd = p + tableSize; p != pEnd; ++ p)
			if(!isEmptyKey(*p))
				*p = emptyKey();
		numElements = 0;
	}

public:
	bool empty() const { return numElements == 0; }
	Size size() const { return numElements; }
	Size capacity() const { return calculateCapacity(tableSize); }

	bool reserve(Size minCapacity) {
		if(minCapacity <= calculateCapacity(tableSize))
			return false;
		Size newSize = tableSize == 0 ? 4 : tableSize * 2;
		while(calculateCapacity(newSize) < minCapacity)
			newSize *= 2;
		reallocate(newSize);
		return true;
	}

private:
	static Size calculateCapacity(Size tableSize) {
		return tableSize * 3 / 4;
	}

	void copyTable(const Key *p, const Key *pEnd) {
		for(; p != pEnd; ++ p) {
			if(!isEmptyKey(*p)) {
				Index index;
				bool found = probe(*p, index);
				assert(!found);
				table[index] = *p;
			}
		}
	}

	void reallocate(Size newSize) {
		assert(newSize > tableSize && (newSize & (newSize - 1)) == 0);
		Key *oldTable = table;
		Size oldSize = tableSize;
		table = new Key[newSize];
		tableSize = newSize;
		std::fill(table, table + tableSize, emptyKey());
		if(numElements != 0)
			copyTable(oldTable, oldTable + oldSize);
		delete[] oldTable;
	}

private:
	//keyが見つかったかどうかを返す
	bool probe(const Key &key, Index &resIndex) const {
		assert(numElements < tableSize);
		Size mask = tableSize - 1;
		Index h = hash(key) & mask, numProbes = 0;
		while(1) {
			const Key &k = table[h];
			if(isEmptyKey(k)) {
				resIndex = h;
				return false;
			}else if(equals(k, key)) {
				resIndex = h;
				return true;
			}
			++ numProbes;
			h = (h + numProbes) & mask;
			assert(numProbes < tableSize);
		}
	}

public:
	bool count(const Key &key) const {
		if(empty()) return false;
		Index dummy;
		return probe(key, dummy);
	}
	
	bool insert(const Key &key) {
		reserve(numElements + 1);
		Index index;
		bool found = probe(key, index);
		if(found) return false;
		table[index] = key;
		++ numElements;
		return true;
	}

	const Key *find(const Key &key) const {
		if(empty()) return NULL;
		Index index;
		bool found = probe(key, index);
		if(!found) return NULL;
		return &table[index];
	}

	Key *find(const Key &key) {
		return const_cast<Key*>(find(key));
	}

	Key &findInsert(const Key &key) {
		reserve(numElements + 1);
		Index index;
		bool found = probe(key, index);
		if(!found) {
			table[index] = key;
			++ numElements;
		}
		return table[index];
	}

	bool findInsertBool(const Key &key) {
		reserve(numElements + 1);
		Index index;
		bool found = probe(key, index);
		if(!found) {
			table[index] = key;
			++ numElements;
		}
		return !found;
	}

private:
	const Config config;
	Key *table;
	Size tableSize;		//power of two (or 0)
	Size numElements;	//number of nonempty elements
};



int X, R, C;

vector<vpii> polyominos;

vpii normalize(const vpii& v) {
	int iy = INF, ix = INF;
	each(i, v)
		iy = min(iy, i->first);
	each(i, v) if(i->first == iy)
		ix = min(ix, i->second);
	vpii r = v;
	each(i, r) i->first -= iy, i->second -= ix;
	sort(all(r));
	if(unique(all(r)) != r.end()) return vpii();
	return r;
}
//ポリオミノを列挙する。BFS的にやってる
void enumeratePolyominos() {
	const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
	set<vpii> q, next;
	next.insert(vpii(1, mp(0, 0)));
	rep(i, X-1) {
		q.clear(); q.swap(next);
		each(t, q) if(!t->empty()) {
			vpii u = *t; u.pb(mp(INF, INF));
			each(j, *t) {
				rep(d, 4) {
					u.back() = mp(j->first+dy[d], j->second+dx[d]);
					next.insert(normalize(u));	//normalizeが空を返すのをそのままinsertしてるから別に除去してる
				}
			}
		}
	}
	next.erase(vpii());
	polyominos.assign(all(next));
}
bool isReflectionOrRotation(vpii v, vpii w) {
	rep(mx, 2) {
		rep(my, 2) {
			rep(sw, 2) {
				if(normalize(v) == w) return true;
				each(i, v) swap(i->first, i->second);
			}
			each(i, v) i->first *= -1;
		}
		each(i, v) i->second *= -1;
	}
	return false;
}

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};


struct Xor128 {
	unsigned x, y, z, w;
	Xor128(): x(123456789), y(362436069), z(521288629), w(88675123) { }
	unsigned next() {
		unsigned t = x ^ (x << 11);
		x = y; y = z; z = w;
		return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
	}
	//手抜き
	unsigned next(unsigned n) { return next() % n; }
	unsigned long long nextll() {
		unsigned long long x = (unsigned long long)next() << 32;
		return x | next();
	}
} xor128;

typedef unsigned long long Hash;

struct Config {
	typedef Hash Key;
	typedef unsigned Index;
	Key emptyKey() const { return ~0ULL; }
	Index hash(const Key &key) const {
		return (unsigned)key ^ (unsigned)(key >> 32);
	}
	bool equals(const Key &key1, const Key &key2) const { return key1 == key2; }
	bool isEmptyKey(const Key &key) const { return !~key; }

	Config() { }
};
typedef HashTable<Config> HashSet;

vi representives, numbers;
int placed[21][21];
int counts[300];
bool canplace[300];
int canpcnt;
Hash hashes[700];
Hash curhash;
HashSet hashset;
int curcnt;

void backtrack(int i, int j) {
	if(canpcnt == representives.size()) return;
	if(i == R) {
		if(!hashset.findInsertBool(curhash)) return;
		bool changed = false;
		rep(k, representives.size()) if(counts[k] > 0 && !canplace[k]) {
			canplace[k] = true;
			++ canpcnt;
			changed = true;
		}
		if(changed) {
			rep(y, R) {
				rep(x, C) {
					cerr << char('A' - 1 + placed[y][x] / 1000);
					cerr << (placed[y][x] % 1000);
				}
				cerr << endl;
			}
			cerr << endl;
		}
		return;
	}
	if(j == C) return backtrack(i+1, 0);
	if(placed[i][j])
		return backtrack(i, j+1);
	if(!hashset.findInsertBool(curhash)) return;
	rep(k, polyominos.size()) {
		const vpii &v = polyominos[k];
		int n = numbers[k];
		bool ok = true;
		each(p, v) {
			int yy = i + p->first, xx = j + p->second;
			ok &= 0 <= yy && yy < R && 0 <= xx && xx < C && !placed[yy][xx];
			if(!ok) break;
		}
		if(!ok) continue;
		each(p, v) {
			int yy = i + p->first, xx = j + p->second;
			placed[yy][xx] = (n + 1) * 1000 + curcnt;
			curhash ^= hashes[yy * C + xx];
		}
		if(!placed[i][j]) cerr << "err 1" << endl;
		if((++ counts[n]) == 1)
			curhash ^= hashes[R * C + n];
		++ curcnt;

		backtrack(i, j+1);

		-- curcnt;
		if((-- counts[n]) == 0)
			curhash ^= hashes[R * C + n];
		each(p, v) {
			int yy = i + p->first, xx = j + p->second;
			placed[yy][xx] = 0;
			curhash ^= hashes[yy * C + xx];
		}
	}
}

int main() {
	rep(k, 700) hashes[k] = xor128.nextll();
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		scanf("%d%d%d", &X, &R, &C);
		if(R < C) swap(R, C);
		bool ans;
		//基本的に単調的。小さい盤面で埋めた後に残りを適当に埋めれば良いから
		if(X >= 7 || R * C % X != 0) {
			ans = true;
		}else if(X <= 2) {
			ans = false;
		}else if(X == 3) {
			ans = C == 1;
		}else if(X == 4) {
			ans = C <= 2;
			//(C == 2)はできない：
			//例えば *
			//       **  が置けない
			//       *
			//1+2n の空間が余るから
		}else if(X == 5) {
			ans = C <= 2 || (C == 3 && R == 5);
			//(C == 3 && R == 5)はできない：
			//**
			// **  が置けない
			//  *
			//なぜなら、どう置いても 1 か 4 か 7 の空間が余るから
		}else if(X == 6) {
			ans = C <= 3;
			//(C == 3)はできない：
			//例えば *
			//       ***  が置けない
			//       *
			//       *
			//なぜなら、上か下に 3n+2 の空間が余るから
		}/*else {
			ans = false;
			enumeratePolyominos();
			UnionFind uf; uf.init(polyominos.size());
			rep(i, polyominos.size()) rep(j, i)
				if(isReflectionOrRotation(polyominos[i], polyominos[j]))
					uf.unionSet(i, j);
			representives.clear();
			rep(i, polyominos.size()) if(uf.root(i) == i)
				representives.push_back(i);
			numbers.resize(polyominos.size());
			rep(i, polyominos.size()) {
				int k = uf.root(i);
				int j = lower_bound(all(representives), k) - representives.begin();
				numbers[i] = j;
			}

			mset(placed, 0);
			mset(canplace, 0);
			canpcnt = 0;
			curhash = 0;
			hashset.clear();
			curcnt = 0;
			backtrack(0, 0);
			rep(k, representives.size()) {
				if(!canplace[k]) {
					ans = true;
					each(i, polyominos[representives[k]])
						cerr << i->first << "," << i->second << "; ";
					cerr << endl;
				}
			}
		}*/
		printf("Case #%d: %s\n", ii+1, ans ? "RICHARD" : "GABRIEL");
	}
	return 0;
}
