#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <hash_map>
#include <map>

using namespace std;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, N;

struct input {
	int day;
	int delta_d;
	int num_att;
	int w, e;
	int delta_p;
	int s;
	int delta_s;
};

struct attack {
	int w, e, s;
	bool isLess(attack& at) {
		return at.w <= w && e <= at.e && s <= at.s;
	}
};

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t_ = 0; t_ != T; ++t_) {
		cin >> N;
		map<int, list<attack> > attacks;
		for (int n = 0; n != N; ++n) {
			input in1;
			cin >> in1.day >> in1.num_att >> in1.w >> in1.e >> in1.s >> in1.delta_d >> in1.delta_p >> in1.delta_s;
			for (int i = 0; i < in1.num_att; i++) {
				attack at = { in1.w, in1.e, in1.s };
				attacks[in1.day].push_back(at);
				in1.day += in1.delta_d;
				in1.w += in1.delta_p;
				in1.e += in1.delta_p;
				in1.s += in1.delta_s;
			}
		}
		int count = 0;
		for (map<int, list<attack> >::iterator it = attacks.begin(); it != attacks.end(); ++it) {
			list<attack>& day_attacks = it->second;
			for (list<attack>::iterator jt = day_attacks.begin(); jt != day_attacks.end(); ++jt) {
				count++;
				attack& att = *jt;
				map<int, list<attack> >::iterator it1 = it;
				for (++it1; it1 != attacks.end(); ++it1) {
					list<attack>& day_attacks1 = it1->second;
					for (list<attack>::iterator jt1 = day_attacks1.begin(); jt1 != day_attacks1.end();) {
						attack& att1 = *jt1;
						if (att1.isLess(att)) {
							list<attack>::iterator jt2 = jt1; ++jt1;
							day_attacks1.erase(jt2);
						} else {
							++jt1;
						}
					}
				}
			}			
		}
        cout << "Case #" << (t_ + 1) << ": " << count << "\n";
    }
    return 0;
}
