#include<iostream>
#include<fstream>
#include<vector>

typedef unsigned int uint;
typedef std::string resType;

struct prob {
	int X,Y;
};

// NSEW
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};  

resType doit(const prob P)
{
	resType R;
	
	int J = 1;
	if (P.X>0)
	{
		std::string X = "EW";
		for (int i=0; i<P.X; i++)
		{
			R+=X;
			J+=2;
		}
		R = R.substr(0, R.length()-1);
		J--;
	}
	else if (P.X<0)
	{
		std::string X = "WE";
		for (int i=0; i<std::abs(P.X); i++)
		{
			R+=X;
			J+=2;
		}
		R = R.substr(0, R.length()-1);
		J--;
	}
	
	const int XJ = J;
	
	if (P.Y>0 && P.Y>=XJ)
	{
		std::string Y = "NS";
		for (int i=0; i<P.Y-XJ+1; i++)
		{
			R+=Y;
			J+=2;
		}
		R = R.substr(0, R.length()-1);
		J--;
	}
	else if (P.Y>0 && P.Y<XJ)
	{
		std::string Y = "SN";
		for (int i=0; i<P.Y; i++)
		{
			R+=Y;
			J+=2;
		}
	}
	else if (P.Y<0 && std::abs(P.Y)>=XJ)
	{
		std::string Y = "SN";
		for (int i=0; i<std::abs(P.Y)-XJ+1; i++)
		{
			R+=Y;
			J+=2;
		}
		R = R.substr(0, R.length()-1);
		J--;
	}
	else if (P.Y<0 && std::abs(P.Y)<XJ)
	{
		std::string Y = "NS";
		for (int i=0; i<std::abs(P.Y); i++)
		{
			R+=Y;
			J+=2;
		}
	}
	
	
// 	std::cout << R << "\n";
// 	std::cout << J << "\n";
	
	return R;
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
		ifs >> P.X >> P.Y;
		
		
		R.push_back(doit(P));
	}
	return R;
}

void write(const std::vector<resType>& R)
{
	for (uint i=0; i<R.size(); i++)
		std::cout << "Case #" << i+1 << ": " << R[i] << "\n";
}

int main(int argc, char* argv[])
{
// 	std::vector<resType> R = read("input");
	std::vector<resType> R = read("B-small-attempt0.in");
	write(R);
}
