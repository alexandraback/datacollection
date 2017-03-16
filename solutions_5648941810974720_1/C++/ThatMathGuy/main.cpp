#include <bits/stdc++.h>

using namespace std;

string com[10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

char c[10] = {'Z','O','W','H','U','F','X','S','G','I'};

int y[10] = {0,2,4,6,8,1,3,5,7,9};

string s;

map<char,int> m;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tst;
	cin>>tst;
	for (int ntst = 1; ntst<=tst; ntst++)
	{
		cout<<"Case #"<<ntst<<": ";	
		cin>>s;
		
		v.clear();
		m.clear();
		for (int i=0; i<s.length(); i++)
			m[s[i]] ++;
			
		for (int i=0; i<10; i++)
		{
			int z = y[i];
			int r = m[c[z]];
			for (int j=0; j<com[z].length(); j++)
				m[com[z][j]]-=r;
			while (r--)
				v.push_back(z);
		}
		
		sort(v.begin(),v.end());
		
		for (int i:v) cout<<i;
		
		cout<<'\n';
	}

    return 0;
}

