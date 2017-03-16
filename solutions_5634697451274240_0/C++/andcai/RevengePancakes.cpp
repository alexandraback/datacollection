#include <fstream>

using namespace std;

int main(){
	ifstream fin ("B-small-attempt1.in");
	ofstream fout ("B-output.txt");
	int t, x;
	fin >> t;
	char input[100];
	for (int i = 1; i <= t; i++){
		fin >> input;
		int cnt = 0;
		for (x = 1; input[x] == '+' || input[x] == '-'; x++){
			if (input[x] != input[x-1]) cnt++;
		}
		if (input[x-1] == '-')
			cnt++;
		fout << "Case #" << i << ": " << cnt << '\n';
	}
	return 0;
}
