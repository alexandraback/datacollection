#include<iostream>
#include<vector>

struct lawn {
	std::vector<std::vector<int>> L;
};

int doit(const lawn P)
{
	const int Y = P.L[0].size();
	const int X = P.L.size();
	std::cerr << X << " " << Y << "\n";
	for (int i=0; i<Y; i++)
		for (int j=0; j<X; j++)
		{
			if (P.L[j][i]>100 || P.L[j][i]<1)
				return 0;
			
			bool tC, tL;
			tC = tL = 1;
			const int h = P.L[j][i];
			for (int k=0; k<Y; k++)
				if (P.L[j][k]>h)
					tC = 0;
			for (int k=0; k<X; k++)
				if (P.L[k][i]>h)
					tL = 0;
			if (tC==0 && tL==0)
				return 0;
		}
	return 1;
}


std::vector<int> read()
{
	std::vector<int> R;
	
	int T;
	std::cin >> T;
	for (int i=0; i<T; i++)
	{
		int N,M;
		
		std::cin >> N >> M;
		lawn L;
		L.L = std::vector<std::vector<int>>(M, std::vector<int>(N));
		for (int j=0; j<N; j++)
			for (int k=0; k<M; k++)
				std::cin >> L.L[k][j];
		
		R.push_back(doit(L));
		std::cerr << "done " << i << "\n";
	}
	return R;
}

void output(const std::vector<int>& R)
{
	for (int i=0; i<R.size(); i++)
	{
		if (R[i]==0)
			std::cout << "Case #" << i+1 << ": NO\n";
		if (R[i]==1)
			std::cout << "Case #" << i+1 << ": YES\n";
	}
}

int main(int argc, char* argv[])
{
	const auto R = read();
	output(R);
}
