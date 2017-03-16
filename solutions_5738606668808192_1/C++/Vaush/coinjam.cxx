#include <fstream>
#include <iostream>
using namespace std;
typedef unsigned long long int ulli;
ofstream out("output");
ifstream in("input");
void printBinary(ulli a){
	while(a > 0){
		out << (a & 1);
		a = a >> 1;
	}
}

bool check(ulli a, int base){
	ulli num = 0;
	ulli mult = 1;
	while(a > 0){
		int c = (a&1);
		a = a >> 1;
		num += mult * (c);
		mult *= base;
	}
	return (num % (base+1) == 0);
}
int main(int argc, char **argv)
{
	
	unsigned int n,j;
	unsigned int t;
	in >> t >> n >> j;
	out << "Case #1:" << endl;;
	if(n == 32){
		unsigned int cnt = 0;
		for(ulli i = 715858895; i <= 1431618553; i+=2){
			if(!check(i*3, 3)) continue;
			printBinary(i * 3);
			out << " 3 4 5 6 7 8 9 10 11" << endl;
			cnt++;
			if(cnt == j) break;
		}
	}else{
		unsigned int cnt = 0;
		for(ulli i = 10925; i <= 21845 ; i+=2){
			if(!check(i*3, 3)) continue;
			printBinary(i * 3);
			out << " 3 4 5 6 7 8 9 10 11" << endl;
			cnt++;
			if(cnt == j) break;
		}
	}
	return 0;
}

