/*
 * $File: c.cpp
 * $Date: Sun May 08 18:42:55 2016 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */


#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>


struct Elem {
	int j, p, s;
};

struct SchemeManager {
	int K;
	std::map<std::pair<int, int>, int> jp, ps, js;
	bool try_add(int j, int p, int s) {
		auto check = [&](std::map<std::pair<int, int>, int> &m, int a, int b) {
			return m[std::make_pair(a, b)] < K;
		};
		auto add = [&](std::map<std::pair<int, int>, int> &m, int a, int b) {
			m[std::make_pair(a, b)] += 1;
		};
		if (check(jp, j, p) && check(ps, p, s) && check(js, j, s)) {
			add(jp, j, p);
			add(ps, p, s);
			add(js, j, s);
			return true;
		} else {
			return false;
		}
	}

	void remove(int j, int p, int s) {
		auto remove = [&](std::map<std::pair<int, int>, int> &m, int a, int b) {
			m[std::make_pair(a, b)] -= 1;
		};
		remove(jp, j, p);
		remove(ps, p, s);
		remove(js, j, s);
	}
};


void dfs_gen(Elem &e, int idx, const std::vector<int> &sizes, std::vector<Elem> &elems) {
	if (idx == 3) {
		elems.emplace_back(e);
		return;
	}
	for (int i = 0; i < sizes[idx]; i ++) {
		if (idx == 0)
			e.j = i;
		else if (idx == 1)
			e.p = i;
		else
			e.s = i;
		dfs_gen(e, idx + 1, sizes, elems);
	}
}


struct Run {
	int max_nr_elem = 0;
	std::vector<Elem> ans;

	void search(const std::vector<Elem> &elems,
			int start,
			std::vector<Elem> &chosen,
			SchemeManager &man) {
		if (chosen.size() > max_nr_elem) {
			max_nr_elem = chosen.size();
			ans = chosen;
		}
		for (int i = start; i < elems.size(); i ++) {
			auto &e = elems[i];
			if (man.try_add(e.j, e.p, e.s)) {
				chosen.push_back(e);
				search(elems, i + 1, chosen, man);
				chosen.pop_back();
				man.remove(e.j, e.p, e.s);
			}
		}
	}
};

void solve() {
	int J, P, S, K;
	std::cin >> J >> P >> S >> K;
	std::vector<Elem> elems;
	Elem e;
	dfs_gen(e, 0, {J, P, S}, elems);
	Run run;
	std::vector<Elem> chosen;
	SchemeManager man;
	man.K = K;
	run.search(elems, 0, chosen, man);
	std::cout << run.max_nr_elem << std::endl;
	for (auto &e: run.ans) {
		std::cout << e.j + 1 << " " << e.p + 1 << " " << e.s + 1 << std::endl;
	}
}

int main() {
	int nr_case;
	std::cin >> nr_case;
	for (int case_id = 1; case_id <= nr_case; case_id ++) {
		printf("Case #%d: ", case_id);
		solve();
	}
	return 0;
}

/*
 * vim: syntax=cpp.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */
