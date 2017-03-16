#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
string s;

int main(){
	int T;
	cin >> T;
	for (int cas = 1;cas <= T;cas++)
	{
		cin >> s;
		deque<char> final;
		for (int i = 0;i < s.size();i ++)
		{
			char c = s[i];
			if (final.empty())
			{
				final.push_back(c);
				continue;
			}
		//	cout << c << " "<<final.front() << endl;
			if(c >= final.front())
			{
				final.push_front(c);
			}else 
			{
				final.push_back(c);
			}
		}
		cout << "Case #" << cas << ": ";
		while(!final.empty())
		{
			cout << final.front();
			final.pop_front();
		}
		cout << endl;
	
	}
	return 0;
}
