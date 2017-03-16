# include <fstream>
# include <iostream>

# define cout fout
using namespace std;

int main()
{
	ifstream fin ("f.in");
	ofstream fout ("f.out");
	
	int T, A, B, K;
	
	fin>>T;
	
	for(int t=1;t<=T;++t) {
		fin>>A>>B>>K;
		
		int sol = 0;
		for(int a=0;a<A;++a)
			for(int b=0;b<B;++b)
				if ((a&b) < K)
					++sol;
					
		cout<<"Case #"<<t<<": "<<sol<<"\n";
	}
	
	return 0;
}
