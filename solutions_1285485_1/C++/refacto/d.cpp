#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <memory>
#include <assert.h>



#ifdef _DEBUG

	inline void assert_false_plus(const std::string & message)
	{message;
 		assert(false);
	}

	inline void assert_false()				{ assert_false_plus(""); }

	#define assert_plus(expr, message)		{ if (!(expr)) assert_false_plus(message); }
	#define assert_(expr)					{ assert_plus(expr, ""); }

#else

	#define assert_false_plus(message)
	#define assert_false()
	#define assert_plus(expr, message)
	#define assert_(expr)

#endif


int pgcd (int a, int b) 
{ 
	if (b == 0) return a; 
	else return pgcd(b, a % b); 
} 






using namespace std;


ifstream fin("in.txt");
ofstream fout("out.txt");




const int MAX_D = 50;


struct VectInfo
{
	int		resolution;
	double	minDistance;
}

VectInfoMatrix[MAX_D+1][MAX_D+1] = {0};


void initVectInfoMatrix()
{
	for (int x = 0 ; x <= MAX_D ; ++x)
	for (int y = 0 ; y <= MAX_D ; ++y)
		if (x || y)
		{
			const int norm_x = x/pgcd(x, y);
			const int norm_y = y/pgcd(x, y);
			VectInfoMatrix[norm_x][norm_y].resolution = 2 * max(1, norm_x) * max(1, norm_y);
			VectInfoMatrix[norm_x][norm_y].minDistance = sqrt(double(norm_x*norm_x + norm_y*norm_y));
		}
}


struct Cell
{
	enum types {empty = '.', mirror = '#', me = 'X'};

							Cell() : type(empty),
								pAtUp(nullptr), pAtDown(nullptr), pAtLeft(nullptr), pAtRight(nullptr) {}

	template<types t> bool	Is() const				{ return type == t; }

	bool					RayToMe(int x, int y, int dx, int dy, int resolution, int maxSteps) const;

	char					type;

	Cell *					pAtUp;
	Cell *					pAtDown;
	Cell *					pAtLeft;
	Cell *					pAtRight;
};


// TODO refactoring...
bool Cell::RayToMe(int x, int y, int dx, int dy, int resolution, int maxSteps) const
{
	if (Is<me>() && (x == y) && (x == resolution/2)) return true;
	if (maxSteps == 0) return false;

	--maxSteps;

	const int newX = x+dx;
	const int newY = y+dy;

	const bool newXok = (0 <= newX) && (newX <= resolution);
	const bool newYok = (0 <= newY) && (newY <= resolution);
	if (newXok && newYok)
		return RayToMe(newX, newY, dx, dy, resolution, maxSteps);		// step inside this cell

	// change cell unless mirror effect

	if (y == 0)
	{
		if (newXok)				// up
			if (pAtUp->Is<mirror>())
				return RayToMe(newX, y-dy, dx, -dy, resolution, maxSteps);
			else
				return pAtUp->RayToMe(newX, newY+resolution, dx, dy, resolution, maxSteps);
		else if (newX < 0)		// up left
		{
			if (pAtUp->pAtLeft->Is<mirror>())
			{
				if (pAtUp->Is<mirror>())
					if (pAtLeft->Is<mirror>())	return RayToMe(x-dx, y-dy, -dx, -dy, resolution, maxSteps);
					else						return pAtLeft->RayToMe(newX+resolution, y-dy, dx, -dy, resolution, maxSteps);
				else
					if (pAtLeft->Is<mirror>())	return pAtUp->RayToMe(x-dx, newY+resolution, -dx, dy, resolution, maxSteps);
					else						return false;
			}
			else
				return pAtUp->pAtLeft->RayToMe(newX+resolution, newY+resolution, dx, dy, resolution, maxSteps);
		}
		else					// up right
		{
			if (pAtUp->pAtRight->Is<mirror>())
			{
				if (pAtUp->Is<mirror>())
					if (pAtRight->Is<mirror>())	return RayToMe(x-dx, y-dy, -dx, -dy, resolution, maxSteps);
					else						return pAtRight->RayToMe(newX-resolution, y-dy, dx, -dy, resolution, maxSteps);
				else
					if (pAtRight->Is<mirror>())	return pAtUp->RayToMe(x-dx, newY+resolution, -dx, dy, resolution, maxSteps);
					else						return false;
			}
			else
				return pAtUp->pAtRight->RayToMe(newX-resolution, newY+resolution, dx, dy, resolution, maxSteps);
		}
	}
	if (y == resolution)
	{
		if (newXok)				// down
			if (pAtDown->Is<mirror>())
				return RayToMe(newX, y-dy, dx, -dy, resolution, maxSteps);
			else
				return pAtDown->RayToMe(newX, newY-resolution, dx, dy, resolution, maxSteps);
		else if (newX < 0)		// down left
		{
			if (pAtDown->pAtLeft->Is<mirror>())
			{
				if (pAtDown->Is<mirror>())
					if (pAtLeft->Is<mirror>())	return RayToMe(x-dx, y-dy, -dx, -dy, resolution, maxSteps);
					else						return pAtLeft->RayToMe(newX+resolution, y-dy, dx, -dy, resolution, maxSteps);
				else
					if (pAtLeft->Is<mirror>())	return pAtDown->RayToMe(x-dx, newY-resolution, -dx, dy, resolution, maxSteps);
					else						return false;
			}
			else
				return pAtDown->pAtLeft->RayToMe(newX+resolution, newY-resolution, dx, dy, resolution, maxSteps);
		}
		else					// down right
		{
			if (pAtDown->pAtRight->Is<mirror>())
			{
				if (pAtDown->Is<mirror>())
					if (pAtRight->Is<mirror>())	return RayToMe(x-dx, y-dy, -dx, -dy, resolution, maxSteps);
					else						return pAtRight->RayToMe(newX-resolution, y-dy, dx, -dy, resolution, maxSteps);
				else
					if (pAtRight->Is<mirror>())	return pAtDown->RayToMe(x-dx, newY-resolution, -dx, dy, resolution, maxSteps);
					else						return false;
			}
			else
				return pAtDown->pAtRight->RayToMe(newX-resolution, newY-resolution, dx, dy, resolution, maxSteps);
		}
	}
	if (x == 0)					// left
	{
		assert_(newYok);
		if (pAtLeft->Is<mirror>())
			return RayToMe(x-dx, newY, -dx, dy, resolution, maxSteps);
		else
			return pAtLeft->RayToMe(newX+resolution, newY, dx, dy, resolution, maxSteps);
	}
	if (x == resolution)		// right
	{
		assert_(newYok);
		if (pAtRight->Is<mirror>())
			return RayToMe(x-dx, newY, -dx, dy, resolution, maxSteps);
		else
			return pAtRight->RayToMe(newX-resolution, newY, dx, dy, resolution, maxSteps);
	}
	assert_false();
	return false;
}


