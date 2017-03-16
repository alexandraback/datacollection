///////////////////////////////////////////////////////////////////////////////
// TESTING PARAMETERS
const char* FILENAME="C%d.in";
int FILE_FROM = 0;
int FILE_TO = 0;

#include <assert.h>
#include <vector>
#include <algorithm>
#include <memory>

template <class T>
inline const T& min(const T& a,const T& b)
{
	return (a < b)? a : b ;
}

template <class T>
inline const T& max(const T& a,const T& b)
{
	return (a > b)? a : b ;
}

const bool OUT_FILE = true;
FILE *FILE_OUT;

///////////////////////////////////////////////////////////////////////////////

void ProcessFile(FILE* fin)
{
	const int MAX_C = 50;
	const char padding_star[MAX_C+1]="**************************************************";
	const char padding_dot[MAX_C+1]="..................................................";
	int T;
	fscanf(fin, "%d", &T);
	for (int test_case=0; test_case<T; ++test_case)
	{
		int R, C, M;
		fscanf(fin, "%d %d %d", &R, &C, &M);
		std::vector<int> mines_in_rows;
		mines_in_rows.resize(R);
		bool found_solution = true;
		if (M==R*C-1) {
			for (int row=0; row<R; ++row)
				mines_in_rows[row] = row==R-1 ? C-1 : C;
		} else if (R==1) {
			mines_in_rows[0] = M;
		} else if (C==1) {
			for (int row=0; row<M; ++row)
				mines_in_rows[row] = 1;
		} else {
			found_solution = false;
			for (int mines_in_last_line = 0; mines_in_last_line<=C && M>=mines_in_last_line*R; ++mines_in_last_line )
			{
				int mines_left_in_other_rows = M-2*mines_in_last_line;
				int mines_to_remove = (R-2)*C-mines_left_in_other_rows;
				if (mines_to_remove>=0)
				{
					int remove_double_mines = min(mines_to_remove/2, R-2);
					int full_lines = R-2-remove_double_mines;
					mines_to_remove -= remove_double_mines*2;
					if (mines_to_remove<=0 || remove_double_mines>0)
					{
						// we have to remove mines_to_remove in remove_double_mines rows
						int highest_value = remove_double_mines ? C-2-mines_to_remove/remove_double_mines : 0;
						int higher_lines = remove_double_mines ? remove_double_mines-mines_to_remove%remove_double_mines : 0;

						if ((R-2-full_lines-higher_lines<=0 || highest_value-1>=mines_in_last_line) && (higher_lines<=0 || highest_value>=mines_in_last_line))
						{
							for (int row=0; row<R; ++row)
							{
								if (row<full_lines)
									mines_in_rows[row]=C;
								else if (row<full_lines+higher_lines)
									mines_in_rows[row]=highest_value;
								else if (row<R-2)
									mines_in_rows[row]=highest_value-1;
								else
									mines_in_rows[row]=mines_in_last_line;
							}
							assert(full_lines*C+higher_lines*highest_value+(R-2-full_lines-higher_lines)*(highest_value-1)==mines_left_in_other_rows);
							found_solution = true;
							break;
						}
					}
				}

				// skip C-1
				if (mines_in_last_line==C-2)
					++mines_in_last_line;
			}
		}
		if (found_solution) {
			fprintf(FILE_OUT, "Case #%d:\n", test_case+1);
			int mines_check = M;
			for (int row=0; row<R; ++row)
			{
				if (row == R-1)
					fprintf(FILE_OUT, "%.*s%.*sc\n", mines_in_rows[row], padding_star, C-mines_in_rows[row]-1, padding_dot);
				else
					fprintf(FILE_OUT, "%.*s%.*s\n", mines_in_rows[row], padding_star, C-mines_in_rows[row], padding_dot);
				mines_check -= mines_in_rows[row];
			}
			assert(mines_check == 0);
		} else
		{
			fprintf(FILE_OUT, "Case #%d:\nImpossible\n", test_case+1);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	char fileName[256];
	printf ("Which file: ");
	fgets ( fileName, 256, stdin );
	if (fileName[0]>13)
	{
		int i = atoi (fileName);
		FILE_FROM = FILE_TO = i;
	}
	for (int file_from=FILE_FROM; file_from<=FILE_TO; ++file_from)
	{
		sprintf(fileName, FILENAME, file_from);
		FILE *fin = fopen(fileName, "r");
		if (!fin)
		{
			printf("!!! CANNOT INF FILE %s", fileName);
			continue;
		} else {
			printf("Processing file: %s ...\n", fileName);
		}
		if (OUT_FILE)
		{
			char fileNameOut[256];
			sprintf(fileNameOut, "%s.out", fileName);
			FILE_OUT = fopen(fileNameOut, "w");
		} else
		{
			FILE_OUT = stdout;
		}
		ProcessFile(fin);
		fclose(fin);
		if (OUT_FILE)
			fclose(FILE_OUT);
	}
	printf("\nREADY!!!\n");
	getc(stdin);
	return 0;
}
