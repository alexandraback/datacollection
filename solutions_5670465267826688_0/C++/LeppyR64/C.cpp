#include <iostream>
#include <algorithm>
using namespace std;

int L,X;
string S;

int m[5][5] = {	{0,  0,  0,  0,  0},
				{0,  1,  2,  3,  4},
				{0,  2, -1,  4, -3},
				{0,  3, -4, -1,  2},
				{0,  4,  3, -2, -1} };

			
int main() {
	int T; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cin >> L >> X >> S;
		L *= X;
		string s = S;
		S = "";
		while(X--)
			S += s;
		bool foundi=false,foundj=false,foundk=false;
		int u = 1;
		for(int i = 0; i < S.size(); i++) {
			int v = (S[i]=='1')?1:S[i]-'i'+2;
			if(u < 0)
				u = -1 * m[-u][v];
			else
				u = m[u][v];
			if(!foundi)
				foundi = (u==2);
			else if(!foundj)
				foundj = (u==4);
		}
		if(foundi && foundj && u == -1)
			cout << "Case #" << Z << ": YES" << endl;
		else
			cout << "Case #" << Z << ": NO" << endl;
	}
}