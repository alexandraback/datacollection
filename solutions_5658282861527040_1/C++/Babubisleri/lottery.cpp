#include<iostream>
#include<fstream>
#include<deque>
#include<map>
#include<iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file;
	ofstream outputFile;
	
	long long A=0, B=0, K=0;
	int intTestCases=0;
	
	outputFile.open(argv[2]);
	file.open(argv[1]);

	if(!file.eof())
	{
		file >> intTestCases;
	}

	for(int t=0; t<intTestCases; ++t)
	{
		file >> A >> B >> K;
		
		long long chances = 0;
		
		if (A<=K || B<=K) {
			chances = A * B;
		} else {
			chances = K * B + (A-K) * K;
			
			for (long long i=K; i<A; ++i) {
				for (long long j=K; j<B; ++j) {
					if((i & j) < K){
						chances++;
					}
				}
			}			
		}
		
		if (t==0) {
			outputFile << "Case #" << t+1 << ": " << chances;
		}else {
			outputFile << "\nCase #" << t+1 << ": " << chances;
		}

	}
}