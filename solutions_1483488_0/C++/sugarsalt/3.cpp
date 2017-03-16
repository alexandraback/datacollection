#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int upper;
int lower;
set<int> re;

int countRecycled(int i, int upper, int digits)
{
	//cout << "i= " << i << endl;
	int digit0 = 10;
	int digit1 = 1;
	for (int j=0;j<digits-1;j++)
		digit1 *= 10;

	re.clear();
	for (int j=0;j<digits-1;j++)
	{
		//cout << "j= " << j << endl;
		int copy = i;
		int r = copy % digit0;
		copy /= digit0;
		int recycle = r * digit1 + copy;

		//cout << "recycle=" << recycle << endl;
		if (recycle > i && recycle <= upper && 
				re.find(recycle) == re.end() )
			re.insert(recycle);
		//cout << "set=" << re.size() << endl;

		digit0 *= 10;
		digit1 /= 10;
	}

	return (int)re.size();
}
int run(int casen)
{
	cin >> lower;
	cin >> upper;
	int digits = 1;
	for (int i=10;upper>=i;i*=10)
		digits++;

	//cout << "digits:" << digits << endl;

	int num_pairs = 0;
	for (int i=lower;i<upper;i++)
		num_pairs += countRecycled(i,upper,digits);
	cout << "Case #" << casen << ": " << num_pairs << endl;
	return 0;
}

int main()
{
	int test_n;
	cin >> test_n;

	for (int i=1;i<=test_n;i++) run(i);

	return 0;
}
