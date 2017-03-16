#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int X,Y;


int main() {
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for (int k=0; k<t; k++) {
//		res.reserve(505);
		cin>>X>>Y;
		int x=0;
		int y=0;
		string res;
		int j=1;
		while (abs(x)<abs(X) && abs(y)<abs(Y)) {
			if (X<x) {
				res+='W';
				x-=j;
				j++;
			}
			else if (X>x) {
				res+='E';
				x+=j;
				j++;
			}
			if (Y<y) {
				res+='S';
				y-=j;
				j++;
			}
			else if (Y>y) {
				res+='N';
				y+=j;
				j++;
			}
			
		}
		if (x>X) {
			while (x!=X) {
				res+='E';
				x+=j;
				j++;
				res+='W';
				x-=j;
				j++;
			}
		}
		if (x<X) {
			while (x!=X) {
				res+='W';
				x-=j;
				j++;
				res+='E';
				x+=j;
				j++;
			}
		}

		if (y>Y) {
			while (y!=Y) {
				res+='N';
				y+=j;
				j++;
				res+='S';
				y-=j;
				j++;
			}
		}
		if (y<Y) {
			while (y!=Y) {
				res+='S';
				y-=j;
				j++;
				res+='N';
				y+=j;
				j++;
			}
		}


		cout<<"Case #"<<k+1<<": "<<res<<'\n';
	}
	return 0;
}