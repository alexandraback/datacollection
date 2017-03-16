#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		char pancakes[1000];
		scanf("%s", pancakes);

		int count = 0;
		int i;
		for (i=1; pancakes[i] != '\0'; i++) {
			// If two pancakes are different, we must flip the stack between them
			//since there's no other way to make them the same
			// If we do this in order, we get that all pancakes are the same
			if (pancakes[i] != pancakes[i-1]) 
				count ++;
		}

		// If the last pancake is a minus, we need to flip the whole stack
		if (pancakes[i-1] == '-')
			count ++;

		printf("Case #%d: %d\n", iC, count);
	}
	return 0;
}