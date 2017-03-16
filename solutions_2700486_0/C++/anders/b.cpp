#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int c = 1; c <= cases; ++c) {
		printf("Case #%d: ",c);
		int n, x, y;
		cin >> n >> x >> y;
		int height = 0;
		double p = 1;
		if(n>=1){
			n-=1;
			++height;
		}
		if(n>=5){
			n-=5;
			++height;
		}
		if(n>=9){
			n-=9;
			++height;
		}
		if( abs(x)+y < 2*height){
			printf("1.0\n");
			continue;
		}
		if( abs(x) + y > 2*height || !n){
			printf("0.0\n");
			continue;
		}
		//cout << "Simulate" << endl;
		int iter = 1<<n;
		int hits = 0;
		for(int i=0; i<iter; ++i){
			int xleft = -2*height;
			int xright = 2*height;
			int size = iter;
			int icop = i;
			while(size > 1){
				size >>= 1;
				int dir = icop&1;
				icop >>= 1;
				if(xleft == 0) dir = 1;
				if(xright == 0) dir = 0;
				if(dir==0){
					if(xleft++ == x){
						++hits;
						break;
					}
				}else{
					if(xright-- == x){
						++hits;
						break;
					}
				}
			}

		}
		printf("%lf\n",((double)hits)/iter);


	}
	return 0;
}

