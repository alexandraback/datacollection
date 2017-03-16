#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool esConsonante(char c)
{
	if(c == 'a')
		return false;
	if(c == 'e')
		return false;
	if(c == 'i')
		return false;
	if(c == 'o')
		return false;
	if(c == 'u')
		return false;
	return true;
}

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("a-s.in","r",stdin);
	freopen("a-s.out","w",stdout);
	int t;
	cin >> t;
	for(int s = 0; s < t; s++)
	{
		int n;
		//char ss [1000010];
		string ss;
		getline(cin, ss);
		getline(cin, ss, ' ');
		cin >> n;
		//scanf("%s %i\n", ss, &n);
		vector<pair<int, int> > sub;
		sub.clear();
		int consonantes = 0;
		int principio = 0;
		for(int i = 0; i < (int) ss.size(); i++)
		{
			if(esConsonante(ss[i]))
			{
				consonantes++;
				if(consonantes == 1)
				{
					principio = i;
				}
				if(consonantes == n)
				{
					sub.push_back(make_pair(principio, principio + n));
				} else if(consonantes > n)
				{
					consonantes--;
					principio++;
					sub.push_back(make_pair(principio, principio + n));					
				}
			} else {
				consonantes = 0;
			}
		}
		int tam = (int)ss.size();
		int res = 0;
		for(int i = 0; i < (int)sub.size(); i++)
		{
			int posp, posf;
			if(i > 0)
				posp = (sub[i].first) - sub[i-1].first;
			else
				posp = sub[i].first + 1;
			posf = tam - sub[i].second + 1;
			res = res + (posf * posp);
		}
		cout << "Case #" << s+1<< ": " << res << endl;
	}
	
	return 0;
	
}
