#include <stdio.h>
#include <stdlib.h>
#include <share.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
using namespace std::tr1;

const unsigned int MAX_LINE = 1050000;

class Kid
{
public:
	Kid(int num) { bff = NULL; used = 0; id = num; }
	int id;
	Kid* bff;
	int used;
	vector<Kid*> loveMe;
};

vector<Kid*> kids;
vector<int> best;
Kid* startKid;

int DoSearch(Kid* currKid, Kid* prevKid)
{
	if (currKid->used)
	{
		if (currKid == startKid)
			return 0;

		if (prevKid && (prevKid == currKid->bff))
		{
			for (int i = 0; i < prevKid->loveMe.size(); i++)
				if ((prevKid->loveMe[i] != startKid) && !prevKid->loveMe[i]->used)
					return 1;
			return 0;
		}

		return -1;
	}

	int doCount = 0;
	currKid->used = 1;
	int searchRes = DoSearch(currKid->bff, currKid);
	currKid->used = 0;
	return searchRes < 0 ? -1 : 1 + searchRes;
}

void main(int argc, char *argv[])
{
	char* fileName = "input\\C-small-attempt0.in";
	char* fileOutName = "output\\C-small-attempt0.out";
	//char* fileName = "input\\B-large.in";
	//char* fileOutName = "output\\B-large.out";
	FILE* filePtr = _fsopen(fileName, "r", _SH_DENYNO);
	FILE* fileOutPtr = _fsopen(fileOutName, "w", _SH_DENYNO);
	if (!filePtr || !fileOutPtr)
	{
		printf("File not found\n");
		return;
	}

	char* currStr = (char*)malloc(MAX_LINE);
	fgets(currStr, MAX_LINE, filePtr);
	int numCases = atoi(currStr);
	for (int tt = 0; tt < numCases; tt++)
	{
		fgets(currStr, MAX_LINE, filePtr);
		currStr[strcspn(currStr, "\r\n")] = 0;

		int numStudents = atoi(currStr);
		kids.clear();
		kids.resize(numStudents + 1);
		for (int i = 1; i <= numStudents; i++)
			kids[i] = new Kid(i);

		fgets(currStr, MAX_LINE, filePtr);
		currStr[strcspn(currStr, "\r\n")] = 0;

		char* parseContext = NULL;
		char* currNumAsStr;
		char* currParse = currStr;
		int inx = 1;
		
		while (currNumAsStr = strtok_s(currParse, " ", &parseContext))
		{
			int BFF = atoi(currNumAsStr);
			Kid* currKid = kids[inx];
			Kid* bffKid = kids[BFF];
			bffKid->loveMe.push_back(currKid);
			currKid->bff = bffKid;
			
			currParse = NULL;
			inx++;
		}

		best.clear();
		best.resize(numStudents);

		int best = 0;
		for (int i = 1; i <= numStudents; i++)
		{
			startKid = kids[i];
			int result = DoSearch(startKid, NULL);
			if (result > best)
				best = result;
		}

		fprintf(fileOutPtr, "Case #%d: %d\n", tt + 1, best);
	}
	fflush(fileOutPtr);
	fclose(fileOutPtr);
	fclose(filePtr);
}