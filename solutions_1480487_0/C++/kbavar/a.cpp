#include <iostream>
using namespace std;


int main()
{
	int t, n, i, j, g[300], m, k, c[300];
	double p, y, b[300], z, x, xm;
	
	
	cin >> t;
	cout.precision(6);
	cout.setf(ios::fixed,ios::floatfield); 
	for (i=0; i<t; i++) {
		cin >> n;
		x=0;
		for (j=0; j<n; j++) {
			cin >> g[j];
			x+=g[j];
		}
		for (k=0; k<n; k++) {
			z=(x-g[k]+x-(n-1)*g[k])/(n);
			b[k]=100*z/x;
			c[k]=1;
			if (b[k]<0) { 
				c[k]=0;
				b[k]=0;
			}
		}
		for (k=0; k<n; k++) {
			if (b[k]>0) {
				m=0;
				xm=0;
				for (j=0; j<n; j++) {
					if ((j!=k) && (c[j])) {
						m++;
						xm+=g[j];
					}
				}
				z=(xm+x-m*g[k])/(m+1);
				b[k]=100*z/x;
			}
		}

		cout << "Case #" << i+1 << ": " ;
		for (j=0; j<n-1; j++) cout << b[j] << " ";
		cout << b[n-1] << endl;
	}	
	return 0;
}
