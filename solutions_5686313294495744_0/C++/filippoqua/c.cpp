#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

const double PI = 3.1415926535;

using namespace std;

pair<string,string> coppie[1000];
vector<pair<string,string> > reali, fake;
int n;

int prova(int a)
{
	int ris = 0;
	if(a==n)
	{
		for(int i=0; i<fake.size(); i++)
		{
			bool p1, p2;
			p1=p2=false;
			for(int j=0; j<reali.size() && !(p1&&p2); j++)
			{
				p1|=(reali[j].first == fake[i].first);
				p2|=(reali[j].second == fake[i].second);
			}
			if(!(p1&&p2))
				return 0;
		}
		return fake.size();
	}
	else
	{
		fake.push_back(coppie[a]);
		ris = prova(a+1);
		fake.pop_back();
		reali.push_back(coppie[a]);
		ris = max(ris,prova(a+1));
		reali.pop_back();
		return ris;
	}
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int t;
	in >> t;
	for(int i=0; i<t; i++)
	{
		in >> n;
		for(int j=0; j<n; j++)
			in >> coppie[j].first >> coppie[j].second;
		out << "Case #" << i+1 << ": " << prova(0) << endl;
	}
	return 0;
}
