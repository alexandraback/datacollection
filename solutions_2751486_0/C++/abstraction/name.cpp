#include <iostream>
#include <string>

using namespace std;

bool isCC(const string& substr, int n)
{
	for (int i = 0; i < n; i++) 
	{
		if (substr[i] == 'a' 
		    || substr[i] == 'e'
		    || substr[i] == 'i'
		    || substr[i] == 'o'
		    || substr[i] == 'u'
		   )
			return false;
	}
	return true;
}

bool isC(const char c)
{
	if (c == 'a' 
	    || c == 'e'
	    || c == 'i'
	    || c == 'o'
	    || c == 'u'
	   )
		return false;
	else
		return true;
}

int solve(const string& str, int n) 
{
	int current = 0;
	int next = 0;
	if (n == 0 && str.size() == 1)
		return 1;
	else if (n == 0)
		return str.size() * (str.size() - 1) / 2;

	if (str.size() < n)
		return 0;
	while(current + n > next && next < str.size()) {
		current = next;
		for (; !isC(str[current]); current++)
			;
		next = current;
		for (; isC(str[next]) && current + n > next && next < str.size() ; next++)
			;
	}
	if ((current + n) == next && current + 1 < str.size())
		return (current + 1) * (str.size() - current - n + 1) + solve(str.substr(current+1), n);
	else if ((current + n) == next)
		return (current + 1) * (str.size() - current - n + 1);
	else
		return 0;

}
int main() {
	int T;
	string str;
	int L;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> str >> L;	
		cout << "Case #" << i << ": " << solve(str, L) << endl;
	}

}
