#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int T, teste;
int X, R, C;

int main() {
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++teste);
		scanf("%d %d %d", &X, &R, &C);

		if (C > R) swap(R, C);

		if ( (R * C) % X != 0) {
			printf("RICHARD\n");
			continue;
		}
		if (X > R) {
			printf("RICHARD\n");
			continue;
		}
		if (X >= (C + C + 1)) {
			printf("RICHARD\n");
			continue;
		}

		if (X >= C + C - 1) {
			X -= C;
			bool RICHARD = false;

			for (int left = 0; left <= X; left++) {
				bool found = false;
				
				for (int placement = 0; placement < R; placement++) {
					if (placement - left < 0 || placement + (X - left) >= R) continue; 

					bool okl = false, okr = false;

					if (placement - left == 0) {
						if (C == 1 || placement == 0) okl = true;
						
						else if (X == C-1) {
							int remA = left * (placement);
							int remB = (X - left) * (placement);

							okl = (remA % (X+C) == 0 && remB % (X+C) == 0);
						}
					}
					else {
						int reml = C * (placement) - left;
						okl = (reml % (X+C) == 0);
					}

					if (placement + (X - left) == R - 1) {
						if (C == 1 || R-placement-1 == 0) okr = true;
						
						else if (X == C-1) {
							int remA = left * (R-placement-1);
							int remB = (X - left) * (R-placement-1);

							okr = (remA % (X+C) == 0 && remB % (X+C) == 0);
						}
					}
					else {
						int remr = C * (R - placement - 1) - (X - left);
						okr = (remr % (X+C) == 0);	
					}

					if (okl && okr) found = true;
				}

				if (!found) {
					RICHARD = true;
				}
			}

			if (RICHARD) {
				printf("RICHARD\n");
				continue;
			}
		}

		printf("GABRIEL\n");
	}
}