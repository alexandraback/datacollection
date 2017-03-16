#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

unsigned long long b_search(unsigned long long r, unsigned long long t);

int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("problemA-large.in");
	cout.open("problemA-large-out.txt");

	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		unsigned long long r, t;
		cin >> r >> t;

		cout << "Case #" << test << ": " << b_search(r,t) << endl;

	}

	cin.close();
	cout.close();

	return 0;
}

unsigned long long b_search(unsigned long long r, unsigned long long t)
{
	unsigned long long low = 0;
	unsigned long long high = 1e10;
	while(true)
	{
		unsigned long long mid = (low + high)/2;
		mid--;
		unsigned long long val_p = (2*r +1)*(mid + 1) + 2*mid*(mid+1);
		mid++;
		unsigned long long val = (2*r +1)*(mid + 1) + 2*mid*(mid+1);
		mid++;
		unsigned long long val_n = (2*r +1)*(mid + 1) + 2*mid*(mid+1);
		mid--;

		if(val_p == t) return mid;
		if(val == t) return mid + 1;
		if(val_n == t) return mid + 2;

		if(val_p < t && val > t) return mid;
		if(val < t && val_n > t) return mid + 1;

		if(val < t)
		{
			low = mid;
		}
		else if(val > t)
		{
			high = mid;
		}
	}
}
