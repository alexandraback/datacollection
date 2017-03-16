//#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
ifstream cin("A-small-attempt0.in");
ofstream cout("A-small-attempt0.txt");

double bs(vector <double> &ps, int pL, int nb){
	//ps[i] holds the prob. that all items until i are correct.
	//b must be smaller than ps.size()
	int k = ps.size()-nb -1;
	double ret = 0;
	double p1 = ps[ps.size()-nb-1];
	double l1 = (nb+pL-(ps.size()-nb)+1);
	ret+= p1*l1;
	double p2 = 1.0-p1;
	double l2 = l1 + pL+1;
	ret+= p2*l2;
	return ret;
}
double gvp(int pL){
	return pL+2;
}
const double infinity = 1E9;

int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int A,B;
		cin >> A >> B;
		vector <double> vd;
		vd.assign(A,0);
		
		for(int j=0;j<A;j++){
			double d;
			cin >> d;
			vd[j] = d;
		}
		vector <double> vd2 = vd;
		for(int j=1;j<A;j++)
			vd2[j] = vd[j]*vd2[j-1];
		vd = vd2;

		double mx = infinity;
		for(int k=0;k<vd.size();k++){
			mx = min(bs(vd,B,k),mx);
		}
		double t = gvp(B);
		mx = min(t,mx);
		cout <<fixed<< setprecision(9)<< "Case #" << i+1 << ": " << mx << endl;
	}
	return 0;
}
