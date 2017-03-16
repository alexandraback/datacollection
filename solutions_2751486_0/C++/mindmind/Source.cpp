#include <iostream>
#include <string>

using namespace std;

bool IsConsonant(char c)
{
	if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
	{
		return false;
	}
	return true;
}

bool IsCondition(string str, long long int bound, long long int& idx)
{
	long long int cnt = 0;
	for(long long int i = 0; i < str.length(); ++i)
	{
		if(str.length() - i < bound -cnt)
		{
			return false;
		}

		if(IsConsonant(str[i]))
		{
			++cnt;
			if(cnt >= bound)
			{
				idx = i;
				return true;
			}
		}
		else
		{
			cnt = 0;
		}
	}
	return false;
}

long long int CntConsonant(string str, long long int bound)
{
	long long int cnt = 0;
	for(long long int i = 0; i < str.length() - bound + 1; ++i)
	{
		long long int id = 0;
		string str1 = str.substr(i);
		if(IsCondition(str1, bound, id))
		{
			cnt += str1.length() - id;
		}
	}
	return cnt;
}

int main()
{
	int probNum = 0;
	// Problem Num
	cin >> probNum;

	for(int i = 1; i <= probNum; ++i)
	{
		string str = "";
		int n = 0;
		cin >> str >> n;
		cout << "Case #" << i << ": " << CntConsonant(str, n) << endl;
	}
}