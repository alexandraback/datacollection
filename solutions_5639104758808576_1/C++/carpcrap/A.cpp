#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int T;
	cin >> T;
	int lv;
	for(int t=1; t<=T; t++)
	{
		cin >> lv;
		cin >> s;
		int sum =0;
		int need =0;
		for(int i=0;i<=lv;i++)
		{
			if(sum < i)
			{
				need += i - sum;
				sum = i;
			}
			sum += (s[i]-'0');
		}
		printf("Case #%d: %d\n", t, need);
	}
}
