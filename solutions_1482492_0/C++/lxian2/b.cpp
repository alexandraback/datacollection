#include<iostream>
#include<math.h>
#include<fstream>
#include<iomanip>
using namespace std;

double other[2][2];
double my[2][2];
double d;
double a;
int n;

double gettd(){
	double x,y,z;
	double ov;
	double time;
	x = other[1][1]- other[0][1];
	y = other[1][0]- other[0][0];
	ov = x/y;
	time = d*2/a;
	time = sqrt(time);
	if(other[0][1]+ov*time >= d){
		return time;
	}
	else{
		return (d-other[0][1])/ov;
	}
}

int main(){
	int t;
	int p;
	double time, dis;
	ifstream ins ("ins");
	ofstream outs("outs");
	ins >> t;
	for(int z=1; z<= t; z++){
		ins >> d;
		ins >> n;
		ins >> p;
		for(int i=0; i<n ;i++){
			ins >> time >> dis;
			other[i][0] = time;
			other[i][1] = dis;
		}
		outs << "Case #" << z << ":" << endl;
		for(int i=0; i<p ; i++){
			ins >> a;
			if(n==1){
				time = d*2/a;
				time = sqrt(time);
				outs << time << endl;
				continue;
			}
			outs << setprecision (7) <<gettd() << endl;
		}
	}
	return 0;
}
