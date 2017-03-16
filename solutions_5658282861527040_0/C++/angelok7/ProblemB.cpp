#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>N;
	for(n=0;n<N;n++){
		__int64 A,B,K;
		int i,j;
		fin>>A>>B>>K;
		__int64 res = 0;

		for(i=0;i<A;i++){
			for(j=0;j<B;j++){
				if( (i&j) < K)
					res++;
			}
		}
		
		fout<<"Case #"<<n+1<<": "<<res<<endl;
	}
	return 0;
}
