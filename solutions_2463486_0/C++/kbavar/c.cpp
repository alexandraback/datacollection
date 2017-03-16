#include <iostream>
using namespace std;


bool ply(long long t) {
	int i;
	long long r, q;
	r=0;
	q=t;
	while (t){
		r*=10;
		r+=t%10;
		t=t/10;
	}
	return r==q;
}

int main()
{
	int n, i, j, ll;
	long long a, b, x, l[1000];
	
	ll=0;
	for (j=1; j<=32; j++)
		if (ply(j) && ply(j*j)) {
			l[ll]=j*j;
			ll++;
			//cout << j*j << endl;
		}
	cin >> n;
	for (i=0; i<n; i++) {
		cin >> a >> b;
		x=0;
		for (j=0; j<ll; j++)
			if ((l[j] >= a) && l[j] <= b) x++;
		cout << "Case #" << i+1 << ": "  << x << endl;
	}	
	return 0;
}
