#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string G;
string ff = "yhesocvxduiglbkrztnwjpfmaq";
int T, Tidx = 1;
int main()
{
	//freopen("e:\\A-small-attempt1.in","r",stdin);
	//freopen("e:\\A-small-attempt1.out","w",stdout);
	cin >> T;
	getchar();
	while(T--)
	{
		getline(cin, G);
		cout << "Case #" << Tidx++ << ": ";
		for(int i = 0; i < G.length(); i++)
		{
			if(G[i] == ' ')
				cout << G[i];
			else
				cout << ff[G[i] - 'a'];
		}
		cout << endl;
	}
	return 0;
}