#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<cassert>

typedef unsigned int uint;
typedef uint resType;

struct tribe {
	int d, n, w, e, s, dd, dp, ds;
};

struct prob {
	std::vector<tribe> T;
};

int t2(int I)
{
	return I*2;
}

resType doit(const prob P)
{
	resType R = 0;
	
	struct attack {
		int day, w, e, s;
	};
	std::vector<attack> ATT;
	
	for (int i=0; i<P.T.size(); i++)
	{
		const tribe& T = P.T[i];
		for (int j=0; j<T.n; j++)
		{
			attack A;
			A.day = T.d + j*T.dd;
			A.w = T.w + j*T.dp;
			A.e = T.e + j*T.dp;
			A.s = T.s + j*T.ds;
			ATT.push_back(A);
		}
	}
	
	std::sort(ATT.begin(), ATT.end(), [](const attack& a, const attack& b){return a.day<b.day;});
	
	
	
	for (int i=0; i<ATT.size(); i++)
	{
		const attack& A = ATT[i];
		assert(A.e>=A.w);
		std::vector<int> wS(t2(A.e)-t2(A.w)+1, 0);
		for (int j=0; j<i; j++)
		{
			const attack& AO = ATT[j];
			if (AO.day==A.day)
				break;
			for (int k=t2(AO.w); k<=t2(AO.e); k++)
				if (k>=t2(A.w) && k<=t2(A.e))
					wS[k-t2(A.w)] = std::max(wS[k-t2(A.w)], AO.s);
		}
		for (int j=0; j<wS.size(); j++)
			if (A.s>wS[j])
			{
				R++;
// 				std::cout << A.day << " " << A.w << " " << A.e << " " << A.s << "\n";
				break;
			}
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
		int N;
		ifs >> N;
		for (int j=0; j<N; j++)
		{
			tribe T;
			ifs >> T.d >> T.n >> T.w >> T.e >> T.s >> T.dd >> T.dp >> T.ds;
			P.T.push_back(T);
		}
	
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
	std::vector<resType> R = read("C-small-attempt0.in");
	write(R);
}

