#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

ifstream fin("in");
ofstream fout("out");

const int MAXN = 21;
long long nums[MAXN];
long long p3[MAXN];

void print(long long subset) {
	int i=0;
	long long s=subset;
	while(s>0) {
		if(s%3==1)
			fout << nums[i] << " ";
		i++;
		s/=3;
	}
	fout << endl;
	i=0;
	s=subset;
	while(s>0) {
		if(s%3==2)
			fout << nums[i] << " ";
		i++;
		s/=3;
	}
	fout << endl;
}

bool equal(long long subset) {
	int i=0;
	long long s1=0, s2=0;
	while(subset>0) {
		int r = subset%3;
		if(r==1)
			s1 += nums[i];
		else if(r==2)
			s2 += nums[i];
		i++;
		subset /= 3;
	}
	return (s1==s2);
}

int main() {
	p3[0] = 1;
	for(int i=1; i<MAXN; i++)
		p3[i] = p3[i-1]*3;
	
	int T; fin>>T;
	for(int t=1; t<=T; t++) {
		int N; fin>>N;
		for(int i=0; i<N; i++)
			fin>>nums[i];
		bool found = false;
		long long subset=1;
		for(subset=1; subset<p3[N]; subset++) {
			found = equal(subset);
			if(found)
				break;
		}

		fout << "Case #" << t << ":" << endl;
		if(found)
			print(subset);
		else
			fout << "Impossible" << endl;
	}

	return 0;
}




