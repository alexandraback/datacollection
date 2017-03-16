#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>

typedef long long ll;
typedef double dub;

using namespace std;


const int SPACESIZE = 1000;
const int SPACEMID = SPACESIZE / 2;
char space[SPACESIZE][SPACESIZE];

class Point
{
public:
	int x;
	int y;
	Point(int q, int w)
	{
	 x = q;
	 y = w;
	}
};

void runTest()
{
	int x, y;
	cin >> x >> y;
	
	for(int i = 0;i < SPACESIZE;i++) {
	for(int j = 0;j < SPACESIZE;j++) {
		space[i][j] = '!';
	}
	}
	space[SPACEMID][SPACEMID] = '0';
	
	list<Point> * nexts = new list<Point>();
	nexts->push_back(Point(SPACEMID, SPACEMID));
	
	int hop = 1;
	int step = 0;
	
	while(space[SPACEMID + x][SPACEMID + y] == '!')
	{
		list<Point> * nn = new list<Point>();
		for(list<Point>::iterator it = nexts->begin();it != nexts->end();it++)
		{
			Point p = *it;
			if(p.y+hop < SPACESIZE && space[p.y+hop][p.x] == '!') {
				space[p.y+hop][p.x] = 'N';
				nn->push_back(Point(p.x, p.y+hop));
			}
			if(p.y-hop >= 0 && space[p.y-hop][p.x] == '!') {
				space[p.y-hop][p.x] = 'S';
				nn->push_back(Point(p.x, p.y-hop));
			}
			if(p.x+hop < SPACESIZE && space[p.y][p.x+hop] == '!') {
				space[p.y][p.x+hop] = 'E';
				nn->push_back(Point(p.x+hop, p.y));
			}
			if(p.x-hop >= 0 && space[p.y][p.x-hop] == '!') {
				space[p.y][p.x-hop] = 'W';
				nn->push_back(Point(p.x-hop, p.y));
			}
		}
		delete nexts;
		nexts = nn;
		hop++;
		step++;
	}
	
	hop--;
	Point at = Point(SPACEMID + x, SPACEMID + y);
	char result[1000];
	int q = 0;
	for(int i = 0;i < step;i++)
	{
		result[q] = space[at.y][at.x];
		q++;
		if(space[at.y][at.x] == 'N')
		{
			at.y -= hop;
		}
		else if(space[at.y][at.x] == 'S')
		{
			at.y += hop;
		}
		else if(space[at.y][at.x] == 'E')
		{
			at.x -= hop;
		}
		else if(space[at.y][at.x] == 'W')
		{
			at.x += hop;
		}
		else {
			cerr << "ERROR" << endl;
		}
		
		hop--;
	}
	while(q > 0)
	{
		q--;
		cout << result[q];
	}
	cout << endl;
	
	/*space[SPACEMID + x-1][SPACEMID + y]= 'X';
	space[SPACEMID + x+1][SPACEMID + y]= 'X';
	space[SPACEMID][SPACEMID] = '0';
	for(int i = -30;i < 20;i++) {
	for(int j = -30;j < 30;j++) {
		cout << space[SPACEMID+j][SPACEMID-i];
	}
	cout << endl;
	}*/
}


int main(int argc, const char * argv[])
{
	(void) argc;
	(void) argv;
	int numTests;
	cin >> numTests;
	srand(time(NULL));
	
	for(int i =0;i < numTests;i++)
	{
		cout << "Case #" << i + 1 << ": ";
		runTest();
	}
}
