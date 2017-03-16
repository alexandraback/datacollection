#include<iostream>
#include<vector>


int doit(const std::string P)
{
	for (int i=0; i<4; i++)
	{
		bool sameLine = 1;
		char tChar = 'T';
		for (int j=0; j<4; j++)
		{
			const int tIndex = i*4+j; 
			if (!(P[tIndex]==P[i*4] || P[tIndex]=='T'))
				sameLine = 0;
			if (P[tIndex]=='.')
				sameLine = 0;
			if (P[tIndex]!='T')
				tChar = P[tIndex];
		}
		if (sameLine)
			return (tChar=='X') ? 3 : 2;
	}
	for (int i=0; i<4; i++)
	{
		bool sameCol = 1;
		char tChar = 'T';
		for (int j=0; j<4; j++)
		{
			const int tIndex = i+4*j; 
			if (!(P[tIndex]==P[i] || P[tIndex]=='T'))
				sameCol = 0;
			if (P[tIndex]=='.')
				sameCol = 0;
			if (P[tIndex]!='T')
				tChar = P[tIndex];
		}
		if (sameCol)
			return (tChar=='X') ? 3 : 2;
	}
	bool sameDiag = 1;
	char tChar = 'T';
	for (int j=0; j<4; j++)
	{
		const int tIndex = 4*j+j;
		if (!(P[tIndex]==P[0] || P[tIndex]=='T'))
			sameDiag = 0;
		if (P[tIndex]=='.')
			sameDiag = 0;
		if (P[tIndex]!='T')
			tChar = P[tIndex];
	}
	if (sameDiag)
		return (tChar=='X') ? 3 : 2;
	
	sameDiag = 1;
	tChar = 'T';
	for (int j=0; j<4; j++)
	{
		const int tIndex = 4*(j+1)-j-1;
		if (!(P[tIndex]==P[3] || P[tIndex]=='T'))
			sameDiag = 0;
		if (P[tIndex]=='.')
			sameDiag = 0;
		if (P[tIndex]!='T')
			tChar = P[tIndex];
	}
	if (sameDiag)
		return (tChar=='X') ? 3 : 2;
	
	for (int i=0; i<16; i++)
		if (P[i]=='.')
			return 1;
	
	return 0;
}


std::vector<int> read()
{
	std::vector<int> R;
	
	int T;
	std::cin >> T;
	std::string D;
	getline(std::cin, D);
	for (int i=0; i<T; i++)
	{
		std::string P,L;
		for (int j=0; j<4; j++)
		{
			getline(std::cin, L);
			P += L;
		}
		getline(std::cin, L);
// 		std::cin >> p;
		R.push_back(doit(P));
		std::cerr << "done " << i << "\n";
	}
	return R;
}

void output(const std::vector<int>& R)
{
	for (int i=0; i<R.size(); i++)
	{
		if (R[i]==0)
			std::cout << "Case #" << i+1 << ": Draw\n";
		if (R[i]==1)
			std::cout << "Case #" << i+1 << ": Game has not completed\n";
		if (R[i]==2)
			std::cout << "Case #" << i+1 << ": O won\n";
		if (R[i]==3)
			std::cout << "Case #" << i+1 << ": X won\n";
	}
}

int main(int argc, char* argv[])
{
	const auto R = read();
	output(R);
}
