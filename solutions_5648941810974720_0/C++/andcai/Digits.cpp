#include <fstream>
#include <cstring>

using namespace std;

int main(){
	ifstream fin ("A-small-attempt0.in");
	ofstream fout ("A-output.txt");
	int T;
	char S[2001];
	fin >> T;
	for(int i = 1; i <= T; i++){
		fin >> S;
		int s[27] = {0};
		for(int x = 0; x < strlen(S); x++){
			s[S[x]-'A']++;
		}
		int d[10] = {0};
		d[4] = s['U'-'A'];
		d[5] = s['F'-'A']-d[4];
		d[0] = s['Z'-'A'];
		d[6] = s['X'-'A'];
		d[2] = s['W'-'A'];
		d[1] = s['O'-'A']-d[0]-d[2]-d[4];
		d[7] = s['S'-'A']-d[6];
		d[8] = s['G'-'A'];
		d[3] = s['H'-'A']-d[8];
		d[9] = s['I'-'A']-d[5]-d[6]-d[8];
		fout << "Case #" << i << ": ";
		for(int x = 0; x < 10; x++){
			for(int y = 0; y < d[x]; y++){
				fout << x;
			}
		}
		fout << '\n';
	}
	return 0;
}
