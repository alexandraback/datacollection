#include<bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;
typedef long long ll;

void genera(string a, int pos, vector<string> &v)
{
	if(pos == a.size()) 
	{
		v.push_back(a);
		return;
	}

	if(a[pos] == '?')
	{
		for(char i='0'; i<='9'; ++i)
		{
			a[pos] = i;
			genera(a, pos+1, v);
		}
	}
	else genera(a, pos+1, v);
}

ll tonum(string a)
{
	ll ris=0;
	for(int i=0;i<a.size();++i)
	{
		ris*=10;
		ris += a[i] - '0';
	}

	return ris;
}

void foo()
{
	string C, J, solC, solJ;
	cin >> C >> J;


	vector<string> genC, genJ;
	genera(C, 0, genC);
	genera(J, 0, genJ);

	ll best = 1000000000000000000ll;

	for(auto i:genC)
		for(auto j:genJ)
		{
			ll delta = abs(tonum(i) - tonum(j));
		//	cout << i << j <<": " << delta << "(" << best << ")\n";
			if(delta < best)
			{
				solC = i;
				solJ = j;
				best = delta;
			}
		}

	cout << solC << " " << solJ;
}

int main()
{
	int T;
	cin >> T;
	
	for(int i=0;i<T;++i)
	{
		cout << "Case #" << i+1 << ": ";
		foo();
		cout << "\n";
	}

	return 0;
}
