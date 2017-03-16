#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

#define distsq(x1, y1, x2, y2) (((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2)))

int main(){
	int t, w, h, d, x, y, n, x2, y2, d2, narr;
	char c;
	cin >> t;
	int i, j, k, p;
	bool ishidden;
	int xarr[10000];
	int yarr[10000];
	
	
	for (i=0; i<t; i++) {
		cin >> h >> w >> d;
		for (j=0; j<h; j++) {
			for(k=0; k<w; k++){
				cin >> c;
				if (c=='X') {
					x = k-1;
					y = j-1;
				}
			}
		}
		w -= 2;
		h -= 2;
		d2 = d*d;
		
		n = 0;
		if((2*x+1)<=d) n++;
		if((2*w-2*x-1)<=d) n++;
		if((2*y+1)<=d) n++;
		if((2*h-2*y-1)<=d) n++;
		narr = n;
		
		for (j=-(d/h+1); j<=d/h+1; j++) {
			for (k=-(d/w+1); k<=d/w+1; k++) {
				if (j==0 || k==0) continue;				
				x2 = k*w+((k&1)?(w-1-x):(x));
				y2 = j*h+((j&1)?(h-1-y):(y));
				if (distsq(x, y, x2, y2)<=d2) {
					p=narr;
					ishidden = false;
					while (p<n) {
						if(((x-x2)*(y-yarr[p])==(y-y2)*(x-xarr[p])) &&
						   (((x-x2)*(x-xarr[p])+(y-y2)*(y-yarr[p]))>0)){
							ishidden = true;
							break;
						}
						p++;
					}
					if (!ishidden) {
						xarr[n] = x2;
						yarr[n] = y2;
						n++;
					}
				}
			}
		}
		
		cout <<"Case #"<<(i+1)<<": "<<n<<endl;
	}
	
	return 0;
}