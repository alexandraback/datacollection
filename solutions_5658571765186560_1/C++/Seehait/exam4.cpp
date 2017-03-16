#include <iostream>
#include <string>
#include <vector>

using namespace std;


string calc(int& x, int& r, int& c)
{
	if ( (r * c) % x != 0) return "RICHARD";
	if (r < x && c < x) return "RICHARD";
	if (r < x / 2 || c < x / 2) return "RICHARD";
	if (r + c < 2 * x - 1) return "RICHARD";
	return "GABRIEL";
}


int main()
{
	int totalcase = 0;
	cin >> totalcase;
	vector<string> output;
	int x = 0, r = 0, c = 0;
	for(int i = 0; i < totalcase; i++)
	{
		cin >> x >> r >> c;
		output.push_back(calc(x, r, c));
	}
	for(int i = 0; i < totalcase; i++)
	{
		cout << "Case #" << (i + 1) << ": " << output[i] << endl;
	}
	
	
}