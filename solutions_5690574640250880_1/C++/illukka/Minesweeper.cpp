// Minesweeper.cpp : Defines the entry point for the console application.
//

#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>

const char inputFile[] = "e:\\tasks\\C-large.in";
const char outputFile[] = "e:\\tasks\\C-large.out";
const char lineBreak[] = "\n";

typedef struct _MemoryFile
{
	size_t length;
	size_t position;
	char* data;
} MemoryFile;

typedef int(*ProcessPart)(char *line, int partIndex, void *param);

int LoadTextFile(const char *path, MemoryFile *file)
{
	FILE *input;
	fpos_t position;
	errno_t err;

	if ((err = fopen_s(&input, path, "rb")) != 0)
	{
		return -1;
	}

	fseek(input, 0, SEEK_END);
	fgetpos(input, &position);
	fseek(input, 0, SEEK_SET);

	//Here we should check length of position..
	file->length = (size_t)position;
	file->data = (char*)malloc(sizeof(char)* (file->length + 1));

	fread(file->data, 1, file->length, input);
	file->data[file->length] = 0;

	fclose(input);

	return 0;
}

int IterateText(char *text, const char *separator, ProcessPart process, void *param)
{
	char *prevDest = text;
	char *dest = text;
	int itemIndex = 0;
	int sepLength = strlen(separator);
	char storedCharacter;
	int getNextLine = 0;

	do
	{
		dest = strstr(prevDest, separator);

		if (dest != NULL)
		{
			storedCharacter = *dest;
			*dest = 0;
		}
		else
		{
			storedCharacter = 0;
		}

		getNextLine = process(prevDest, itemIndex++, param);

		if (storedCharacter)
		{
			*dest = storedCharacter;
		}

		prevDest = dest + sepLength;
	} while (dest != NULL && getNextLine == 0);

	return itemIndex;
}

int WriteOut(const char *path, const char *text, int append)
{
	FILE *output;

	if (append)
	{
		if (fopen_s(&output, path, "ab"))
		{
			return -1;
		}
	}
	else
	{
		if (fopen_s(&output, path, "wb"))
		{
			return -1;
		}
	}

	fwrite(text, sizeof(char), strlen(text), output);
	fclose(output);

	return 0;
}

int GetDoubles(char *line, double *result, int count)
{
	char *nextToken;
	char *tok = strtok_s(line, " ", &nextToken);
	int index = 0;

	while (tok != NULL)
	{
		result[index++] = atof(tok);
		tok = strtok_s(NULL, " ", &nextToken);
	}

	return 0;
}

int Get3Doubles(char *line, double *i1, double *i2, double *i3)
{
	double i[3];
	int ret = GetDoubles(line, i, 3);
	*i1 = i[0];
	*i2 = i[1];
	*i3 = i[2];
	return ret;
}

int GetInts(char *line, int *result, int count)
{
	char *nextToken;
	char *tok = strtok_s(line, " ", &nextToken);
	int index = 0;

	while (tok != NULL)
	{
		result[index++] = atoi(tok);
		tok = strtok_s(NULL, " ", &nextToken);
	}

	return 0;
}

int Get2Ints(char *line, int *i1, int *i2)
{
	int i[2];
	int ret = GetInts(line, i, 2);
	*i1 = i[0];
	*i2 = i[1];
	return ret;
}

int Get3Ints(char *line, int *i1, int *i2, int *i3)
{
	int i[3];
	int ret = GetInts(line, i, 3);
	*i1 = i[0];
	*i2 = i[1];
	*i3 = i[2];
	return ret;
}

void PrintBoard(char **board, int rows, int cols)
{
	char tempBuf[512];

	for (int y = 0; y < rows; y++)
	{
		memcpy(tempBuf, board[y], sizeof(char)* cols);
		tempBuf[cols] = '\n';
		tempBuf[cols + 1] = 0;
		printf(tempBuf);
	}
}

