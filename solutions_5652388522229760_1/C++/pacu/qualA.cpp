#include <iostream>
#include <fstream>
using namespace std;

bool seen[10];

void test(int t)
{
	int N;
	cin >> N;
	for(int i=0;i<10;i++) seen[i] = 0;
	long long cur = N;
	for(int k=1;k<=1500000;k++, cur += N)
	{
		long long tmp = cur;
		while(tmp > 0)
		{
			seen[tmp%10] = 1;
			tmp /= 10;
		}
		bool good = 1;
		for(int i=0;i<10;i++) good = (good && seen[i]);
		if(good)
		{
			cout << "Case #" << t << ": " << cur << '\n';
			return;
		}
	}
	cout << "Case #" << t << ": " << "INSOMNIA\n";
}

int main()
{
	freopen("testin.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) test(i+1);
}