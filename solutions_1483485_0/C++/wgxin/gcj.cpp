#include<iostream>
#include<string>
using namespace std;

char mapping[] = {
	'y',
	'h',
	'e',
	's',
	'o',
	'c',
	'v',
	'x',
	'd',
	'u',
	'i',
	'g',
	'l',
	'b',
	'k',
	'r',
	'z',
	't',
	'n',
	'w',
	'j',
	'p',
	'f',
	'm',
	'a',
	'q'};

int main()
{
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);

	int T;
	string G;
	cin>>T;
	getchar();
	for(int cas=1;cas<=T;cas++)
	{
		getline(cin, G);
		cout<<"Case #"<<cas<<": ";
		for(int i=0;i<G.length();i++)
		{
			if(G[i] == ' ')
				cout<<" ";
			else
				cout<<mapping[G[i]-'a'];
		}
		cout<<endl;
	}
}