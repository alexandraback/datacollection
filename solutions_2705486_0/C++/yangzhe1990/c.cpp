#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include <assert.h>

const int allowed_pos_diff = 5;

struct four_int_tuple {
	int a[4];
};

struct four_int_tuple calc_change(
	std::string::const_iterator a1, std::string::const_iterator a2,
	std::string::const_iterator b)
{
	struct four_int_tuple change;
	change.a[0] = -1;

	int size = a2 - a1;
	int count = 0;
	int pos = 0;
	std::string::const_iterator a;
	for (a = a1; a < a2 && *a == *b; ++a, ++b, ++pos);
	int first_change = pos;
	int last_change = first_change;
	if (a < a2)
		++count;
	for (++a, ++b, ++pos; a < a2; ++a, ++b, ++pos) {
		if (*a != *b) {
			if (pos - last_change >= allowed_pos_diff) {
				last_change = pos;
				++count;
			}
			else
				return change;
		}
	}

	last_change = size - last_change;
	if (last_change == 0 || last_change > allowed_pos_diff)
		last_change = allowed_pos_diff;
	change.a[0] = size;
	change.a[1] = first_change;
	change.a[2] = last_change - 1;
	change.a[3] = count;
	assert(count <= size);

	return change;
}

int get_result(const std::vector<std::string> &dict, const std::string &line) {
	std::vector<std::vector<struct four_int_tuple> >
		transitions(line.size());

	for (int i = 0; i < line.size(); ++i) {
		for (int j = 0; j < dict.size(); ++j) {
			const std::string &s = dict[j];
			if (s.size() + i <= line.size()) {
				struct four_int_tuple change = calc_change(
					s.begin(), s.end(), line.begin() + i);
				if (change.a[0] >= 0) {
					change.a[0] = j;
					transitions[i].push_back(change);
				}
			}
		}
	}

	int size = (line.size() + 1) * allowed_pos_diff;
	int *min_changes = new int[size];
	std::fill(min_changes, min_changes + size, line.size() + 1);
	min_changes[4] = 0;

	for (int i = 0; i < line.size(); ++i) {
		for (int j = 0; j < allowed_pos_diff; ++j) {
			for (int k = 0; k < transitions[i].size(); ++k) {
				int base_cost = min_changes[i * allowed_pos_diff + j];
				if (base_cost == line.size() + 1)
					continue;

				int len = dict[transitions[i][k].a[0]].size();
				int first = transitions[i][k].a[1];
				int last = transitions[i][k].a[2];
				int cost = transitions[i][k].a[3] + base_cost;
				if (cost > line.size())
					continue;
				if (first == len
				    || j + first >= allowed_pos_diff - 1) {
					int new_i = i + len;
					int new_j = std::min(last, len + j);
					assert(new_j < allowed_pos_diff);
					assert(new_i <= line.size());

					if (cost <
					    min_changes[new_i * allowed_pos_diff + new_j])
						min_changes[new_i * allowed_pos_diff
							    + new_j] = cost;
				}
			}
		}
	}

	int result = line.size() + 1;
	{
		int i = line.size();
		for (int j = 0; j < allowed_pos_diff; ++j)
			result = std::min(result,
					  min_changes[i * allowed_pos_diff + j]);
	}

	delete[] min_changes;
	return result;
}

void read_data(int *mass, int *p_init_mass, int *p_n) {
	scanf("%d %d", p_init_mass, p_n);
	for (int i = 0; i < *p_n; ++i)
		scanf("%d", mass + i);
}

const int MAXN = 4000;

int main() {
	std::ifstream fin("garbled_email_dictionary.txt");
	std::vector<std::string> dict;
	std::string line;
	while (std::getline(fin, line)) {
		dict.push_back(line);
	}

	int t;
	std::cin >> t;
	std::getline(std::cin, line);
	for (int i = 1; i <= t; ++i) {
		std::getline(std::cin, line);
		printf("Case #%d: %d\n", i, get_result(dict, line));
	}
	return 0;
}
