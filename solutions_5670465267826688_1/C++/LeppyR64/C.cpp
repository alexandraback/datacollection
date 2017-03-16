#include <iostream>
#include <algorithm>
using namespace std;

int L;
long long X;
string S;
bool foundi, foundj;
int ending;

int m[5][5] = {	{0,  0,  0,  0,  0},
				{0,  1,  2,  3,  4},
				{0,  2, -1,  4, -3},
				{0,  3, -4, -1,  2},
				{0,  4,  3, -2, -1} };

int getending() {
	int u = 1;
	for(int i = 0; i < L; i++) {
		int v = (S[i]=='1')?1:S[i]-'i'+2;
		if(u < 0)
			u = -1 * m[-u][v];
		else
			u = m[u][v];
	}
	return u;
}

void lookij() {
	foundi = false;
	foundj = false;
	int u = 1; 
	for(int x = 0; x < X && x <= 8; x++) {
		for(int i = 0; i < L; i++) {
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
	}
}
			
int main() {
	int T; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cin >> L >> X >> S;
		ending = getending();
		lookij();
		//cout << ending << " " << foundi << " " << foundj << " ";
		if(foundi && foundj && ((ending == -1 && X%2==1) || (abs(ending)>1 && (X-2ll)%4ll==0)))
			cout << "Case #" << Z << ": YES" << endl;
		else
			cout << "Case #" << Z << ": NO" << endl;
	}
}