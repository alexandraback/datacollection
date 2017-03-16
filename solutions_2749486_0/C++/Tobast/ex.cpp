#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct BfsElem {
	BfsElem() {}
	BfsElem(int x, int y, int depth) : x(x),y(y), depth(depth) {}

	int x;
	int y;
	int depth;
};

const int MAX_COORD = 100+20; // SMALL
bool depthOf[2*MAX_COORD+5][2*MAX_COORD+5][500];


inline bool getDepthOf(const int& x, const int& y, const int& depth)
{
	return depthOf[x+MAX_COORD][y+MAX_COORD][depth];
}
inline void setDepthOf(const int& x, const int& y, const int& depth)
{
	depthOf[x+MAX_COORD][y+MAX_COORD][depth] = true;
}

inline bool validPos(const BfsElem& pos)
{
	return (-MAX_COORD <= pos.x && pos.x <= MAX_COORD && -MAX_COORD <= pos.y && pos.y <= MAX_COORD && pos.depth <= 500);
}

void bfs()
{
	queue<BfsElem> toProcess;
	toProcess.push(BfsElem(0,0,0));

	while(!toProcess.empty())
	{
		BfsElem pos=toProcess.front();
		toProcess.pop();

		if(!validPos(pos))
			continue;
		if(getDepthOf(pos.x, pos.y, pos.depth))
			continue;
		setDepthOf(pos.x, pos.y, pos.depth);

		toProcess.push(BfsElem(pos.x+pos.depth+1, pos.y, pos.depth+1));
		toProcess.push(BfsElem(pos.x-pos.depth-1, pos.y, pos.depth+1));
		toProcess.push(BfsElem(pos.x, pos.y+pos.depth+1, pos.depth+1));
		toProcess.push(BfsElem(pos.x, pos.y-pos.depth-1, pos.depth+1));
	}
}

const int NB_DIRS = 4;
const int DIRS[NB_DIRS][2] = { {1,0},{0,1},{-1,0},{0,-1} };
const char DIRS_LETTERS[] = "WSEN";

string solveTest(int x, int y, int depth=-1);
string solveTest(int x, int y, int depth)
{
	if(x==0 && y==0 && depth==0)
		return "";
	
	if(depth == -1)
	{
		for(int cDepth=0; cDepth <= 500; cDepth++)
		{
			string out = solveTest(x,y,cDepth);
			if(!out.empty())
				return out;
		}
		return "ERROR";
	}

	if(!getDepthOf(x,y,depth))
		return "";
	
	for(int dir=0; dir < NB_DIRS; dir++)
	{
		BfsElem nPos(x,y,depth);
		nPos.x += DIRS[dir][0] * depth;
		nPos.y += DIRS[dir][1] * depth;
		nPos.depth -= 1;
		
		if(getDepthOf(nPos.x, nPos.y, nPos.depth))
			return solveTest(nPos.x, nPos.y, nPos.depth)+(DIRS_LETTERS[dir]);
	}
	return "ERROR";
}

int main(void)
{
	bfs();

	int nbTests;
	scanf("%d", &nbTests);
	for(int test=0; test < nbTests; test++)
	{
		int x,y;
		scanf("%d %d", &x, &y);

		printf("Case #%d: %s\n", test+1, solveTest(x,y,-1).c_str());
	}

	return 0;
}

