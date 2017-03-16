#include <iostream>
#include <cstring>

using namespace std;


string shrink(string str)
{
	string out = "";
	out += str[0];
	for(int i=1;i<str.size();i++)
		if(str[i]!=str[i-1])
			out+=str[i];
	return out;
}

int count(string str)
{
	if(str[0]=='+')
		return str.size() - str.size()%2;
	else
		return str.size() - 1  + str.size()%2;
}



int main()
{
	int t;
	cin >> t;
	string inp;
	getline(cin, inp);
	for(int i=0;i<t;i++)
	{
		getline(cin, inp);
		cout << "Case #" << i+1 << ": ";
		cout << count(shrink(inp)) << endl;
	}
	return 0;	
}
