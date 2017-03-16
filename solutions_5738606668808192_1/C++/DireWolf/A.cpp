#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

FILE *fin = freopen("A-small.in", "r", stdin);
FILE *fout = freopen("A-small.out", "w", stdout);

using namespace std;

int j = 500;
vector<string> found;


void MakeUpNumbers(string curr, int oneLeftOdd, int oneLeftEven)
{
	if(j == 0) return;
	if(oneLeftOdd == 0 && oneLeftEven == 0)
	{
		if (!(find(found.begin(), found.end(), curr) != found.end()))
{
		cout << curr << " 3 2 5 2 5 2 3 2 11" << endl;
		j--;
		found.push_back(curr);
		}
				return;

	}
	
	for (int i= 1; i < curr.length()-1; i++)
	{
		if(curr[i] != '1')
		{
			if(i %2 == 0 && oneLeftEven > 0)
			{
			curr[i] = '1';
			MakeUpNumbers(curr, oneLeftOdd, oneLeftEven-1);
			curr[i] = '0';
			}
			if(i %2 == 1 && oneLeftOdd > 0)
			{
			curr[i] = '1';
			MakeUpNumbers(curr, oneLeftOdd-1, oneLeftEven);
			curr[i] = '0';
			}
		}
	}
	
}

void solve()
{
	int n;
	cin >> n >> j;
	string str(n, '0');
	str[0] = '1';
	str[n-1] = '1';
	//str[n-2] = '1';
	MakeUpNumbers(str,9,9);
}

// Multiple text cases
void main(){
	int t;
	cin >> t;
	for(int i=1 ; i<=t ; i++){
		cout << "Case #" << i << ":";
		cout << endl;
		solve();
		//cout << endl;
	}
}