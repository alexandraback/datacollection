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
	freopen("A-large.in","r",stdin);
	freopen("A-o.out","w",stdout);
	int t;
	cin >> t;
	for(int s = 0; s < t; s++)
	{
		long long int n;
		//char ss [1000010];
		string ss;
		getline(cin, ss);
		getline(cin, ss, ' ');
		cin >> n;
		//scanf("%s %i\n", ss, &n);
		vector<pair<long long int, long long int> > sub;
		sub.clear();
		long long int consonantes = 0;
		long long int principio = 0;
		for(long long int i = 0; i < (long long int) ss.size(); i++)
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
		long long int tam = (int)ss.size();
		long long int res = 0;
		bool h = false;
		for(long long int i = 0; i < (long long int)sub.size(); i++)
		{
			h = true;
			long long int posp, posf;
			if(i > 0)
				posp = (sub[i].first) - sub[i-1].first;
			else
				posp = sub[i].first + 1;
			posf = tam - sub[i].second + 1;
			res = res + (posf * posp);
		}
		if(!h)
		cout << "Case #" << s+1<< ": " << 0 << endl;
		else
		cout << "Case #" << s+1<< ": " << res << endl;
	}
	
	return 0;
	
}
