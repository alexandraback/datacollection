//#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

ifstream cin("B-small-attempt0.in");
ofstream cout("B-small.out");
int main() {
int T;

cin >> T;
for (int tt=1; tt<=T; tt++) {
string s = "";
int x=0, y=0;
int X,Y;
cin >> X >> Y;
int step = 1;
if (x!=X) {
if (x<X) {
while (x<X){
x+=step; s += "E"; step++;
}
} else {
while (x>X) {
x-=step; s += "W"; step++;
}
}}
if (x!=X) {
	if (x<X) {
		while (x!=X) {
			s += "WE";
			x++;
		}
	} else {
		while (x!=X) {
			s += "EW";
			x--;
		}
	}
}
//x==X guaranteed
if (y!=Y) {
	if (y<Y) {
		while (y!=Y) {
			s += "SN";
			y++;
		}
	} else {
		while (y!=Y) {
			s += "NS";
			y--;
		}
	}
}
cout <<"Case #"<<tt<<": " << s<< endl;
}

return 0;
}

