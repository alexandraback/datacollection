#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

//#include <cctype>
#include <cmath>

#include <fstream>

using namespace std;

double passw(int a, int b, vector<double> vd)
{
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;

	vector<double> res;
	vector<double> vd1;
	double p = 0;

	vd1.push_back(vd[0]);
	for (int i = 1; i < vd.size(); i++)
	{
		vd1.push_back(vd1[i-1]*vd[i]);
	}

	res.push_back((double)(b+2));
	double r1 = (b-a+1)*vd1[vd1.size()-1]+(b-a+b+2)*(1.0-vd1[vd1.size()-1]);
	res.push_back(r1);

	for (int i = 1; i < a; i++)
	{		
		double p = vd1[a-i-1]*(b-a+i+1+i) + (1.0-vd1[a-i-1])*(i+b-a+i+1+b+1);
		res.push_back(p);

		//cout << "p = "<< p << endl;
	}	
	
	sort(res.begin(), res.end());
	return res[0];
}

int main(int argc, char *argv[])
{
	cout.precision(6); 
	int a,b,c,t,n = 0;

	cin >> n;
	cin.ignore();

	string line;
	
	int i = 1;
	while (i<=n)
	{
		int a, b;
		vector<double> vd;
		cin >> a >> b;
		for (int j = 0; j < a; j++)
		{
			double d;
			cin >> d;

			vd.push_back(d);
		}

		//getline(cin, line);
		
		cout << "Case #" << i << ": " << fixed << passw(a, b, vd) << endl;
		i++;
	}



	return 0;
}
