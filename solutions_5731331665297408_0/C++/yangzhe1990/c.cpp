#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct min_concat_dfs_t {
	int n;

	const std::vector<std::string> &zip_names;
	const std::vector<std::vector<bool> > &is_connected;

	std::vector<bool> visited;
	std::vector<int> try_order;

	std::vector<int> stack;
	std::vector<std::vector<int> > candidate_level;

	min_concat_dfs_t(int n, const std::vector<std::string> &zip_names,
			 const std::vector<int> &zip_codes,
			 const std::vector<std::vector<bool> > &is_connected)
		: n(n), zip_names(zip_names), is_connected(is_connected),
		  visited(n, false), candidate_level(n, std::vector<int>(1, 0))
	{
		for (int i = 0; i < n; ++i)
			try_order.push_back(i);

		struct zip_code_cmp {
			const std::vector<int> &zip_codes;
			zip_code_cmp(const std::vector<int> &zip_codes)
				: zip_codes(zip_codes) {}

			bool operator() (int x, int y) {
				return (zip_codes[x] < zip_codes[y]);
			}
		};

		std::sort(try_order.begin(), try_order.end(), zip_code_cmp(zip_codes));
	}

	bool valid_to_rewind(int rewind_level) {
		std::vector<bool> reachable(visited.begin(), visited.end());
		std::vector<int> to_expand(stack.begin(), stack.begin() + rewind_level);

		for (int i = 0; i < to_expand.size(); ++i) {
			int node = to_expand[i];
			for (int next = 0; next < n; ++next)
				if (is_connected[node][next] && !reachable[next]) {
					reachable[next] = true;
					to_expand.push_back(next);
				}
		}
		for (int i = 0; i < n; ++i)
			if (!reachable[i])
				return false;
		return true;
	}

	void rewind_to_level(int rewind_level) {
		for (int i = 0; i < n; ++i) {
			while (candidate_level[i].back() > rewind_level) {
				candidate_level[i].pop_back();
			}
		}
		stack.resize(rewind_level);
	}

	void do_dfs(int node, std::string *p_result) {
		stack.push_back(node);
		visited[node] = true;
		*p_result += zip_names[node];

		int level = stack.size();
		for (int i = 0; i < n; ++i)
			if (is_connected[node][i])
				candidate_level[i].push_back(level);

		for (int i = 0; i < n; ++i) {
			int next = try_order[i];
			if (!visited[next]) {
				int rewind_level = candidate_level[next].back();
				if (rewind_level > 0) {
					if (valid_to_rewind(rewind_level)) {
						rewind_to_level(rewind_level);
						do_dfs(next, p_result);
					}
				}
			}
		}
	}

	std::string operator() () {
		std::string ret;
		do_dfs(try_order[0], &ret);
		return ret;
	}
};

void solve(int case_num) {
	std::vector<std::string> zip_names;
	std::vector<int> zip_codes;

	int m, n;
	std::cin >> n >> m;

	std::vector<std::vector<bool> > is_connected(n, std::vector<bool>(n, false));
	for (int i = 0; i < n; ++i) {
		std::string zip_name;
		std::cin >> zip_name;
		zip_names.push_back(zip_name);
		zip_codes.push_back(std::stoi(zip_name));
	}

	for (int i = 0; i < m; ++i) {
		int s, t;
		std::cin >> s >> t;
		--s; --t;
		is_connected[s][t] = true;
		is_connected[t][s] = true;
	}

	std::string best_string = min_concat_dfs_t(n, zip_names, zip_codes, is_connected)();
	std::cout << "Case #" << case_num << ": " << best_string << '\n';
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
	}
}
