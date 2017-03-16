#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t;
	cin >> t;
	int a, b, k;
	for(int caso = 1; caso <= t; caso++){
		cin >> a >> b >> k;
		int ans = 0;
		for(int i = 0; i < k; i++)
			for(int A = 0; A < a; A++)
				if((i & A) == i)
					for(int B = 0; B < b; B++)
						if((A & B) == i)
							ans++;
		printf("Case #%d: %d\n", caso, ans);
	}
	return 0;
}
