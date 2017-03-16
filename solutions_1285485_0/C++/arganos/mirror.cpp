/*
ID: enggi231
LANG: C++
PROG: 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

fstream out;

int t;
double h, w, d;
double mx, my;

double l(double b, double r, double m) {
	if (r == 1)
		return b/2;
	/*return ((b/r)*(m/w));*/
	return tan(asin( (b/r) / sqrt((b/r)*(b/r) + w*w) ))*m;
}

int getCnt() {
	double used[1000];
	int ucnt = 0;
	int cnt = 0;
	
	memset(used, 0, 1000*sizeof(double));
	for (int r = 1; 2*r*sqrt(mx*mx + h*h/(r*r*4)) <= d; r++) {
		for (double b = h; (2*r*sqrt(mx*mx + b*b/(r*r*4)) <= d); b += h) {
			bool ok = true;
			for (int i = 0; i < ucnt; i++) 
				if (used[i] == l(b, r, mx))
					ok = false;
			if (ok && (l(b, r, mx) > my)) {
				used[ucnt++] = l(b, r, mx);
				//cout << "r=" << r << " b=" << b << " d=" << l(b, r, mx) << " l=" << 2*r*sqrt(mx*mx + b*b/(r*r*4))<< endl;
				cnt++;
			}
		}
	}
	ucnt = 0;
	
	memset(used, 0, 1000*sizeof(double));
	for (int r = 1; 2*r*sqrt((w-mx)*(w-mx) + h*h/(r*r*4)) <= d; r++) {
		for (double b = h; (2*r*sqrt((w-mx)*(w-mx) + b*b/(r*r*4)) <= d); b += h) {
			bool ok = true;
			for (int i = 0; i < ucnt; i++) 
				if (used[i] == l(b, r, w-mx))
					ok = false;
			if (ok && (l(b, r, w-mx) > my)) {
				//cout << "r=" << r << " b=" << b << " d=" << l(b, r, mx) << " l=" << 2*r*sqrt(mx*mx + b*b/(r*r*4))<< endl;
				used[ucnt++] = l(b, r, w-mx);
				cnt++;
			}
		}
	}
		return cnt;
}


int main()
{
	fstream in("in.txt", ios_base::in);
	
	in >> t;
	
	for (int cas = 1; cas <= t; cas++) {
		in >> h >> w >> d;
		for (int y = 0; y < h ; y++)
			for (int x = 0; x < w; x++) {
				char tmp;
				in >> tmp;
				if (tmp == 'X') {
					mx = x - 0.5;
					my = y - 0.5;
					//cout << mx << " " << my << endl;
				}
			}
		
		h -= 2;
		w -= 2;
		//cout << w << " "<<h << endl;
		int cnt = 0;
			
		//trivial
		cnt += (2*mx <= d) + (2*(w-mx) <= d) + (2*my <= d) + (2*(h-my) <= d);  
		cnt += (4*(mx*mx + my*my) <= d*d) + (4*((w-mx)*(w-mx) + my*my) <= d*d)+
				(4*(mx*mx + (h-my)*(h-my)) <= d*d) + (4*((w-mx)*(w-mx) + (h-my)*(h-my)) <= d*d);
		//cout << cnt << endl;
		

		cnt += getCnt();
		//cout << cnt << endl;
		
		//cout << "   "<<h<<" "<<w << " "<<mx << " "<<my << endl;
		for (int i = 0; i < 3; i++) {
			double temp = h;
			h = w;
			w = temp;
			
			temp = mx;
			mx = my;
			my = (h-temp);
			//cout <<"   "<< h<<" "<<w << " "<<mx << " "<<my << endl;
			cnt += getCnt();
			//cout << cnt << endl;
		}
		cout <<"Case #" << cas << ": "<< cnt << endl;
		
	}
	return 0;
}

