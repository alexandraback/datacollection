#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define abs(X) ((X)<0?-(X):(X))
#define rst(X) memset(X,0,sizeof(X))
#define pb push_back
#define mp make_pair
#define sz(X) ((int)X.size())
#define ff first
#define ss second

char M[5][5];
int TT[2];
bool won(char s){
	if (TT[0]!=-1) M[TT[0]][TT[1]] = s;
	for (int i = 0; i < 4; i++)
		if (M[i][0]==s && M[i][1]==s && M[i][2]==s && M[i][3]==s ||
			M[0][i]==s && M[1][i]==s && M[2][i]==s && M[3][i]==s)
			return true;
	if (M[0][0]==s && M[1][1]==s && M[2][2]==s && M[3][3]==s ||
		M[0][3]==s && M[1][2]==s && M[2][1]==s && M[3][0]==s)
		return true;
	return false;
	
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		for (int j = 0; j < 4; j++)
			scanf("%s", M[j]);
		bool draw = 1;
		TT[0] = -1;
		for (int j = 0; j < 4; j++)
			for (int z = 0; z < 4; z++)
				if (M[j][z]=='.')
					draw = 0;
				else if (M[j][z]=='T')
					TT[0] = j, TT[1] = z;
		printf("Case #%d: ", i+1);
		if (won('X'))
			printf("X won");
		else if (won('O'))
			printf("O won");
		else if (draw)
			printf("Draw");
		else
			printf("Game has not completed");
		printf("\n");
	}
	return 0;
}
