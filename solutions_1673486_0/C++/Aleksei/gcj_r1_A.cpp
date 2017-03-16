#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

double p[100100];
double pp[100100];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int A, B;
		cin>>A>>B;
		for(int i=0; i<A; i++) cin>>p[i];
		pp[0] = 1;
		for(int i=1; i<=A; i++) pp[i] = pp[i-1]*p[i-1];
		double rez = B+2;
		//double t1 = (1.0-pp[A])*(B-A+1+B+1)+pp[A]*(B-A+1);
		//rez = min(rez, t1);
		for(int i=0; i<=A; i++){
			double t1 = (A-i+B-i+1)*pp[i]+(A-i+B-i+1+B+1)*(1.0-pp[i]);
			rez = min(rez, t1);
		}
		cout<<"Case #"<<testnum+1<<": "<<setiosflags(ios::showpoint|ios::fixed)<<setprecision(6)<<rez<<endl;
	}
	return 0;
}
