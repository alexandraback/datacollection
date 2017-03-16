#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define for if (0) ; else for

char buf[20];

bool ispalin(__int64 n)
{
	sprintf(buf, "%I64d", n);
	int len = strlen(buf);
	for (int i  =0; i < len/2; ++i)
	{
		if (buf[i] != buf[len-i-1]) return false;
	}
	return true;
}

int main()
{
	FILE* ifs = fopen("3.in", "r");
	ofstream ofs("3.out");
	int t;
	fscanf(ifs, "%d", &t);
	vector<__int64> v;
	for (__int64 i = 1;  i < 10000000; ++i)
	{
		if (ispalin(i*i) && ispalin(i))
		{
			v.push_back(i*i);
		}
	}
	for (int test = 0; test < t; ++test)
	{
		__int64 a, b;
		fscanf(ifs, "%I64d %I64d", &a, &b);
		ofs << "Case #" << test+1 << ": ";
		ofs << lower_bound(v.begin(), v.end(), b+1) - lower_bound(v.begin(), v.end(), a) << endl;
	}


	return 0;
}