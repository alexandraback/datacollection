#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void doprob(double c, double f, double x, int index){
	double crate = 2.0, mintime;
	double ftime, ctime;
	ftime = 0;
	ctime = x/crate;
	mintime = ctime;
	int num = 0;
	while(num <= x/c - 2.0/f+10){
		ftime = ftime + c/(crate+num*f);
		ctime = ftime + x/(crate+f*(num+1));
		if(ctime < mintime){
			mintime = ctime;
		}
		num++;
	}
	cout << "Case #" << index << ": ";
	cout << setprecision(9) << mintime << endl;
}



int main(){
	int i;
	int cases;
	cin >> cases;
	double c, x, f;
	for(i=1; i<=cases; ++i){
		cin >> c >> f >> x;
		doprob(c, f, x, i);
	}
	return 0;
}