int LineProcessor(char *line, int partIndex, void *param)
{
	static int cmdMode = 0;
	static int caseCount = 0;
	static int caseIndex = 1;
	static int rows; //R
	static int cols; //C
	static int mines; //M
	static int append = 0;

	static char tempBuf[512];

	if (cmdMode == 0)
	{
		caseCount = atoi(line);
		++cmdMode;
	}
	else if (cmdMode == 1)
	{
		Get3Ints(line, &rows, &cols, &mines);

		int mostMinesPossible = 0;

		if (mines < rows * cols - 1)
		{
			if (rows > 2 && cols > 2)
			{
				mostMinesPossible = rows * cols - 4;

				if (mostMinesPossible < 0)
				{
					mostMinesPossible = 0;
				}
			}
			else if (rows == 2 || cols == 2)
			{
				if (mines % 2)
				{
					mostMinesPossible = -1;
				}
				else
				{
					mostMinesPossible = rows * cols - 4;

					if (mostMinesPossible < 0)
					{
						mostMinesPossible = 0;
					}
				}
			}
			else if (rows == 1 || cols == 1)
			{
				mostMinesPossible = rows * cols - 2;

				if (mostMinesPossible < 0)
				{
					mostMinesPossible = 0;
				}
			}
		}

		if (mostMinesPossible != -1 && (mostMinesPossible >= mines || mines == rows * cols - 1))
		{
			char **board = (char**)malloc(sizeof(char*)* rows);

			for (int i = 0; i < rows; i++)
			{
				board[i] = (char*)malloc(sizeof(char)* cols);
				memset(board[i], '.', sizeof(char)* cols);
			}

			int minesLaid = 0;

			if (mines == rows * cols - 1)
			{
				for (int i = 0; i < rows; i++)
				{
					memset(board[i], '*', sizeof(char)* cols);
				}

				minesLaid = rows * cols - 1;
				board[0][0] = 'c';
			}
			else if (rows < 3 && cols < 3)
			{
				//Small boards
				minesLaid = 0;
				board[0][0] = 'c';
			}
			else if (rows < 3)
			{
				board[0][0] = 'c';

				for (int x = cols - 1; x >= 2 && minesLaid < mines; x--)
				{
					for (int y = 0; y < rows; y++)
					{
						board[y][x] = '*';
						++minesLaid;
					}
				}
			}
			else if (cols < 3)
			{
				board[0][0] = 'c';

				for (int y = rows - 1; y >= 2 && minesLaid < mines; y--)
				{
					for (int x = 0; x < cols; x++)
					{
						board[y][x] = '*';
						++minesLaid;
					}
				}
			}
			else if (mines == rows * cols - 6)
			{
				for (int i = 0; i < rows; i++)
				{
					memset(board[i], '*', sizeof(char)* cols);
				}

				minesLaid = cols * rows;

				int x = 0;
				int y = rows / 2;

				board[y][x] = 'c';
				board[y + 1][x] = '.';
				board[y - 1][x] = '.';
				board[y][x + 1] = '.';
				board[y + 1][x + 1] = '.';
				board[y - 1][x + 1] = '.';

				minesLaid -= 6;
			}
			else if (mines == rows * cols - 9)
			{
				for (int i = 0; i < rows; i++)
				{
					memset(board[i], '*', sizeof(char)* cols);
				}

				minesLaid = cols * rows;

				int x = cols / 2;
				int y = rows / 2;

				board[y][x] = 'c';
				board[y + 1][x] = '.';
				board[y - 1][x] = '.';

				board[y][x + 1] = '.';
				board[y + 1][x + 1] = '.';
				board[y - 1][x + 1] = '.';

				board[y][x - 1] = '.';
				board[y + 1][x - 1] = '.';
				board[y - 1][x - 1] = '.';

				minesLaid -= 9;
			}
			else
			{
				int safeSize = (rows - 2) * (cols - 2);

				if (mines <= safeSize || (mines > safeSize && (mines - safeSize) % 2 == 0))
				{
					board[0][0] = 'c';

					//Fill safe area...
					for (int y = rows - 1; y >= 2 && minesLaid < mines; y--)
					{
						for (int x = cols - 1; x >= 2 && minesLaid < mines; x--)
						{
							board[y][x] = '*';
							++minesLaid;
						}
					}

					for (int x = cols - 1; x >= 2 && minesLaid < mines; x--)
					{
						board[0][x] = '*';
						board[1][x] = '*';
						minesLaid += 2;
					}

					for (int y = rows - 1; y >= 2 && minesLaid < mines; y--)
					{
						board[y][0] = '*';
						board[y][1] = '*';
						minesLaid += 2;
					}
				}
				else
				{
					if (caseIndex == 143)
					{
						int a = 3;
					}

					board[0][0] = 'c';

					if (safeSize > 1)
					{
						int yend = 3;
						int xend = 3;

						if (yend == rows)
						{
							--yend;
						}

						if (xend == cols)
						{
							--xend;
						}

						//Fill safe area...
						for (int y = rows - 1; y >= yend && minesLaid < mines; y--)
						{
							for (int x = cols - 1; x >= xend && minesLaid < mines; x--)
							{
								board[y][x] = '*';
								++minesLaid;
							}
						}

						int colFill = 0;
						int rowFill = 0;

						for (int x = cols - 1; x >= xend && minesLaid <= mines - yend; x--)
						{
							board[0][x] = '*';
							board[1][x] = '*';

							if (yend == 3)
							{
								board[2][x] = '*';
								minesLaid += 3;
							}
							else
							{
								minesLaid += 2;
							}

							++colFill;
						}

						for (int y = rows - 1; y >= xend && minesLaid <= mines - xend; y--)
						{
							board[y][0] = '*';
							board[y][1] = '*';

							if (xend == 3)
							{
								board[y][2] = '*';
								minesLaid += 3;
							}
							else
							{
								minesLaid += 2;
							}
							
							++rowFill;
						}

						

						if (minesLaid < mines && mines - minesLaid < 3)
						{
							int left = mines - minesLaid;

							if (colFill < cols - 3)
							{
								if (board[2][cols - 1 - colFill] != '*')
								{
									board[2][cols - 1 - colFill] = '*';
									++minesLaid;
								}
								else
								{
									int a = 3;
								}
							}

							while (minesLaid < mines && rowFill <= rows - 3)
							{
								if (rowFill <= rows - 3)
								{
									if (board[rows - 1 - rowFill][2] != '*')
									{
										board[rows - 1 - rowFill][2] = '*';
										++minesLaid;
										++rowFill;
									}
									else
									{
										rowFill = 1000;
										break;
									}
								}
							}
						}
					}
				}
			}

			if (minesLaid == mines)
			{
				sprintf_s(tempBuf, "Case #%d:\n", caseIndex, mines);
				WriteOut(outputFile, tempBuf, append);
				append = 1;

				for (int i = 0; i < rows; i++)
				{
					memcpy(tempBuf, board[i], sizeof(char)* cols);
					tempBuf[cols] = '\n';
					tempBuf[cols+1] = 0;
					WriteOut(outputFile, tempBuf, append);
					append = 1;
				}
			}
			else
			{
				//Impossible..
				//sprintf_s(tempBuf, "Case #%d:\nImpossible  %d %d mines %d \n", caseIndex, rows, cols, mines);
				sprintf_s(tempBuf, "Case #%d:\nImpossible\n", caseIndex);
				WriteOut(outputFile, tempBuf, append);
				append = 1;
			}

			for (int i = 0; i < rows; i++)
			{
				free(board[i]);
			}

			free(board);
		}
		else
		{
			//Impossible..
			//sprintf_s(tempBuf, "Case #%d:\nImpossible  %d %d mines %d \n", caseIndex, rows, cols, mines);
			sprintf_s(tempBuf, "Case #%d:\nImpossible\n", caseIndex);
			WriteOut(outputFile, tempBuf, append);
			append = 1;
		}

		++caseIndex;
	}

	if (caseIndex > caseCount)
	{
		return 1;
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MemoryFile memFile;

	if (LoadTextFile(inputFile, &memFile))
	{
		return -1;
	}

	IterateText(memFile.data, lineBreak, LineProcessor, NULL);
	::free(memFile.data);

	return 0;
}

