#include <iostream>
#include <fstream>
#include <map>
#include <string.h>

int n;
long long num[500];
struct T {
	T() {};
	T(const char* p) { memcpy(data, p, 64); }
	char data[64];
};
std::map<long long, T> hist;
long long total =0;
char pos[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

void init() {
}

void display(char* a, char* b) {
	std::cout << "\n";
	for(int i =0; i < n;++i) {
		if(a[i/8] & pos[i%8]) {
			std::cout << num[i] << " ";
		}
	}
	std::cout << "\n";
	for(int i =0; i < n;++i) {
		if(b[i/8] & pos[i%8]) {
			std::cout << num[i] << " ";
		}
	}
	std::cout << "\n";
}
void display_rev(char* a, char* b) {
	std::cout << "\n";
	for(int i =0; i < n;++i) {
		if(!(a[i/8] & pos[i%8])) {
			std::cout << num[i] << " ";
		}
	}
	std::cout << "\n";
	for(int i =0; i < n;++i) {
		if(b[i/8] & pos[i%8]) {
			std::cout << num[i] << " ";
		}
	}
	std::cout << "\n";
}
bool calc_val(int r, int s, long long res, char* d) {
	r -=1;
	char m[64];
	memcpy(m ,d, 64);
	for(int i = s;i <n - r;++i) {
		m[i/8] ^= pos[i%8];
		res += num[i];
		if(r ==0) {
			if(hist.find(res) != hist.end()) {
				display(m, hist[res].data);
				return true;
			}
			else if(hist.find(total - res) != hist.end()) {
				display_rev(m, hist[total - res].data);
				return true;
			}
			else {
				hist[res] = T(m);
			}
		}
		else {
			if(calc_val(r, i+ 1, res, m))
				return true;
		}
		m[i/8] ^= pos[i%8];
		res -= num[i];
	}
	return false;
}
void solve(int c) {
	hist.clear();
	total =0;
	for(int i =0; i < n;++i) 
	{
		total += num[i];
	}
	std::cout << "Case #" << c << ": ";
	char d[64];
	memset(d, 0, 64);
	for(int s = 1; s <=n/2;++s) {
		if(calc_val(s, 0, 0, d))
		{
			return;
		}
	}
	std::cout << "Impossible" << std::endl;
}
int main(int argc , char** argv)
{
	init();
	std::ifstream in(argv[1]);
	int count;
	in >> count;
	for(int i = 1; i <=count;++i) 
	{
		in >> n;
		for(int j =0; j < n;++j) {
			in >> num[j];
		}
		solve(i);
	}
	return 0;
}

