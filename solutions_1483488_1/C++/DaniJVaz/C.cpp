#include <cstdio>
#include <set>

using namespace std;

int main() {
	int T, I;
	scanf("%d",&T);
	
	for (I=1; I<=T; I++) {
		int a, b, d, t;
		scanf("%d %d", &a, &b);
		
		// Number of digits of a and b
		t = a;
		for (d=0; t>0; d++)
			t /= 10;
		
		int pot10[d+1];
		pot10[0] = 1;
		for (int i=1; i<=d; i++)
			pot10[i] = pot10[i-1]*10;
		
		int count = 0;
		for (int i=a; i<=b; i++) {
			set<int> values;
			// Different cycles
			for (int j=1; j<d; j++) {
				// Build the new number (i%pot10[j]) is the right part, (i/pot10[j]) is the left part
				t = (i % pot10[j]) * pot10[d-j] + (i / pot10[j]);
				if (t <= b and t > i) {
					values.insert(t);
				}
			}
			count += values.size();
		}
		printf("Case #%d: %d\n", I, count);
	}
	return 0;
}
