#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <algorithm>

typedef long long ll;

using namespace std;


ll get_factorial(ll n)
{
	ll rest = 1;

	for(ll i = 2; i <= n; i++)
	{
		rest *= i;
	}

	return rest;
}

void fill_rest(set<pair<ll,ll> > &pairs, ll m, ll b, ll numRoads)
{
	
	for(int i = 2; i < b; i++)
	{
		for(int j = i + 1; j < b; j++)
		{
			pair<ll,ll> pr = make_pair(i,j);
			if(pairs.find(pr) == pairs.end())
			{
				pairs.insert(pr);
				numRoads++;
				if(numRoads == m) return;
			}

			pr = make_pair(j,i);
			if(pairs.find(pr) == pairs.end())
			{
				pairs.insert(pr);
				numRoads++;
				if(numRoads == m) return;
			}
		}
	}

}

int main()
{

    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int t;
    fin >> t;

    for(int q = 0; q < t; q++)
    {
		
		ll numRoads = 0;
		ll b,m;
		fin >> b >> m;
		
		ll factorial = get_factorial(b-2) + 1;
		if(factorial < m) 
		{
			fout << "Case #" << q+1 <<": IMPOSSIBLE" << endl;
			continue;
		}

		set<pair<ll,ll> > pairs;
		
		pairs.insert(make_pair(1,b));

		numRoads = 1;

		for(int i = 0; i < min(b-2,m-1); i++)
		{
			pairs.insert(make_pair(1,2+i));
			pairs.insert(make_pair(2+i,b));
			numRoads++;
		}

		fill_rest(pairs,m,b, numRoads);


		fout << "Case #" << q+1 <<": POSSIBLE" << endl;
		
		for(int i = 1; i <= b; i++)
		{
			for(int j = 1; j <= b; j++)
			{
				pair<ll,ll> pr = make_pair(i,j);
				if(pairs.find(pr) == pairs.end()) fout << 0;
				else fout << 1;
			}
			fout << endl;
		}
    }



    fin.close();
    fout.close();

    return 0;
}

