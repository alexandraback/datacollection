
#define PROBLEM_NAME "C"
#define PROBLEM_SMALL_INPUT "-small-attempt8"
#define PROBLEM_LARGE_INPUT "-large"

#include <set>

//bool printDebug = true;
bool printDebug = false;

const int CELL_NULL = 0;
const int CELL_BOMB = 100;
void printMine(int R, int C, int M, int**board);

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		if (printDebug)
			fout << endl;

		int R, C, M;
		fin >> R >> C >> M;

		int** board = new int*[R];
		for (int i=0; i<R; ++i)
			board[i] = new int[C];

		for (int ir = 0; ir<R; ++ir)
		{
			for (int ic = 0; ic<C; ++ic)
				board[ir][ic] = CELL_NULL;
		}

		int bombToPut = mymax(0, mymin((R-2)*(C-2), M));
		int remainedBomb = M - bombToPut;
		bool leftTopCornerPut = true;
		if (remainedBomb % 2 == 1 && bombToPut > 0)
		{
			bombToPut--;
			remainedBomb++;
			leftTopCornerPut = false;
		}

		for (int ir = 0; ir < R-2 && bombToPut > 0; ++ir)
		{
			for (int ic = 0; ic < C-2 && bombToPut > 0; ++ic)
			{
				bombToPut--;
				board[ir][ic] = CELL_BOMB;
			}
		}

		if (remainedBomb == 0)
		{
//continue;
			fout << "Case #" << cases << ":" << endl;
			printMine(R, C, M, board);
			continue;
		}
		if (remainedBomb < 0)
		{
			fout << "Case #" << cases << ":" << endl;
			if (printDebug)
				fout << "########### remainedBome < 0 : " << remainedBomb << endl;
			printMine(R, C, M, board);
			continue;
		}

		if (C - 2 >= 0)
		{
			int rr = 0;
			while (remainedBomb >= 2 && rr <= R - 4)
			{
				board[rr][C-2] = CELL_BOMB;
				board[rr][C-1] = CELL_BOMB;
				remainedBomb -= 2;
				rr++;
			}
		}

		if (R - 2 >= 0)
		{
			int cc = 0;
			while (remainedBomb >= 2 && cc <= C - 4)
			{
				board[R-2][cc] = CELL_BOMB;
				board[R-1][cc] = CELL_BOMB;
				remainedBomb -= 2;
				cc++;
			}
		}

		if (remainedBomb >= 2 && remainedBomb % 2 == 0 && leftTopCornerPut)
		{
			if (R - 3 >= 0 && C - 2 >= 0)
			{
				board[R-3][C-2] = CELL_BOMB;
				board[R-3][C-1] = CELL_BOMB;
				remainedBomb -= 2;
			}
		}

		if (remainedBomb >= 2 && remainedBomb % 2 == 0 && leftTopCornerPut)
		{
			if (R - 2 >= 0 && C - 3 >= 0)
			{
				board[R-2][C-3] = CELL_BOMB;
				board[R-1][C-3] = CELL_BOMB;
				remainedBomb -= 2;
			}
		}

		if (remainedBomb > 0)
		{
			for (int n=0; n<=(R-1)+(C-1) && remainedBomb > 0; ++n)
			{
				int ir = R-1;
				if (n - (R-1) < 0)
					ir += n - (R-1);
				for (; ir >= 0 && n - ir <= C-1 && remainedBomb > 0; --ir)
				{
					int ic = n - ir;
					if (board[ir][ic] == CELL_NULL)
					{
						board[ir][ic] = CELL_BOMB;
						remainedBomb--;
					}
				}
			}
		}

		for (int ir = 0; ir<R; ++ir)
		{
			for (int ic = 0; ic<C; ++ic)
			{
				int val = board[ir][ic];
				if (val == CELL_BOMB)
					continue;
				val = 0;
				for (int iir = -1; iir <= 1; ++iir)
				{
					if (ir + iir > R-1 || ir + iir < 0)
						continue;
					for (int iic = -1; iic <= 1; ++iic)
					{
						if (ic + iic > C-1 || ic + iic < 0)
							continue;

						if (board[ir+iir][ic+iic] == CELL_BOMB)
							val++;
					}
				}
				board[ir][ic] = val;
			}
		}


		bool emptyNeighborExist = true;
		for (int ir = 0; ir<R && emptyNeighborExist; ++ir)
		{
			for (int ic = 0; ic<C && emptyNeighborExist; ++ic)
			{
				int val = board[ir][ic];
				if (val == CELL_BOMB || val == CELL_NULL)
					continue;
				bool emptyNeighborFound = false;
				for (int iir = -1; iir <= 1 && !emptyNeighborFound; ++iir)
				{
					if (ir + iir > R-1 || ir + iir < 0)
						continue;
					for (int iic = -1; iic <= 1; ++iic)
					{
						if (ic + iic > C-1 || ic + iic < 0)
							continue;

						if (board[ir+iir][ic+iic] == CELL_NULL)
						{
							emptyNeighborFound = true;
							break;
						}
					}
				}
				if (!emptyNeighborFound)
				{
					emptyNeighborExist = false;
					if (printDebug)
						fout << "at " << ir << ", " << ic << " with val : " << val << endl;
				}
			}
		}

		if (remainedBomb > 0)
		{
			fout << "Case #" << cases << ":" << endl;
			fout << "Impossible" << endl;
			if (printDebug)
			{
				fout << "#### Remained : " << remainedBomb << endl;
				printMine(R, C, M, board);
			}
		}
		else if (!emptyNeighborExist)
		{
			if (M == R*C - 1)
			{
//continue;
				fout << "Case #" << cases << ":" << endl;
				if (printDebug)
				{
					fout << "#### OneCell" << endl;
				}
				printMine(R, C, M, board);
			}
			else
			{
				fout << "Case #" << cases << ":" << endl;
				fout << "Impossible" << endl;
				if (printDebug)
				{
					printMine(R, C, M, board);
				}
			}
		}
		else
		{
//continue;
			fout << "Case #" << cases << ":" << endl;
			printMine(R, C, M, board);
		}

		//fout << "Case #" << cases << ":" << endl;
		//fout << "Impossible" << endl;
		//fout << "M : " << M << endl;
		//fout << "bombPut : " << bombPut << endl;
		//fout << "R, C : " << R << ", " << C << endl;
		//fout << endl;

		//for (int ir = 0; ir<R; ++ir)
		//{
		//	for (int ic = 0; ic<C; ++ic)
		//	{
		//		int val = board[ir][ic];
		//		if (val == CELL_NULL)
		//			fout << ".";
		//		else if (val == CELL_BOMB)
		//			fout << "*";
		//		else
		//			fout << (char)(val + '0');
		//	}
		//	fout << endl;
		//}

//		fout << "Case #" << cases << ": " << std::fixed << std::setprecision(7) << TimeTotal << endl;
	}

	return 0;
}

void printMine(int R, int C, int M, int**board)
{
	if (printDebug)
		fout << "R, C, M : " << R << " " << C << " " << M << endl;

	int mineCount = 0;
	for (int ir = 0; ir<R; ++ir)
	{
		for (int ic = 0; ic<C; ++ic)
		{
			if (ir == R-1 && ic == C-1)
			{
				if (R*C == M)
				{
					fout << "*";
					mineCount++;
				}
				else
					fout << "c";
			}
			else
			{
				int val = board[ir][ic];
				if (val == CELL_NULL)
					fout << ".";
				else if (val == CELL_BOMB)
				{
					fout << "*";
					mineCount++;
				}
				else
					//fout << (char)(val + '0');
					fout << ".";
			}
		}
		fout << endl;
	}

	if (printDebug)
	{
		if (mineCount != M)
		{
			fout << "########### mine count mismatch : M(" << M << ") vs. mineCount(" << mineCount << ")" << endl;
		}
	}
}

