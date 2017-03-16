#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct tribe {
	int delta_d;
	int delta_p;
	int delta_s;
	int w,e;
	int s;
	int n;
	int d;
};
struct atk {
	int tribe_id;
	int w, e;
	int times;
	int s;
	void print() {
		//cout << "atk: " << tribe_id << " " << w << " " << e << " " << s << " " << times << endl;
	}
};
class wall {
private:
	map<int, int> bricks;
	map<int, int> upd;
public:
	bool attack(atk e_atk) {
		e_atk.print();
		bool suc =false;
		for(int i=e_atk.w; i<e_atk.e; ++i) {
			if(bricks[i] < e_atk.s) {
				suc = true;
				upd[i] = e_atk.s;
			}
		}
		return suc;
	}
	void update() {
		map<int, int>::iterator it;
		for(it = upd.begin(); it != upd.end(); ++it) {
			bricks[it->first] = it->second;
		}
	}
};
void solve() {
	int n;
	cin >> n;
	vector<tribe> tribes;
	map<int, vector<atk> > atk_q;
	
	for(int i=0; i<n; ++i) {
		tribe t;
		cin >> t.d >> t.n >> t.w >> t.e >> t.s >> t.delta_d >> t.delta_p >> t.delta_s;
		tribes.push_back(t);
	}

	for(int i=0; i<n; ++i) {
		tribe& t = tribes[i];
		atk_q[t.d].push_back((atk) {
			i,
			t.w,
			t.e,
			1,
			t.s
		});
	}
	wall w;
	map<int, vector<atk> >::iterator it;
	int cnt = 0;
	while(atk_q.size()) {
		it = atk_q.begin();
		int dat = it->first;
		vector<atk> atks = it->second;
		atk_q.erase(it);
		//cout << "dat: " << dat << endl;
		for(int i=0; i< atks.size(); ++i) {
			atk e_atk = atks[i];
			if(w.attack(e_atk)) {
				//cout << "Success: ";
				e_atk.print();
				cnt ++;
			}
				
			tribe t = tribes[e_atk.tribe_id];

			if(e_atk.times >= t.n) continue;
			atk_q[dat + t.delta_d].push_back((atk) {
				e_atk.tribe_id,
				e_atk.w + t.delta_p,
				e_atk.e + t.delta_p,
				e_atk.times + 1,
				e_atk.s + t.delta_s
			});
		}

		w.update();
	}
	cout << cnt;
}
int main() {
	int casn;
	cin >> casn;
	for(int casi=1; casi <= casn; ++casi) {
		cout << "Case #" << casi << ": ";
		solve();
		cout << endl;
	}
	return 0; 
}