class Grid
{
public:
							Grid() : m_width(0), m_height(0), m_pMe(nullptr) { }

	void					Reset(int width, int height);
	int						ComputeNbImages() const;

private:
	int						m_width;
	int						m_height;
	vector<Cell>			m_Cells;

	Cell *					m_pMe;

	int						m_D;

	Cell *					GetCell(int x, int y)			{ assert_(0 <= x && x < m_width); assert_(0 <= y && y < m_height); return &m_Cells[y*m_width + x]; }
	const Cell *			GetCell(int x, int y) const 	{ assert_(0 <= x && x < m_width); assert_(0 <= y && y < m_height); return &m_Cells[y*m_width + x]; }

	friend istream & operator >>(istream &, Grid &);
};


void Grid::Reset(int width, int height)
{
	m_width = width;
	m_height = height;

	m_Cells.clear();
	m_Cells.resize(height*width);

	for (int y = 0 ; y < height ; ++y)
	for (int x = 1 ; x < width ; ++x)
	{
		GetCell(x, y)->pAtLeft = GetCell(x-1, y);
		GetCell(x-1, y)->pAtRight = GetCell(x, y);
	}
	for (int x = 0 ; x < width ; ++x)
	for (int y = 1 ; y < height ; ++y)
	{
		GetCell(x, y)->pAtUp = GetCell(x, y-1);
		GetCell(x, y-1)->pAtDown = GetCell(x, y);
	}
}


int Grid::ComputeNbImages() const
{
	int cpt = 0;

	for (int dy = -MAX_D ; dy <= +MAX_D ; ++dy)
	for (int dx = -MAX_D ; dx <= +MAX_D ; ++dx)
		if (dx || dy)
		{
			const VectInfo & VectInf = VectInfoMatrix[abs(dx)][abs(dy)];
			if (VectInf.minDistance == 0) continue;		// dx/dy can be simplifed

			if (VectInf.minDistance <= m_D)
			{
				int maxSteps = static_cast<int>((m_D / VectInf.minDistance) * VectInf.resolution);
				if (m_pMe->RayToMe(VectInf.resolution/2+dx, VectInf.resolution/2+dy, dx, dy, VectInf.resolution, maxSteps-1))
					++cpt;
			}
		}


	return cpt;
}

istream& operator >>(istream & iStream, Grid & grid)
{
	string line;

	int H, W, D;
	fin >> H >> W >> D;
	grid.Reset(W, H);
	grid.m_D = D;

	for (int y = 0 ; y < H ; ++y)
	{
		string line;
		iStream >> line;
		assert_(line.length() == W);
		for (int x = 0 ; x < grid.m_width ; ++x)
		{
			Cell * pCell = grid.GetCell(x, y);
			const char c = line[x];
			if (c == Cell::me) grid.m_pMe = pCell;
			pCell->type = c;
		}
	}

	return iStream;
}


int solveTest(int t)
{
	int res = 0;

	Grid grid;
	fin >> grid;

	return grid.ComputeNbImages();
}




int main()
{
	initVectInfoMatrix();

	assert_plus(fin, "could not open input file");
	assert_plus(fout, "could not create output file");

	string s;
	int T;
	fin >> T;
	getline(fin, s);
	for (int t = 1 ; t <= T ; ++t)
		fout << "Case #" << t << ": " << solveTest(t) << endl;

	return 0;
}

