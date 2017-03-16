#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int T, X, Y;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d %d", &X, &Y);

		string inX = X > 0 ? "WE" : "EW";
		string inY = Y > 0 ? "SN" : "NS";

		printf("Case #%d: ", t+1);

		for (int i = 0; i < abs(X); ++i) {
			printf("%s", inX.c_str());
		}

		for (int i = 0; i < abs(Y); ++i) {
			printf("%s", inY.c_str());
		}

		puts("");
	}
	return 0;
}