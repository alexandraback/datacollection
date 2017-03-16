#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int DoInvert(int x, bool invert)
{
	return invert ? -x : x;
}

int debug_case_num = -1;

int main()
{
	ifstream f("B-small-attempt0.in");
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int N;
		cin >> N;
		if (case_num == debug_case_num)
			cerr << "N = " << N << endl;
		vector< vector<int> > H;
		int min_value = 0, min_count = 0;
		int max_value = 0, max_count = 0;
		for (int k = 0; k < (2*N-1); ++k)
		{
			H.push_back(vector<int>());
			for (int i = 0; i < N; ++i)
			{
				int h;
				cin >> h;
				if (case_num == debug_case_num)
					cerr << " " << h;
				H.back().push_back(h);
				if (!min_count || (h < min_value))
					min_value = h, min_count = 1;
				else if (h == min_value)
					++min_count;
				if (!max_count || (h > max_value))
					max_value = h, max_count = 1;
				else if (h == max_value)
					++max_count;
			}
			if (case_num == debug_case_num)
				cerr << endl;
		}

		bool invert = false;
		if (min_count == 1)
		{
			// Missing one of the "minimum" rows. Negate integers so we have two minimum rows.
			for (int k = 0; k < H.size(); ++k)
			{
				vector<int> new_row(N);
				for (int i = 0; i < H[k].size(); ++i)
					new_row[i] = -H[k][N - 1 - i];
				H[k] = new_row;
			}
			min_value = -max_value;
			invert = true;
		}

		vector<int> min_col, min_row;
		vector<int> row_pos(2501, -1), col_pos(2501, -1);
		{
			// cerr << "min_value=" << min_value << endl;
			// for (int k = 0; k < H.size(); ++k) {
			// 	for (int i = 0; i < H[k].size(); ++i)
			// 		cerr << " " << H[k][i];
			// 	cerr << endl;
			// }
			vector< vector<int> > new_H;
			for (int k = 0; k < H.size(); ++k)
			{
				if (H[k][0] == min_value)
				{
					// cerr << "found min row" << endl;
					if (min_row.empty())
						min_row = H[k];
					else
						min_col = H[k];
				}
				else
					new_H.push_back(H[k]);
			}
			H.swap(new_H);
			// cerr << min_row.size() << endl << min_col.size() << endl;
			for (int i = 0; i < N; ++i)
			{
				// cerr << min_row[i];
				row_pos[abs(min_row[i])] = i;
				// cerr << min_col[i];
				col_pos[abs(min_col[i])] = i;
			}
			if (case_num == debug_case_num)
			{
				cerr << "newH" << endl;
				for (int k = 0; k < H.size(); ++k)
				{
					for (int i = 0; i < H[k].size(); ++i)
						cerr << " " << H[k][i];
					cerr << endl;
				}
			}
		}

		int brute_force = 1 << H.size();
		vector< vector<int> > G(N, vector<int>(N));
		vector<int> row_counts(N), col_counts(N);
		vector<int> success;
		for (int trial = 0; trial < brute_force; ++trial)
		{
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					G[i][j] = 0;

			for (int i = 0; i < N; ++i)
			{
				G[i][0] = min_row[i];
				G[0][i] = min_col[i];
				row_counts[i] = 0;
				col_counts[i] = 0;
			}
			row_counts[0] = 1;
			col_counts[0] = 1;

			int k;
			for (k = 0; k < H.size(); ++k)
			{
				if (trial & (1 << k))
				{
					// row
					int j = row_pos[abs(H[k][0])];
					if (j < 0)
						break;
					if (++row_counts[j] > 1)
						break;
					bool okay = true;
					for (int i = 0; i < N; ++i)
					{
						if ((G[j][i] == 0) || (G[j][i] == H[k][i]))
							G[j][i] = H[k][i];
						else
						{
							okay = false;
							break;
						}
					}
					if (!okay)
						break;
				}
				else
				{
					// col
					int j = col_pos[abs(H[k][0])];
					if (j < 0)
						break;
					if (++col_counts[j] > 1)
						break;
					bool okay = true;
					for (int i = 0; i < N; ++i)
					{
						if ((G[i][j] == 0) || (G[i][j] == H[k][i]))
							G[i][j] = H[k][i];
						else
						{
							okay = false;
							break;
						}
					}
					if (!okay)
						break;
				}
			}
			if (k == H.size())
			{
				for (int j = 0; j < N; ++j)
				{
					if (row_counts[j] == 0)
					{
						success.clear();
						for (int i = 0; i < N; ++i)
							success.push_back(G[j][i]);
					}
					if (col_counts[j] == 0)
					{
						success.clear();
						for (int i = 0; i < N; ++i)
							success.push_back(G[i][j]);
					}
				}
			}
		}

		cout << "Case #" << case_num << ":";
		if (!invert)
		{
			for (int i = 0; i < success.size(); ++i)
				cout << " " << success[i];
		}
		else
		{
			for (int i = success.size() - 1; i >= 0; --i)
				cout << " " << (-success[i]);
		}
		cout << endl;
	}
	return 0;
}
