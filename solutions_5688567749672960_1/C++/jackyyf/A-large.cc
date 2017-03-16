#include <bits/stdc++.h>

using namespace std;

namespace Solve {

	template<class T> inline bool _min(T& data, const T& comp) {
		if (comp < data) {
			data = comp;
			return true;
		}
		return false;
	}

	template<class T> inline bool _max(T& data, const T& comp) {
		if (data < comp) {
			data = comp;
			return true;
		}
		return false;
	}

	template<class T> inline vector<T>& operator<< (vector<T> &storage, const T& data) {
		storage.push_back(data);
		return storage;
	}

	template<class T> inline set<T>& operator<< (set<T> &storage, const T& data) {
		storage.insert(data);
		return storage;
	}


	template<class T> inline void operator!(const vector<T>& vect) {
		for(const T& data : vect) {
			cout << data << " ";
		}
	}

	template<class T> inline queue<T>& operator<< (queue<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline stack<T>& operator<< (stack<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline priority_queue<T>& operator<< (priority_queue<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline queue<T>& operator>> (queue<T> &storage, T& data) {
		data = storage.front();
		storage.pop();
		return storage;
	}

	template<class T> inline stack<T>& operator>> (stack<T> &storage, T& data) {
		data = storage.top();
		storage.pop();
		return storage;
	}

	template<class T> inline priority_queue<T>& operator>> (priority_queue<T> &storage, T& data) {
		data = storage.top();
		storage.pop();
		return storage;
	}

	queue<long> S;
	set<long> power;
	long pw[32];

	inline long reverse(long orig) {
		while(orig) {
			S.push(orig % 10);
			orig = orig / 10;
		}
		long ret = 0;
		while(S.size()) {
			ret = ret * 10 + S.front();
			S.pop();
		}
		return ret;
	}

	long solve(long target) {
		if (target == 1) return 1;
		long cur = 1, cnt = 1, ret = target;
		long digit = 1;
		while (cur <= target) {
			_min(ret, cnt + target - cur);
			if (cur == target) return ret;
			long np = *power.upper_bound(cur);
			if (np <= target) {
				if (cur == 1) {
					cur = 10; ++ digit; cnt = 10;
					continue;
				}
				cur += pw[digit >> 1] - 1; cur = reverse(cur);
				cnt += pw[digit >> 1] + np - cur; cur = np;
				++ digit;
			} else {
				if (target % 10 == 0) {
					++ cnt; -- target;
				}
				long tmp = reverse(target);
				tmp %= pw[digit >> 1];
				cur += tmp; cnt += tmp;
				cur = reverse(cur); cnt += 1 + target - cur;
				cur = target;
			}
		}
		return ret;
	}

	void main(void) {
		ios::sync_with_stdio(false);
		register long i, j = 1;
		pw[0] = j;
		for(i = 1; i <= 18; ++ i) {
			power << j;
			j *= 10; pw[i] = j;
		}
		long T;
		cin >> T;
		for(auto t = 1; t <= T; ++ t) {
			long N;
			cin >> N;
			cout << "Case #" << t << ": " << solve(N) << endl; 
		}
	}
}

int main(void) {
	Solve::main();
}
