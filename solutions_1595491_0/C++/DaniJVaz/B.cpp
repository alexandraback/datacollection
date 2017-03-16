#include <cstdio>

using namespace std;

inline int & min(int & a, int & b) {
	if (a <= b)
		return a;
	else
		return b;
}

int main() {
	int T, I;
	scanf("%d",&T);
	
	for (I=1; I<=T; I++) {
		int n, s, p, t, t2;
		scanf("%d %d %d", &n, &s, &p);
		int countPabove = 0;
		int countPminus1 = 0;
		
		for (int i=0; i<n; i++) {
			scanf("%d", &t);
			
			// Max score is given by ceil(t/3) or floor((t+2)/3)
			t2 = (t+2)/3;
			if (t2>=p)
				countPabove++;
			else if (t > 1 and t >= p*3 - 4)
				countPminus1++;
		}
	
		printf("Case #%d: %d\n", I, countPabove + min(countPminus1, s));
	}
	return 0;
}
