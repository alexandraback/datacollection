// Cookie.cpp : Defines the entry point for the console application.
//
#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>

const char inputFile[] = "e:\\tasks\\B-small-attempt0.in";
const char outputFile[] = "e:\\tasks\\B-small-attempt0.out";
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

int LineProcessor(char *line, int partIndex, void *param)
{
	static int cmdMode = 0;
	static int caseCount = 0;
	static int caseIndex = 1;
	static double cookieFarmPrize; //C
	static double cookieFarmAdd; //F
	static double cookiesToWin; //X

	static char tempBuf[512];

	if (cmdMode == 0)
	{
		caseCount = atoi(line);
		++cmdMode;
	}
	else if (cmdMode == 1)
	{
		Get3Doubles(line, &cookieFarmPrize, &cookieFarmAdd, &cookiesToWin);

		double cookieCount = 0.0;
		double cookiesPerSecond = 2.0;
		double timeSpent = 0.0;

		while (cookieCount < cookiesToWin)
		{
			double timeToEndWithCurrent = (cookiesToWin - cookieCount) / cookiesPerSecond;
			double timeForNextFarm = cookieFarmPrize / cookiesPerSecond;

			if (timeToEndWithCurrent <= timeForNextFarm)
			{
				//We go all the way...
				timeSpent += timeToEndWithCurrent;
				cookieCount = cookiesToWin;
			}
			else
			{
				timeSpent += timeForNextFarm;
				cookieCount += timeForNextFarm * cookiesPerSecond;

				double timeToEndWithFarm = (cookiesToWin - cookieCount + cookieFarmPrize) / (cookiesPerSecond + cookieFarmAdd);
				timeToEndWithCurrent = (cookiesToWin - cookieCount) / cookiesPerSecond;

				//If we should buy?
				if (timeToEndWithFarm < timeToEndWithCurrent)
				{
					cookieCount -= cookieFarmPrize;
					cookiesPerSecond += cookieFarmAdd;
				}
				else
				{
					//We go all the way...
					timeSpent += timeToEndWithCurrent;
					cookieCount = cookiesToWin;
				}
			}
		}

		sprintf_s(tempBuf, "Case #%d: %0.7f\n", caseIndex, timeSpent);
		WriteOut(outputFile, tempBuf, caseIndex != 1);

		if (++caseIndex > caseCount)
			cmdMode = 33;
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



