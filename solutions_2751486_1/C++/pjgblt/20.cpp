#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int starting[1000000];
int nextStart[1000000];
map< pair<int,int>, bool> known;

bool isCons(char c)
{
	if (c == 'a') return false;
	if (c == 'e') return false;
	if (c == 'i') return false;
	if (c == 'o') return false;
	if (c == 'u') return false;
	return true;
}

int main()
{
	int cases;
	int c;
	long long result;
	
	string name;
	int l;
	int n;
	int i;
	
	cin >> cases;
	for (c = 1; c <= cases; c++)
	{
		result = 0;
		known.clear();
		cout << "Case #" << c << ": ";
		
		cin >> name >> n;
		l = name.length();
		
		starting[l-1] = isCons(name[l-1]) ? 1 : 0;
		for (i = l-2; i >= 0; i--)
		{
			if (isCons(name[i]))
			{
				starting[i] = starting[i+1] + 1;
			}
			else
			{
				starting[i] = 0;
			}
		}
		
		/*for (i = 0; i < l; i++)
		{
			cout << starting[i] << " ";
		}*/
		
		nextStart[l-1] = starting[l-1] >= n ? l-1 : -1;
		for (i = l-2; i >= 0; i--)
		{
			if (starting[i] >= n)
			{
				nextStart[i] = i;
			}
			else
			{
				nextStart[i] = nextStart[i+1];
			}
		}
		
		/*for (i = 0; i < l; i++)
		{
			cout << nextStart[i] << " ";
		}*/
		
		for (i = 0; i < l; i++)
		{
			if (nextStart[i] == -1)
			{
				break;
			}
			
			int nextEnd = nextStart[i] + n - 1;
			//cout << i << ":" << nextEnd << " ";
			result += l - nextEnd;
		}
		
		cout << result;
		cout << endl;
	}
	
	return 0;
}