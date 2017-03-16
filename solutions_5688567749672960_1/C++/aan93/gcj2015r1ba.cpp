#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int t;
vector <long long int> a(1,0),b(1,0),d(1,1);
long long int inv(long long int p) {
	long long int q = 0;
	while (p > 0) {
		q = q*10 + p%10;
		p /= 10;
	}
	return q;
}
int ans(long long int n) {
	long long int n1 = n;
	int z = 0;
	//int y = 0;
	int x = 0;
	vector <int> c(0);
	while (n1 > 0) {
		c.push_back(n1%10);
		n1 /= 10;
		z++;
	}
	for (int j=0;j<z;j++) {
		x += c[j] * d[min(j,z-1-j)];
		//cout << i << " --- " << j << " " << c[j] << " " << d[min(j,z-1-j)] << "\n";
	}
	if (z > 1) {
		bool f = true;
		for (int j=0;f && j<(z+1)/2;j++) {
			if (c[j] > 0) f = false;
		}
		if (f) {
			int s = 0;
			for (int j=0;j<z;j++) {
				s += c[j];
			}
			if (s > 1) {
				//cout << n << " " << n-d[(z+1)/2]+1 << " " << ans(inv(n-d[(z+1)/2]+1)) << "\n";
				if (inv(n-d[(z+1)/2]+1) == n-d[(z+1)/2]+1) return ans(inv(n-d[(z+1)/2]+1)) + d[(z+1)/2] - 1;
				else return ans(inv(n-d[(z+1)/2]+1)) + d[(z+1)/2];
				x += d[(z+1)/2]-d[z-(z+1)/2-1];
			}
		}
	}
	if (z > 1) {
		bool g = true;
		if (c[z-1]!=1) g = false;
		for (int j = 1; g && j < z/2; j++) {
			if (c[z-1-j] != 0) g = false;
		}
		if (!g) x++;
	}
	return b[z-1]+x;
}
int main()
{
	in >> t;
	a.push_back(9);
	b.push_back(9);
	long long int c[2]={10,10};
	for (int i=2;i<17;i++) {
		a.push_back(c[0]+c[1]-1);
		b.push_back(b[i-1]+a[i]);
		c[i%2] *= 10;
	}
	for (int i=0;i<17;i++) {
		d.push_back(d[i]*10);
	}
	/*vector <int> ch(1,0);
	for (int i=1;i<=1e7;i++) {
		int ee = ch[i-1];
		int j = inv(i);
		if (i%10 > 0 && j<i) ee = min(ee, ch[j]);
		ch.push_back(ee + 1);
	}
	for (int z = 2; z < 10; z++) {
		cout << z << "\t" << d[(z+1)/2] << " " << d[z-(z+1)/2-1] << "\n";
	}*/
	for (int i=1;i<=t;i++)
	{
		long long int n;
		in >> n;
		out << "Case #" << i << ": " << ans(n) << "\n";
		//long long int n = i;
		
		//long long int m = ans(n);
		
		/*if (m != ch[n]) {
			out << "Case #" << i << ": " << m << " " << ch[n] << "\n";
			cout << "Case #" << i << ": " << m << " " << ch[n] << "\n";
			exit(0);
		}*/
		//if (i%1000000 == 0) cout << i << "\n";
	}
	return 0;
}
