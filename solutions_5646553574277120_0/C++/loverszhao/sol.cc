#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;


// ====== Defines ======


// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

#ifdef DBG
std::fstream logs;
#endif

int C, D, V;

vector<int> d_v;
vector<int> v_v;
vector<int> t_v;

int c_size;
int combination[10];


// ------ Global Variables ------


// ====== Function declarations ======

int get_next_combination();
void init_combination();

// ------ Function declarations ------


int init_only_once()
{
#ifdef DBG
	logs << ">>>>init_only_once()" << endl;
	logs << "<<<<init_only_once()" << endl << endl;
#endif

        return 0;
}

int handle_input()
{
#ifdef DBG
	logs << ">>>>>>handle_input()" << endl;
#endif

	cin >> C >> D >> V;

	d_v.clear();
	v_v.clear();

	int temp;
	for (int iii = 1; iii <= D; iii++) {
		cin >> temp;
		d_v.push_back(temp);
	}

	for (int iii = 1; iii <= V; iii++) {
		v_v.push_back(iii);
	}

	init_combination();
	do {

		int sum = 0;
		logs << "c_size=" << c_size << endl;

		for (int iii = 1; iii <= c_size; iii++) {
			sum += d_v[ combination[iii] - 1 ];
			logs << combination[iii] << "  ";
		}
		logs << endl;
		logs << "sum=" << sum << endl;

		vector<int>::iterator it = v_v.begin();
		while (v_v.end() != it) {
			if (sum == *it) {
				v_v.erase(it);
				break;
			}
			it++;
		}
                
        } while (-1 != get_next_combination());

	logs << "v_v=" << endl;
	logs << "\t";
	for (int iii = 0; iii < v_v.size(); iii++) {
		logs << v_v[iii] << "  ";
	}
	logs << endl;


#ifdef DBG
	logs << "<<<<<<handle_input()" << endl << endl;
#endif
        return 0;
}

int init_per_case()
{
#ifdef DBG
	logs << ">>>>>>init_per_case()" << endl;
#endif



#ifdef DBG
	logs << "<<<<<<init_per_case()" << endl << endl;
#endif
        return 0;
}

long long run()
{
#ifdef DBG
	logs << ">>>>>>run()" << endl;
#endif

	if (0 == v_v.size() || 1 == v_v.size())
		return v_v.size();

	int ans = v_v.size();

	std::sort(v_v.begin(), v_v.end());

	logs << "v_v=" << endl;
	logs << "\t";
	for (int iii = 0; iii < v_v.size(); iii++) {
		logs << v_v[iii] << "  ";
	}
	logs << endl;

	const double d = log2(v_v[v_v.size() - 1]);
	logs << "d=" << d << endl;

	int temp = 1 + (int)d;

	for (int jjj = 0; jjj < temp; jjj++) {
		const int m = pow(2.0, jjj);
		logs << "m=" << m << endl;
		for (int iii = 0; iii < d_v.size(); iii++) {
			if (m == d_v[iii])
				temp--;
		}
	}

	ans = std::min(ans, temp);

#ifdef DBG
	logs << "<<<<<<run() = " << ans << endl << endl;
#endif
	return ans;
}

int main()
{
#ifdef DBG
        logs.open("log.txt", std::fstream::out);
	logs << ">>main()" << endl << endl;
#endif

        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        long long run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": " << run_ret << endl;

#ifdef DBG
		logs << "Case #" << tt << ": " << run_ret << endl;
#endif
        }


#ifdef DBG
	logs << "<<main()" << endl;
	logs.close();
#endif
        return 0;
}



// e.g.
// c_size == 3, pos == 2
// 
// The first combination : 1    2    3
// The second combination: 1    2    4
// ...
// The last combination  : L-2  L-1  L
// 
// The last value of pos 2 is: L-1
//
inline int cnt_pos_is_last(const int pos)
{
	return D - c_size + pos == combination[pos];
}

// Return 0 if not
// Return 1 otherwise
int is_last()
{
	for (int i = 1; i <= c_size; i++) {
		if (!cnt_pos_is_last(i))
			return 0;
        }
	return 1;
}

// 
// Update values of combination from @(pos + 1) to the end
// 
// e.g.
// c_size = 5, L = 10
// 
// The first combination : 1 2 3 4  5
// The second combination: 1 2 3 4  6
// ...
// The 6th combination   : 1 2 3 4  10
// The 7th combination   : 1 2 3 5  6
// ...
// The 21th combination  : 1 2 3 9  10
// 
// update_after_pos(3)
// 
// The 22th combination  : 1 2 4 5  6
void update_after_pos(const int pos)
{
	for (int i = pos + 1; i <= c_size; i++)
		combination[i] = combination[i - 1] + 1;
}

int get_next_combination()
{
// logs << "get_next_combination()" << endl;
	if (is_last()) {
		if (D == c_size)
			return -1; // Current combination is the end
		else {
			c_size++;
			for (int i = 1; i <= c_size; i++)
				combination[i] = i;
			return 0;
                }
        }

	for (int i = c_size; i >= 1; i--) {
		if (!cnt_pos_is_last(i)) {
			combination[i]++;
			update_after_pos(i);
			break;
                }
        }

	return 0;
}

void init_combination()
{
	c_size = 1;
	combination[1] = 1;
}

