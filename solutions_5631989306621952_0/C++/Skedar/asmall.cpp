#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string wynik(string s)
{
	if (s.size() <= 1)
		return s;
	char ost = 0;
	for(auto el: s)
		ost = max(ost, el);
	
	int wyst = 0;
	for(int i=0; i<(int)s.size(); i++)
		if (s[i] == ost)
		{
			wyst = i;
			break;
		}
		
	string pom = "";
	for(int i=0; i<wyst; i++)
		pom += s[i];
	string wyn = wynik(pom);

	for(int i=wyst; i<(int)s.size(); i++)
	{
		if (s[i] == ost)
			wyn = s[i] + wyn;
		else
			wyn = wyn + s[i];
	}
	return wyn;
	
}

int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	int testy;
	cin>>testy;
	for(int test=1; test<=testy; test++)
	{
		string s;
		cin>>s;
		string wyn = wynik(s);
		cout << "Case #"<<test<<": "<<wyn<<"\n";
	}
}
