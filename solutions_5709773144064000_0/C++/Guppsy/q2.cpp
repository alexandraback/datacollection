#include <iostream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

int main(){

	freopen("q2.txt", "r", stdin);
	freopen("q2.out", "w", stdout);

	int cases;
	cin>>cases;

	for(int i=0;i<cases;i++){
		
		double c, f, x;
		cin>>c>>f>>x;

		double rt = 2;
		double sum = 0;

		double c1 = x/rt;
		double c2 = (c/rt) + (x/(f+rt));

		while(c1 > c2){
			sum += c/rt;
			rt = rt + f;
			c1 = x/rt;
			c2 = (c/rt) + (x/(f+rt));
		}
		
		sum += x/rt;
		cout<<std::fixed;
		cout<<"Case #"<<i+1<<": "<<std::setprecision(7)<<sum<<endl;
	}
	return 0;
}