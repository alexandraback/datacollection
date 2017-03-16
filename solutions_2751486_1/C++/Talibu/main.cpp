#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_set>

typedef unsigned int uint;
typedef long long resType;

struct prob {
	std::string S;
	int N;
};

const std::unordered_set<char> VOC= {'a', 'e', 'i', 'o', 'u'};
bool isVOC(const char C)
{
	return VOC.find(C)!=VOC.end();
}

resType doit(const prob P)
{
	resType R = 0;
	
	std::vector<int> cpos;
	int lpos = -1;
	for (int i=0; i<P.S.length(); i++)
	{
		if (!isVOC(P.S[i]))
		{
			if (i-lpos==P.N)
				cpos.push_back(lpos+1);
			else if (i-lpos>P.N)
			{
				lpos++;
				cpos.push_back(lpos+1);
			}
		}
		else
			lpos = i;
	}	

	if (cpos.size()==0)
		return 0;
	
	R += (cpos[0]+1)*(P.S.length()-(cpos[0]+P.N-1)); 
	for (int i=1; i<cpos.size(); i++)
	{
		long long LL = cpos[i]-cpos[i-1]; 
		long long RR = P.S.length()-(cpos[i]+P.N-1);
		R += LL*RR;
	}
	
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
	
		ifs >> P.S >> P.N;
		
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
// 	std::vector<resType> R = read("A-small-attempt0.in");
	std::vector<resType> R = read("A-large.in");
// 	std::vector<resType> R = read("input");
	write(R);
}
