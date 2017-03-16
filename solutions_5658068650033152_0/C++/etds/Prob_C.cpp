
#define PROBLEM_NAME "C"
#define PROBLEM_SMALL_INPUT "-small-attempt0"
#define PROBLEM_LARGE_INPUT "-large"

#include <set>


class Indexer
{
	int N, M;
	int cx, cy;

public:
	int x, y;

	enum
	{
		DOWN_LEFT,
		DOWN_RIGHT,
		UP_RIGHT,
		UP_LEFT,
	} mode;

	Indexer(int n, int m)
	{
		N = n;
		M = m;
		cx = m/2;
		cy = n/2;
		x = cx;
		y = cy;
	}

	bool is_valid()
	{
		return (x >= 0 && x < M && y >= 0 && y < N);
	}

	bool go_next()
	{
		if (x == cx && y == cy)
		{
			--y;
			mode = DOWN_LEFT;
		}
		else
		{
			if (mode == DOWN_LEFT)
			{
				--x;
				++y;
				if (y == cy)
					mode = DOWN_RIGHT;
			}
			else if (mode == DOWN_RIGHT)
			{
				++x;
				++y;
				if (x == cx)
					mode = UP_RIGHT;
			}
			else if (mode == UP_RIGHT)
			{
				++x;
				--y;
				if (y == cy)
					mode = UP_LEFT;
			}
			else if (mode == UP_LEFT)
			{
				--x;
				--y;
				if (x == cx)
				{
					mode = DOWN_LEFT;
					--y;
				}
			}
		}

		return (x >= 0 && x < M && y >= 0 && y < N);
	}
};


class Board
{
	int N, M;

	int* stat;
	enum
	{
		EMPTY = 0,
		ENCLOSED,
		STONE,
	};

public:
	int encloseCount;
	int stoneCount;

	void Print()
	{
		for (int y=0; y<N; ++y)
		{
			for (int x=0; x<M; ++x)
			{
				int v = Get(x, y);
				if (v == EMPTY)
					fout << " ";
				else if (v == ENCLOSED)
					fout << "x";
				else if (v == STONE)
					fout << "@";
			}
			fout << endl;
		}
		fout << "stone : " << stoneCount << ", enclosed : " << encloseCount << endl;
		fout << "---------------" << endl;
	}

	Board(int n, int m)
	{
		N = n;
		M = m;
		encloseCount = 0;
		stoneCount = 0;

		stat = new int [N*M];
		for (int i=0; i<n*m; ++i)
			stat[i] = 0;
	}

	int Get(int x, int y) // x : 0 ~ M-1, y : 0 ~ N-1
	{
		if (x < 0 || y < 0 || x >= M || y >= N)
			return -1;
		return stat[N * x + y];
	}

	void Set(int x, int y, int val)
	{
		stat[N * x + y] = val;
	}

	bool IsEnclosed(int x, int y)
	{
		if (x == 0 || y == 0 || x == M-1 || y == N-1)
			return false;

		if (Get(x-1, y) != 0 && Get(x+1, y) != 0 &&
			Get(x, y-1) != 0 && Get(x, y+1) != 0)
			return true;
		return false;
	}

	bool PutStone(int x, int y)
	{
		if (Get(x,y) == STONE)
			return false;
		Set(x, y, STONE);
		++stoneCount;
		++encloseCount;
		int left = Get(x-1, y);
		if (left == STONE && IsEnclosed(x-1, y))
		{
			Set(x-1, y, ENCLOSED);
			--stoneCount;
		}
		int right = Get(x+1, y);
		if (right == STONE && IsEnclosed(x+1, y))
		{
			Set(x+1, y, ENCLOSED);
			--stoneCount;
		}
		int up = Get(x, y-1);
		if (up == STONE && IsEnclosed(x, y-1))
		{
			Set(x, y-1, ENCLOSED);
			--stoneCount;
		}
		int down = Get(x, y+1);
		if (down == STONE && IsEnclosed(x, y+1))
		{
			Set(x, y+1, ENCLOSED);
			--stoneCount;
		}
		return true;
	}
};


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
		int N, M, K;
		fin >> N >> M >> K;

		Indexer indexer(N, M);
		Board board(N, M);

		int count = 0;
		do
		{
			if (indexer.is_valid())
				board.PutStone(indexer.x, indexer.y);

			//fout << "count : " << count << endl;
			//board.Print();

			if (board.encloseCount >= K)
				break;
			indexer.go_next();
			count++;
		} while (count < N*M);


		fout << "Case #" << cases << ": " << board.stoneCount << endl;
	}

	return 0;
}
