#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>

typedef unsigned int uint;
typedef uint resType;

struct prob {
	int A;
	std::vector<int> M;
};


resType doit(prob P)
{
	const int  N = P.M.size();
	
// 	std::cerr << P.A << "\t|\t";
// 	for (auto& m : P.M)
// 		std::cerr << m << " ";
// 	std::cerr << "\n";
	
	struct op {int ADD, DEL;};
	
	std::vector<op> OP;
	int ADD = 0;
	for (int I = 0; I<N; I++)
	{
		if (P.M[I]>=P.A)
		{
// 			std::cerr << I << " " << P.A << " " << ADD << " " << N-I << " " << (ADD+N-I) << "\n";
			OP.push_back({ADD, N-I});
			if (P.A==1)
				return N;
			ADD++;
			P.A += P.A-1;
			I--;
		}
		else
		{
			P.A += P.M[I];
		}
	}
	OP.push_back({ADD,0});

	
	uint MIN = ~0U;
	for (uint i=0; i<OP.size(); i++)
		if (OP[i].ADD+OP[i].DEL < MIN)
		{
			MIN = OP[i].ADD+OP[i].DEL;
		}
	
// 	std::cerr << "RET " << MIN << "\n";
	return MIN;
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
		int NUM;
		
		ifs >> P.A >> NUM;
		P.M.resize(NUM);
		for (int j=0; j<NUM; j++)
			ifs >> P.M[j];
		
		std::sort(P.M.begin(), P.M.end());
		
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
	std::vector<resType> R = read("A-small-attempt2.in");
// 	std::vector<resType> R = read("input");
	write(R);
}
