#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 10
int testn;
int n, temp;
int result;
vector<int> a;

void Recur(int minute)
{
	if (minute >= result)
		return;

	int curMax = a[0];
	int index = 0;
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] > curMax) {
			curMax = a[i];
			index = i;
		}
	}

	result = min(result, minute + curMax);

	if (curMax <= 3)
		return;

	for (int k = 2; k*2 <= curMax; ++k) {
		a[index] = k;
		a.push_back(curMax-k);
		Recur(minute+1);
		a.pop_back();
		a[index] = curMax;
	}
}


int main()
{
	//ifstream in("input.txt");
	ifstream in("B-small-attempt3.in");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		a.clear();

		in >> n;
		for (int i = 0; i < n; ++i) {
			in >> temp;
			a.push_back(temp);
		}

		sort(a.begin(), a.end());
		
		result = a[a.size()-1];
		Recur(0);

		out << "Case #" << test << ": " << result << endl;
	}

	in.close();
	out.close();
	return 0;
}