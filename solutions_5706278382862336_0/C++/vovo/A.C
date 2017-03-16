
#include <iostream>

using namespace std;

void div_fraction(int p, int q)
{
}

int findAncestor(int P, int Q)
{
	int counter = 1;
	int curQ = Q;
	
	while (double(curQ)/P > 2) {
//		cout << P << "/" << curQ << ":" << curQ/P << endl;;
		counter++;
		curQ /= 2;
	}
	return counter;
}

int main (void)
{
int T;
int P,Q;
char slash;

cin >> T;

for (int t = 1; t <= T; t++) {
	
	cout << "Case #" << t << ": ";
	cin >> P;
	cin >> slash;
	cin >> Q;

	div_fraction(P,Q);

	if ((Q & (Q-1)) != 0) {
		cout << "impossible" << endl;
		continue;
	}
	
	cout << findAncestor(P, Q) << endl;
	
}
	
return 0;	
}