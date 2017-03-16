#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	ifstream is("rp22.txt");
//	std::istream& is = std::cin;
	ofstream os("answer.txt");
	int testcase;
	is >> testcase;
	for ( int tc = 1; tc <= testcase; tc++){
		double c,f,x;
		is >> c >> f >> x;
		int n = static_cast<int>(f*x-2*c)/(f*c);
		if( n < 1) n = 0;
		
		double ans;
		if(  n == 0 )
			ans = x/2.0;
		else{
			ans = x/(2.0+n*f);
			for( int i = 0; i <=n-1; i++){
				ans += c/(2.0+i*f);
			}
		}


		os << "Case #"<<tc;
		os << ": ";
		os << setprecision(15) << ans << endl;
	}
	is.close();
	os.close();
}