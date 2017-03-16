#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, i, j, k, n, m, a[4000], b[4000], day[200], ee[200], ww[200], ss[200];
	int d, ni, w, e, s, dd, dp, ds, x, y, z, da;
	
	
	cin >> t;
	for (k=0; k<t; k++) {
		cin >> n;
		for (i=0; i<4000; i++) {
			a[i]=0;
			b[i]=0;
		}
		
		m=0;
		for (i=0; i<n; i++) {
			cin >> d >> ni >> w >> e >> s >> dd >> dp >> ds;
			for (j=0; j<ni; j++) {
				day[m]=d+dd*j;
				ee[m]=2000+2*e+2*dp*j;
				ww[m]=2000+2*w+2*dp*j;
				ss[m]=s+ds*j;
				m++;
			}
		}
		
		for (i=0; i<m; i++)
			for (j=1; j<m; j++)
				if (day[j]<day[j-1]) {
					x=day[j]; day[j]=day[j-1]; day[j-1]=x;
					x=ee[j]; ee[j]=ee[j-1]; ee[j-1]=x;
					x=ww[j]; ww[j]=ww[j-1]; ww[j-1]=x;
					x=ss[j]; ss[j]=ss[j-1]; ss[j-1]=x;
				}

		z=0;	
		i=0;
		da=day[0];
		while (i<m) {
//			cout << day[i] << ": " << ww[i] << "-" << ee[i] << "| " << ss[i] << endl;
			if (day[i]>da) 
				for (j=0; j<4000; j++) a[j]=b[j];
			y=0;
			for (j=ww[i]; j<=ee[i]; j++)
				if (a[j]<ss[i]) y++;
			for (j=ww[i]; j<=ee[i]; j++)
				if (b[j]<ss[i]) b[j]=ss[i];
			if (y) z++;
	//		if (y==0) cout << "<->" << i << endl;
			da=day[i];
			i++;
		}
		
		cout << "Case #" << k+1 << ": " << z << endl;

	}	
	return 0;
}
