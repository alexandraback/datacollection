#include<string>
#include<iostream>

using namespace std;

int main()
{
	string g, s = "yhesocvxduiglbkrztnwjpfmaq";
	int t;
	scanf("%d", &t);
	getline(cin, g);
	for(int d = 1; d <= t; d++)
	{
		getline(cin, g);
		cout << "Case #" << d << ": ";
		for(int i = 0; i < g.length(); ++i)
			if(g[i] >= 'a' && g[i] <= 'z')
				cout << s[g[i] - 97];
			else
				cout << " ";
		cout << endl;
	}
}