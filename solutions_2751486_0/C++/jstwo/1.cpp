#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>
#include <algorithm>
#include <assert.h>


void solve(std::ifstream& input)
{
	std::string data;
	long long n;
	long long result =0;
	input >> data >> n;
	int start =0;
	for(int i = 0; i < data.size();++i) {
		if(data[i] == 'a' || data[i] == 'i' || data[i] == 'e' || data[i] == 'o' || data[i] == 'u') {
			data[i] = 'a';
		}
		else {
			data[i] = 'b';
		}
	}
	for(int i =0; i < data.size();++i) {
		if((data.size() - i) < n) {
			break;
		}
		bool found = true;
		for(int j = i; j < (i + n);j++) {
			if(data[j] != 'b') {
				found = false;
				break;
			}
		}
		if(found) {
			long long a = i - start + 1;
			long long b = data.size() - i - n + 1;
			result += a * b;
			start = i +1;
		}
	}
	printf("%lld\n", result);
}
int main(int argc, char* argv[]) 
{
	if(argc < 2) {
		std::cerr << "missing input file\n" ;
		return 1;
	}

	std::ifstream in(argv[1]);
	int c ;
	in  >> c;
	for(int i =1; i <=c;++i) {
		printf("Case #%d: ", i);
		solve(in);
	}
	return 0;
}
