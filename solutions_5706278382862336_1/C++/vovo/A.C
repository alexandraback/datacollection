
#include <iostream>

using namespace std;

long int NOD(long int x, long int y)
{   if (y == 0) return x;
    return NOD(y, x % y);
}

void div_fraction(long int &p, long int &q)
{
	long int nod = NOD(p,q);
	p = p/nod;
	q = q/nod;
}


long int findAncestor(long int P, long int Q)
{
	long int counter = 1;
	long int curQ = Q;
	
	while (double(curQ)/P > 2) {
//		cout << P << "/" << curQ << ":" << curQ/P << endl;;
		counter++;
		curQ /= 2;
	}
	return counter;
}

 int main (void)
{
long int T;
long int P,Q;
char slash;

cin >> T;

for (long int t = 1; t <= T; t++) {
	
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