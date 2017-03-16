#include <fstream>
#include <iostream>

using namespace std;

int main(){
	ifstream in("input");
	ofstream out("output");
	int times;
	in >> times;
	for(int t = 1; t <= times; t++){
		int k, c, s;
		in >> k >> c >> s;
		if(k == s){
			out << "Case #" << t << ": ";
			for(int i = 1; i < k; i++){
				out << i << " ";
			}
			out << k << endl;
		}
	}
	return 0;
}
