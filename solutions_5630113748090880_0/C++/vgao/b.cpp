#include <bits/stdc++.h>

using namespace std;

using row = vector<int>;
using mat = vector<row>;


void partition(mat & r, mat & v)
{
	r.clear();
	size_t n = (v.size() + 1) / 2;
	for (size_t i = 0; i < n; ++i) {
		auto f = [&v, i](const row & a, const row & b) {
			return a[i] < b[i];
		};
		sort(v.begin(), v.end(), f);
		r.push_back(v[0]);
		if (v.size() == 1 || v[1][i] != v[0][i]) {
			r.push_back(row(n, -1));
			v.erase(v.begin());
		}
		else {
			r.push_back(v[1]);
			v.erase(v.begin(), v.begin() + 2);
		}
	}
}

void print_row(const row & v)
{
	cout << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		if (i)
			cout << ", ";
		cout << v[i];
	}
	cout << "]" << endl;
}

void print_mat(const mat & v)
{
	for (size_t i = 0; i < v.size(); ++i)
		print_row(v[i]);
}

void c_row(mat & v, size_t i, const row & r, bool f = false)
{
    for (size_t j = 0; j < r.size(); ++j)
		if (f || r[j] != -1)
			v[i][j] = r[j];
}

bool f_row(const mat & v, size_t i, const row & r)
{
	for (size_t j = 0; j < r.size(); ++j)
		if (v[i][j] != r[j] && v[i][j] != -1 && r[j] != -1)
			return false;
	return true;
}

bool f_col(const mat & v, size_t j, const row & r)
{
	for (size_t i = 0; i < v.size(); ++i)
		if (v[i][j] != r[i] && v[i][j] != -1 && r[i] != -1)
			return false;
	return true;
}

void c_col(mat & v, size_t j, const row & r, bool f = false)
{
	for (size_t i = 0; i < v.size(); ++i)
		if (f || r[i] != -1)
			v[i][j] = r[i];
}

void e_row(row & r, const mat & v, size_t i)
{
	r = v[i];
}

void e_col(row & r, const mat & v, size_t j)
{
	r.resize(v.size());
	for (size_t i = 0; i < r.size(); ++i)
		r[i] = v[i][j];
}

void print_ans(size_t i, const row & r)
{
	cout << "Case #" << (i + 1) << ":";
	for (auto x : r)
		cout << " " << x;
	cout << endl;
}

bool f_mat(const mat & f, const mat & r, size_t l)
{

	
	for (; l < r.size(); l += 2) {
		size_t t = l / 2;
		if (f_row(f, t, r[l]) && f_col(f, t, r[l+1]))
			continue;
		if (f_row(f, t, r[l+1]) && f_col(f, t, r[l]))
			continue;
	    return false;
	}
	return true;
}

int main()
{
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		size_t n; cin >> n;
	    mat v(2 * n - 1, vector<int>(n));
		for (size_t i = 0; i + 1 < 2 * n; ++i)
			for (size_t j = 0; j < n; ++j)
				cin >> v[i][j];
	    mat r; partition(r, v);
		mat f(n, row(n, -1)); size_t k = -1;
		//print_mat(f);
		for (size_t j = 0; j < r.size(); j += 2) {
			size_t i = j / 2;
			const row & x = r[j], & y = r[j+1];
			//cout << "-------------------" << endl;
			//print_row(x); print_row(y);
			//cout << endl;
		    if (x[0] < 0 || y[0] < 0)
				k = i;
			if (f_row(f, i, x) && f_col(f, i, y)) {
				row u, v;
				e_row(u, f, i);
				e_col(v, f, i);
				
				c_row(f, i, x);
				c_col(f, i, y);

				if (!f_mat(f, r, j + 2)) {
					c_row(f, i, u, true);
					c_col(f, i, v, true);
					c_row(f, i, y);
					c_col(f, i, x);
				}
			}
			else {
				assert(f_row(f, i, y));
				assert(f_col(f, i, x));
				c_row(f, i, y);
				c_col(f, i, x);
			}
			
		}
		assert(k != -1);
		row x, y;
		e_row(x, f, k);
		e_col(y, f, k);
		print_ans(_, (r[k << 1] == x) ? y : x);
	}
	return 0;
}
