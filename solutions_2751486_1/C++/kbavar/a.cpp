#include <iostream>
#include <string>

using namespace std;

int a[1000011];

int main()
{
	int t, i, j, k, n, c, d;
	long long m;
	string s;
	
	cin >> t;
	for (k=0; k<t; k++) {
		cin >> s >> n;

		j=s.length();
		for (i=0; i<j; i++)	a[i]=1;
		for (i=0; i<j; i++)	if (s[i]=='a') a[i]++;
		for (i=0; i<j; i++)	if (s[i]=='e') a[i]++;
		for (i=0; i<j; i++)	if (s[i]=='i') a[i]++;
		for (i=0; i<j; i++)	if (s[i]=='o') a[i]++;
		for (i=0; i<j; i++)	if (s[i]=='u') a[i]++;
			
		//for (i=0; i<j; i++)	cout << a[i];

		i=0; 
		m=0;
		c=0;
		d=0;
		while (i<j) {
			if (a[i]>1)	c=0;
			if (a[i]==1) c++;
			if (c>=n) { 
				m+=(i-n+2-d)*(j-i);
				d=i-n+2;
			}
			i++;
		}		

		cout << "Case #" << k+1 << ": " << m << endl;
	}	
	return 0;
}
