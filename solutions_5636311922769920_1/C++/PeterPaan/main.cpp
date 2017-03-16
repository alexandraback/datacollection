#include <iostream>

using namespace std;

typedef unsigned long long Int;

Int fi(Int K, Int begin, Int end) {
	Int ret;
	if (begin == end) {
		ret = begin;
	} else {
		ret = end + K * fi(K, begin, end - 1);
	}
	//cerr << "fi (K="<<K<<" , " << begin << ", " << end << ") = " << ret << endl;
	return ret;
}

Int fn(Int K, Int C, int nb_info) {
	Int begin  = nb_info;
	Int end = nb_info + C - 1;
	if (end >= K) {
		end = K - 1;
	}
	Int pos = fi(K, begin, end);
	//cerr << "fn (K = " << K << ", C=" << C << ", nbinfo=" << nb_info << ") = " << (pos + 1) << endl;
	return pos + 1; // We want the position, not a 0-started index
}

int main(int, char **) {
	int nb_tc;
	cin >> nb_tc;
	Int K, C, S;
	for (auto tc = 1; tc <= nb_tc;  ++tc) {
		cin >> K >> C >> S;
		cout << "Case #" << tc << ':';
		if (S * C < K) {
				cout << " IMPOSSIBLE" << endl;
		} else {
			int nb_info = 0;
			while (nb_info <= K - 1) {
				cout << ' ' << fn(K, C, nb_info);
				nb_info += C;
			}
			cout << endl;
		}
	}
    return 0;
}
