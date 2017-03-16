#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

char C[19];
char J[19];
unsigned long long BestC;
unsigned long long BestJ;
unsigned long long diff;

void DFS(int pos, int state){
	if(pos == strlen(C)){
		unsigned long long cC = 0;
		unsigned long long cJ = 0;
		for(int x = 0; x < strlen(C); x++){
			cC *= 10;
			cC += C[x]-'0';
			cJ *= 10;
			cJ += J[x]-'0';
		}
		if(cJ > cC){
			if(diff > cJ - cC || (diff == cJ - cC && cC < BestC) || (diff == cJ - cC && cC == BestC && cJ < BestJ)){
				diff = cJ - cC;
				BestC = cC;
				BestJ = cJ;
			}
		} else {
			if(diff > cC - cJ || (diff == cC - cJ && cC < BestC) || (diff == cC - cJ && cC == BestC && cJ < BestJ)){
				diff = cC - cJ;
				BestC = cC;
				BestJ = cJ;
			}
		}
		return;
	}
	if(state == 0){			// 0: C=J 1: C>J, 2: J>C
		if(C[pos]=='?'){
			if(J[pos]=='?'){
				C[pos] = '0';
				J[pos] = '0';
				DFS(pos+1, 0);
				C[pos] = '1';
				DFS(pos+1, 1);
				C[pos] = '0';
				J[pos] = '1';
				DFS(pos+1, 2);
				C[pos] = '?';
				J[pos] = '?';
			}else{
				C[pos] = J[pos];
				DFS(pos+1, 0);
				if(J[pos]<'9'){
					C[pos] = J[pos]+1;
					DFS(pos+1, 1);
				}
				if(J[pos]>'0'){
					C[pos] = J[pos]-1;
					DFS(pos+1, 2);
				}
				C[pos] = '?';
			}
		}else if(J[pos]=='?'){
			J[pos] = C[pos];
			DFS(pos+1, 0);
			if(C[pos]<'9'){
				J[pos] = C[pos]+1;
				DFS(pos+1, 2);
			}
			if(C[pos]>'0'){
				J[pos] = C[pos]-1;
				DFS(pos+1, 1);
			}
			J[pos] = '?';
		}else{
			if(C[pos]==J[pos])
				DFS(pos+1, 0);
			else if(C[pos]>J[pos])
				DFS(pos+1, 1);
			else
				DFS(pos+1, 2);
		}
	}else if(state == 1){
		bool c, j;
		if(c = (C[pos]=='?'))
			C[pos] = '0';
		if(j = (J[pos]=='?'))
			J[pos] = '9';
		DFS(pos+1, 1);
		if(c)
			C[pos] = '?';
		if(j)
			J[pos] = '?';
	}else{
		bool c, j;
		if(c = (C[pos]=='?'))
			C[pos] = '9';
		if(j = (J[pos]=='?'))
			J[pos] = '0';
		DFS(pos+1, 2);
		if(c)
			C[pos] = '?';
		if(j)
			J[pos] = '?';
	}
}

int main(){
	ifstream fin ("B-large.in");
	ofstream fout ("B-output.txt");
	int T;
	fin >> T;
	int state;
	for(int i = 1; i <= T; i++){
		diff = -1;
		fin >> C;
		fin >> J;
		DFS(0, 0);
		fout << "Case #" << i << ": " << setw(strlen(C)) << setfill('0') << BestC << ' ' << setw(strlen(C)) << setfill('0') << BestJ << '\n';
	}

	return 0;
}
