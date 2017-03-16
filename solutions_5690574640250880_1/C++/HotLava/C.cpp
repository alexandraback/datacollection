#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template<typename T>
ostream& operator<<(ostream& str, const vector<T>& v) {
	str << "[";
	for(auto n : v) {
		str << n << ", ";
	}
	str << "]";
	return str;
}

template<typename K, typename V>
ostream& operator<<(ostream& str, const unordered_map<K, V>& v) {
	str << "{";
	for(auto&& p : v) {
		str << p.first << " => " << p.second << ", ";
	}
	str << "}";
	return str;
}

int simulate_war( vector<double> naomi,  vector<double> ken) {
	int score = 0;
	while(!naomi.empty()) {
		int n = naomi.back();
		naomi.pop_back();

		auto l = lower_bound(ken.begin(), ken.end(), n, greater<double>());
		if(l == ken.end()) l = ken.begin();

		if(*l < n) score++;
		ken.erase( l );
	}

	return score;
}

int simulate_deceit(vector<double> naomi, vector<double> ken) {
	auto it = ken.begin();

	while(!naomi.empty()) {
		int maxn = naomi.back();
		naomi.pop_back();

		if(*it < maxn) {
			return naomi.size();
		} else {
			it++;
		}
	}

	return 0;
}

vector<bool> solution;
int remaining = 0;

bool backtracking_test(int rows, int cols, int mines, vector<bool> path) 
{
	//cout << "backtracking " << rows << ", " << cols << ", " << " ," << mines << ", " << path << endl;

	if(rows == 1 || cols == 1) return false;

	if(mines == 0) {
		solution = path;
		return true;
	}

	vector<bool> rpath(path), tpath(path);
	rpath.push_back(true);
	tpath.push_back(false);

	bool right=false, top=false, init=false;
	if(mines >= rows) {
		init = true;
		right = backtracking_test(rows, cols-1, mines-rows, rpath);
		if(right) {
			//solution = rpath;
			return true;
		}

	}

	if(mines >= cols) {
		init = true;
		top = backtracking_test(rows-1,cols, mines-cols, tpath);
		if(top) {
			//solution = tpath;
			return true;
		}
	}

	if(rows > 2 && cols > 2 && !init) {
		solution = path;
		remaining = mines;

		return true;
	}

	if(cols >= 2 && rows >= 2) return false;




	return false;
}

void print_path_reconstruction(int rows, int cols, vector<bool>& path)
{
	//cout << "reconstructin: " << path << endl;

	vector<vector<char>> image(rows, vector<char>(cols, '.'));

	auto it = path.begin();

	int col = 0, row = 0;

	while(it != path.end()) {
		if(*it++) { // gone right

			for(int i=0; i<rows; ++i) image.at(i).at(col) = '*';
			col++;

		} else { // gone top

			for(int i=0; i<cols; ++i) image.at(row).at(i) = '*';
			row++;

		}
	}

	image.at(rows-1).at(cols-1) = 'c';

	for(int i=row; i<rows-2 && remaining > 0; ++i, --remaining) image.at(i).at(col) = '*';
	for(int i=col+1; i<cols-2 && remaining > 0; ++i, --remaining) image.at(row).at(i) = '*';

	for(auto row : image) {
		for(auto p : row) cout << p;
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int r, c, m;
		cin >> r >> c >> m;
		//m = r*c - i - 1;

		//cout << "testing " << i << endl;
		
		if(r == 1) {
			solution = vector<bool>(m, true);
			cout << "Case #" << i+1 << ": " <<  endl;

			print_path_reconstruction(r, c, solution);
			continue;
		}

		if(c == 1) {
			solution = vector<bool>(m, false);
			cout << "Case #" << i+1 << ": " <<  endl;

			print_path_reconstruction(r, c, solution);
			continue;
		}

		int diff = r*c - m;
		if(diff == 1) {
			solution = vector<bool>(r, false);
			cout << "Case #" << i+1 << ": " <<  endl;

			print_path_reconstruction(r, c, solution);
			continue;
		} else if(diff == 3 || diff == 2 || diff == 5 || diff == 7) {
			cout << "Case #" << i+1 <<  ":" << endl << "Impossible" << endl;
			continue;
		}

		vector<bool> path;

		bool res = backtracking_test(r,c,m, path);

		//cout << solution << endl;

		if(res) {
			cout << "Case #" << i+1 << ": " << endl;
			print_path_reconstruction(r, c, solution);
		} else {
			cout << "Case #" << i+1 << ":" << endl << "Impossible" << endl;
		}
	}
}
