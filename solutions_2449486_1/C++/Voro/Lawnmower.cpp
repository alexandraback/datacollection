#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXN 200

int A[MAXN][MAXN];
pair<int, int> O;
int i, j, test;
int N, M, T;
bool Ok, Corect;

inline pair<int, int> Minim()
{
	pair<int, int> O = make_pair(0, 0);
	int i, j;
	A[0][0] = 101;
	
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			if (A[i][j] && A[O.first][O.second] > A[i][j])
				O = make_pair(i, j);
	return O;
}

inline bool Check_line(int Line, int Val)
{
	int i;
	for (i = 1; i <= M; ++i)
		if (A[Line][i] > Val)
			return false;
	return true;
}

inline bool Check_column(int Column, int Val)
{
	int i;
	for (i = 1; i <= N; ++i)
		if (A[i][Column] > Val)
			return false;
	return true;
}

inline void Select_line(int Line)
{
	int i;
	for (i = 1; i <= M; ++i)
		A[Line][i] = 0;
}

inline void Select_column(int Column)
{
	int i;
	for (i = 1; i <= N; ++i)
		A[i][Column] = 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d", &T);
	for (test = 1; test <= T; ++test){
		printf("Case #%d: ", test);
		scanf("%d %d", &N, &M);
		for (i = 1; i <= N; ++i)
			for (j = 1; j <= M; ++j)
				scanf("%d", &A[i][j]);
		O = Minim(); Corect = true;
		while (O.first != 0){
			Ok = false;
			if (Check_line(O.first, A[O.first][O.second])){
				Select_line(O.first);
				Ok = true;
			}
			if (Check_column(O.second, A[O.first][O.second])){
				Select_column(O.second);
				Ok = true;
			}
			
			if (Ok == false){
				Corect = false;
				break;
			}
			
			O = Minim();
		}
		if (Corect)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}