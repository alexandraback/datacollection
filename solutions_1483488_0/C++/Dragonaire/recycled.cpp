#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

ifstream reader("in");
ofstream writer("out");

string cycle(string num){
	return num[num.length() - 1] + num.substr(0, num.length() - 1);
}

char buf[10];

int main(){
	
	int cases;
	reader >> cases;

	for(int _m = 0; _m < cases; ++_m){
		int in, ax; reader >> in >> ax;
		int npairs = 0;

		for(int a = in; a <= ax; ++a){
			ostringstream oss; oss << a;
			string num = oss.str();
			string num2 = num;
			while((num2 = cycle(num2)) != num){
				int b = atoi(num2.c_str());
				if(a < b && b <= ax){
					++npairs;
				}
			}
		}
		writer << "Case #" << _m + 1 << ": " << npairs << endl;
	}

}
