#include <iostream>
using namespace std;

int m[1000010], c[1000010];

int main()
{
	long t, i, j, k, n, x, y, a, z;
	
	cin >> t;
	for (k=0; k<t; k++) {
		cin >> a >> n;
//		cout << a << " " << n << endl;
		for (i=0; i<n; i++)
			cin >> m[i];
		for (i=0; i<n ; i++)
			for (j=n-1; j>i ; j--)
			  if (m[j]<m[j-1]) {
				x=m[j];
				m[j]=m[j-1];
				m[j-1]=x;
			  }

		z=0;
		if (a == 1) x=n;
		else {
			for (i=0; i<n; i++) {
				c[i]=z;
				if (m[i] < a) {
					a+=m[i];
				}
				else {
					y=a;
					while (y<=m[i]) {
						c[i]++;
						y+=y-1;
					}
					a=y+m[i];
				}
				z=c[i];
			}

			//for (i=0; i<n; i++)  cout << m[i] << " "; cout << endl;
			//for (i=0; i<n; i++)  cout << c[i] << " "; cout << endl;
			//for (i=1; i<=n; i++)  cout << c[i-1]+n-i << " "; cout << endl;

			x=n;
			for (i=1; i<=n; i++)  
				if (c[i-1]+n-i<x) x=c[i-1]+n-i;
		}
		cout << "Case #" << k+1 << ": " << x <<  endl;
	}	
	return 0;
}
