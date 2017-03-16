#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>

void init() {
}
void solve(int c, int n, double* s) {
	double total = 0;
	for(int i =0; i < n; ++i) {
		total += s[i];
	}
	double min_avg = (total * 2) / double(n);

	double extras =0;
	int e_c = 0;
	for(int i =0; i < n;++i) {
		if(min_avg <=s[i]) {
			extras += s[i];
			e_c +=1;
		}
	}
	min_avg = (total* 2 - extras )  / double(n- e_c);
	std::cout << "Case #" << c << ": ";
	for(int i =0; i < n;++i) {
		if(min_avg <=s[i]) {
			printf("%f ", 0.0);
		}
		else {
			printf("%f ", (min_avg - s[i])* 100 / total);
		}
	}
	std::cout << "\n";
}
int main(int argc , char** argv)
{
	init();
	double scores[200];
	std::ifstream in(argv[1]);
	int count;
	in >> count;
	for(int i = 1; i <=count;++i) 
	{
		int num;
		in >> num;
		for(int j =0; j < num;++j) {
			in >> scores[j];
		}
		solve(i, num, scores);
	}
	return 0;
}

