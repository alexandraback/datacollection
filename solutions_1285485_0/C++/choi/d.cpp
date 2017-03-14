#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

double dist(double x,double y,double i,double j) {
	return sqrt((x-i)*(x-i)+(y-j)*(y-j));
}

int tst()
{
	int H, W, D;
	cin >> H >> W >> D;

	int count=0;
	char map[50][50];
	char m[200][200];

	char ch;
	for (int i=H; i>=1; i--) {
		for (int j=1; j<=W; j++) {
			cin >> ch;
			if (i<H && i>1 && j>1 && j<W) {
				map[i-2][j-2] = ch;
			}
		}
	}

	int ri, rj;
	int num_h = 2*ceil((double)D/(H-2))+1;
	int num_w = 2*ceil((double)D/(W-2))+1;
	for (int i=0; i<(H-2)*num_h; i++) {
		for (int j=0; j<(W-2)*num_w; j++) {
			int ii, jj;
			if ((i/(H-2))%2==0) {
				ii = i%(H-2);
			} else {
				ii = H-3-i%(H-2);
			}
			if ((j/(W-2))%2==0) {
				jj = j%(W-2);
			} else {
				jj = W-3-j%(W-2);
			}
			if (map[ii][jj]=='X' && i>=(H-2)*(num_h/2) && i<(H-2)*(num_h/2+1) && j>=(W-2)*(num_w/2) && j<(W-2)*(num_w/2+1)) {
				m[i][j] = '*';
				ri=i; rj=j;
			} else {
				m[i][j] = map[ii][jj];
			}
			//cout << m[i][j];
		}
		//cout << endl;
	}

	set<double> north, south;

	for (int i=0; i<(H-2)*num_h; i++) {
		for (int j=0; j<(W-2)*num_w; j++) {
			if (m[i][j]=='X' && dist(ri,rj,i,j)<=D) {
				if (i>ri || (i==ri && j>rj)) {
					if (i==ri)
						north.insert(1000);
					else
						north.insert((double)(j-rj)/(i-ri));
				} else {
					if (i==ri)
						south.insert(1000);
					else
						south.insert((double)(j-rj)/(i-ri));
				}
			}
		}
	}

	return north.size()+south.size();
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		cout << "Case #" << i+1 << ": " << tst() << endl;
	}
}



