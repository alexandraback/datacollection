
#define PROBLEM_NAME "B"
#define PROBLEM_SMALL_INPUT "-small-attempt0"
#define PROBLEM_LARGE_INPUT "-large"

#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int get_board(int r, int c, int N, const vector<int*>& papers, const vector<int>& row, const vector<int>& col)
{
	if (row[r] != -1)
		return papers[row[r]][c];
	else if (col[c] != -1)
		return papers[col[c]][r];
	else
		return 0;
}

bool can_put_line_row(int i, int r, int N, const vector<int*>& papers, const vector<int>& row, const vector<int>& col)
{
	int* line = papers[i];

	for (int c=0; c<N; ++c)
	{
		int val = get_board(r, c, N, papers, row, col);
		if (val == 0)
			continue;
		if (val != line[c])
			return false;
	}
	return true;
}

bool can_put_line_col(int i, int c, int N, const vector<int*>& papers, const vector<int>& row, const vector<int>& col)
{
	int* line = papers[i];

	for (int r=0; r<N; ++r)
	{
		int val = get_board(r, c, N, papers, row, col);
		if (val == 0)
			continue;
		if (val != line[r])
			return false;
	}
	return true;
}

void print(int idx, int N, const vector<int*>& papers, const vector<int>& row, const vector<int>& col)
{
	//int* arr = new int[N*2];
	//for (int i=0; i<N*2; ++i)
	//	arr[i] = 0;
	//for (int r=0; r<N; ++r)
	//{
	//	for (int c=0; c<N; ++c)
	//	{
	//		int val = get_board(r, c, N, papers, row, col);
	//		arr[r*N + c] = val;
	//	}
	//}

	for (int r=0; r<N; ++r)
	{
		for (int c=0; c<N; ++c)
		{
			int val = get_board(r, c, N, papers, row, col);
			char str[256];
			sprintf_s(str, "%5d", val);

			cout << str;
		}
		cout << endl;
	}

	cout << "------------" << endl;
}

struct config
{
	vector<int> row, col;
};

bool put_line(int i, int N, const vector<int*>& papers, config& cfg)
{
	print(i, N, papers, cfg.row, cfg.col);

	if (i >= N)
		return true;

	for (int r = 0; r < N; ++r)
	{
		if (can_put_line_row(i, r, N, papers, cfg.row, cfg.col))
		{
			config newcfg = cfg;
			newcfg.row[r] = i;
			if (put_line(i+1, N, papers, newcfg))
			{
				return true;
			}
		}
	}
	for (int c = 0; c < N; ++c)
	{
		if (can_put_line_col(i, c, N, papers, cfg.row, cfg.col))
		{
			config newcfg = cfg;
			newcfg.col[c] = i;
			if (put_line(i+1, N, papers, newcfg))
			{
				return true;
			}
		}
	}
	return false;
}

class sorter1
{
	int N;
public:
	sorter1(int N_) : N(N_) {}

	bool operator()(const int* left, const int* right)
	{
		return left[0] > right[0];
	}
};


bool is_valid(int c, const string& C)
{
	string CC = C;
	while (!CC.empty())
	{
		char ch = CC[CC.size()-1];
		if (ch != '?')
		{
			if ('0' + (c % 10) != ch)
				return false;
		}
		c = c / 10;
		CC.pop_back();
	}
	return true;
}


string print(int c, size_t count)
{
	stringstream oss;
	for (size_t i=0; i<count; ++i)
	{
		oss << (char) ('0' + c % 10);
		c /= 10;
	}
	string s = oss.str();
	reverse(s.begin(), s.end());
	return s;
}

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		string C, J;
		fin >> C >> J;

		__int64 minC = 1000, minJ = 1000;
		int min_diff = 2000;

		int count = (C.size() == 3) ? 1000 : ((C.size() == 2) ? 100 : 10);

		for (int c=0; c<count; ++c)
		{
			for (int j=0; j<count; ++j)
			{
				if (!is_valid(c, C))
					continue;
				if (!is_valid(j, J))
					continue;
				if (abs(c - j) < min_diff)
				{
					minC = c;
					minJ = j;
					min_diff = (int)abs(c - j);
				}
			}
		}

		fout << "Case #" << cases << ": " << print(minC, C.size()) << " " << print(minJ, C.size()) << endl;
	}

	return 0;
}
