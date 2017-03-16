#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin("B-large.in");
	ofstream fout("cookie.out");
	
	int cases;
	fin >> cases;
	for(int cnt = 1; cnt <= cases; ++cnt)
	{
		double C, F, X;
		double ans = 0;
		double rate = 2;
		fin >> C >> F >> X;
		fout << "Case #" << cnt << ": ";
		
		if(X < C)
		{
			ans = X / 2;
			fout << fixed << setprecision(7) << ans << endl;
			continue;
		}
		ans += C / 2;
		//cout << ans << endl;
		while(true)
		{
			if((X - C)/rate < X / (rate + F))
				break;
			rate += F;
			ans += C / rate;
			//cout << ans << endl;
		}
		ans += (X - C) / rate;
		//cout << ans << endl;
		//cout << endl;
		fout << fixed << setprecision(7) << ans << endl;
	}
}