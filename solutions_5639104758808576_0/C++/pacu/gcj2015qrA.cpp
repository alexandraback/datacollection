#include <iostream>
#include <string>
using namespace std;

int test(string s)
{
	int curStood = 0;
	int invite = 0;
	for(int i=0;i<s.size();i++)
	{
		if(curStood >= i)
			curStood += (s[i]-'0');
		else
		{
			invite += (i-curStood);
			curStood = i;
			curStood += (s[i]-'0');
		}
	}
	return invite;
}

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);
	int T;
	int m;
	string s;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> m >> s;
		cout << "Case #" << i+1 << ": " << test(s) << "\n";
	}
}