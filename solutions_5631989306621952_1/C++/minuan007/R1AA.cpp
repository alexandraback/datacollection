#include<iostream>
#include<string>
#include<list>

using namespace std;

int main()
{
	int T, t;
	cin >> T;
	t = 1;
	while (T >= t)
	{
		string input;
		list<char> res;
		cin >> input;
		
		res.push_back(input[0]);
		char templ = input[0];
		for (int i = 1; i < input.size(); i++)
		{
			if (input[i] >= templ)
			{
				res.push_front(input[i]);
				templ = input[i];
			}
			else
			{
				res.push_back(input[i]);
			}
				
		}
		cout << "Case #" << t << ": ";
		auto p = res.begin();
		for (; p != res.end(); ++p)
			cout << *p;
		cout << endl;
		t++;
	}
}