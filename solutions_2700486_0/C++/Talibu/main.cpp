#include<iostream>
#include<fstream>
#include<vector>

typedef unsigned int uint;
typedef double resType;

struct prob {
	int N,X,Y;
};


// const int XOFF = 10001;
// const int XSIZE = 20002;
// const int YSIZE = 10001;


const int XOFF = 101;
const int XSIZE = 202;
const int YSIZE = 101;

enum type { STABLE, FREE, LEFT, RIGHT };

type testD(int X, int Y, const std::vector<std::vector<bool>>& DATA)
{
	if (Y==0)
		return STABLE;
	if (DATA[X-1][Y-1] && DATA[X+1][Y-1])
		return STABLE;
	if (DATA[X-1][Y-1])
		return LEFT;
	if (DATA[X+1][Y-1])
		return RIGHT;
	return FREE;
}

type fall(int& X, int& Y, const std::vector<std::vector<bool>>& DATA)
{
	type theType = testD(X,Y,DATA);
	if (theType==STABLE)
		return STABLE;
	if (theType==LEFT)
	{
		X++;
		Y--;
		return testD(X,Y,DATA);
	}
	if (theType==RIGHT)
	{
		X--;
		Y--;
		return testD(X,Y,DATA);
	}
	
	int tl,tc,tr;
	tl = tc = tr = 0;
	for (int i=Y-1; i>=0; i--)
		if (DATA[X][i])
			tc = i+2;
	for (int i=Y-1; i>=0; i--)
		if (DATA[X-1][i])
			tl = i+1;
	for (int i=Y-1; i>=0; i--)
		if (DATA[X+1][i])
			tr = i+1;
		
	if (tl>tr && tl>tc)
	{
		Y = tl;
		return LEFT;
	}
	if (tr>tl && tr>tc)
	{
		Y = tr;
		return RIGHT;
	}
	Y = tc;
	if (Y==0)
		return STABLE;
	return FREE;
}

int SUM = 0;
int ALL = 0;

void simulate(const int N, const int X, const int Y, int tx, int ty, std::vector<std::vector<bool>>& DATA)
{
	if (N==0)
	{
		SUM += DATA[X+XOFF][Y];
		ALL++;
		return;
	}
	
	type theType = fall(tx,ty,DATA);
	if (theType==STABLE)
	{
		DATA[tx][ty] = 1;
		simulate(N-1, X, Y, XOFF, YSIZE-1, DATA);
		DATA[tx][ty] = 0;
		return;
	}
	if (theType==FREE)
	{
		simulate(N, X, Y, tx-1, ty-1, DATA);
		simulate(N, X, Y, tx+1, ty-1, DATA);
		return;
	}
	while (theType!=STABLE)
	{
		theType = fall(tx,ty,DATA);
		DATA[tx][ty] = 1;
		simulate(N-1, X, Y, XOFF,  YSIZE-1, DATA);
		DATA[tx][ty] = 0;
		return;
	}
	return;
}


resType doit(const prob P)
{
// 	resType R = 0;
	
	if (std::abs(P.X)>40 || std::abs(P.Y)>40)
		return 0;
	
	SUM = 0;
	ALL = 0;
	std::vector<std::vector<bool>> DATA(XSIZE,std::vector<bool>(YSIZE));
	simulate(P.N, P.X, P.Y, XOFF,  YSIZE-1, DATA);
	
// 	std::cout << (double)SUM/ALL << "\n";
// 	std::cout << ALL << "\n";
	return (double)SUM/ALL;
}


std::vector<resType> read(std::string fName)
{
	std::vector<resType> R;
	
	std::ifstream ifs(fName);
	int T;
	ifs >> T;
	for (int i=0; i<T; i++)
	{
		prob P;
		ifs >> P.N >> P.X >> P.Y;
		R.push_back(doit(P));
	}
	return R;
}

void write(const std::vector<resType>& R)
{
	for (uint i=0; i<R.size(); i++)
	{
		std::cout << "Case #" << i+1 << ": ";/* << R[i] << "\n";*/
		printf("%.8lf\n", R[i]);
	}
		
}

int main(int argc, char* argv[])
{
	std::vector<resType> R = read("B-small-attempt0.in");
// 	std::vector<resType> R = read("input");
	write(R);
}
