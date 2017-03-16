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

#define EPS 1e-6

	vector<double> arrival_time;
	vector<long> loop_time;

	inline void add_hiker(const long &pos, const long &time) {
		arrival_time << 1.0 * time / 360 * (360 - pos);
		loop_time << time;
	}

	inline long calc(const double &t) {
		long ret = 0;
		for(register long i = 0; i < (long)arrival_time.size(); ++ i) {
			ret += long(fabs(floor((t - arrival_time[i]) / loop_time[i])));
		}
		return ret;
	}

	void main(void) {
		ios::sync_with_stdio(false);
		register int i, j;
		long T;
		cin >> T;
		for(long t = 1; t <= T; ++ t) {
			long N;
			cin >> N;
			arrival_time.clear();
			loop_time.clear();
			for(i = 0; i < N; ++ i) {
				long D, H, M;
				cin >> D >> H >> M;
				for(j = 0; j < H; ++ j) {
					add_hiker(D, M + j);
				}
			}
			long ans = arrival_time.size();
			for(i = 0; i < (long)arrival_time.size(); ++ i) {
				_min(ans, calc(arrival_time[i] + EPS));
			}
			cout << "Case #" << t << ": " << ans << endl;

		}
	}
}

int main(void) {
	Solve::main();
}
