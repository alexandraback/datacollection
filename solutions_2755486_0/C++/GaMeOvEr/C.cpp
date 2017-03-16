#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<list>
#define _USE_MATH_DEFINES
using namespace std;

/*
di – the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
ni – the number of attacks from this tribe
wi, ei – the westmost and eastmost points respectively of the Wall attacked on the first attack
si – the strength of the first attack
delta_di – the number of days between subsequent attacks by this tribe
delta_pi – the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
delta_si – the change in strength between subsequent attacks
*/

class tribe {
	public:
	int d, n, w, e, s, delta_d, delta_p, delta_s;

	tribe(int aa, int bb, int cc, int dd, int ee, int ff, int gg, int hh) {
		d = aa;
		n = bb;
		w = cc;
		e = dd;
		s = ee;
		delta_d = ff;
		delta_p = gg;
		delta_s = hh;
	}
};

class attack {
	public:
	tribe* tr;
	int day, attack_no;
	attack() {}
	/*bool operator<(const attack& other) {
		return (day < other.day);
	}*/
};
/*
class CompareAttack {
    public:
    bool operator()(attack* &t1, attack* &t2) // Returns true if t1 is earlier than t2
    {
       if (t1->day < t2->day) return true;
       else {
       		return false;
       	}
    }
};*/

struct CompareAttack : public std::binary_function<attack*, attack*, bool> {
  bool operator()(const attack* lhs, const attack* rhs) const
  {
    return lhs->day > rhs->day;
  }
};

class build {
	public:
	int w;
	int e;
	int s;
	build(int w1, int e1, int s1) {
		w = w1;
		e = e1;
		s = s1;
	}
};



int main() {
	int t, N, d,n,w,e,s,delta_d, delta_p, delta_s;
	int wall[400];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 400; j++) {
			wall[j] = 0;
		}
		priority_queue<attack*, vector<attack*>, CompareAttack> pq;
		int ans = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
			tribe* new_tribe = new tribe(d, n, w, e, s, delta_d, delta_p, delta_s);
			attack* new_attack = new attack();
			new_attack->day = d;
			new_attack->attack_no = 1;
			new_attack->tr = new_tribe;
			pq.push(new_attack);
		}
		while(! pq.empty()) {
			int curr_day = (pq.top())->day;
			list<build*> build_list;
			while((! pq.empty()) && ((pq.top())->day == curr_day)) {
				attack* curr_attack = pq.top();
				pq.pop();

				
				tribe* curr_tribe = curr_attack->tr;
				int w1 = curr_tribe->w + ((curr_attack->attack_no - 1) * curr_tribe->delta_p) + 200;
				int e1 = curr_tribe->e + ((curr_attack->attack_no - 1) * curr_tribe->delta_p) + 200;
				int s1 = curr_tribe->s + ((curr_attack->attack_no - 1) * curr_tribe->delta_s);

				//printf("ATTACK!! day: %d, w: %d, e: %d, s: %d\n", curr_day, w1-200, e1-200, s1);
				
				for (int k = w1; k < e1; k++) {
					if (wall[k] < s1) {
						//printf("SUCCESS\n");
						ans++;
						build* new_build = new build(w1, e1, s1);
						build_list.push_back(new_build);
						break;
					}
				}

				if (curr_attack->attack_no < curr_tribe->n) {
					attack* new_attack = new attack();
					new_attack->tr = curr_tribe;
					new_attack->day = curr_attack->day + (curr_tribe->delta_d);
					new_attack->attack_no = curr_attack->attack_no + 1;
					pq.push(new_attack);
				}
				delete curr_attack;
			}
			for (list<build*> :: iterator it = build_list.begin(); it != build_list.end(); it++) {
				int w1 = (*it)->w;
				int e1 = (*it)->e;
				int s1 = (*it)->s;
				for (int k = w1; k < e1; k++) {
					
					if (s1 > wall[k]) {
						wall[k] = s1;
					}
					//printf("BUILD: time: %d, wall: %d %d\n", curr_day, k-200, wall[k]);
				}
			}
			///////////////////////
			

			////////////////////////
		}
		printf("Case #%d: %d\n", i+1, ans);
	} 
	return 0;
}
