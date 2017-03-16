#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<iomanip>
#include<algorithm>

using namespace std;

long double EPS = 0.000000001;

bool func (pair<pair<double,int>, double> a, pair<pair<double,int>, double> b)
{
	return a.first.second < b.first.second;
}

int main()
{
	ifstream fin ("in.in");
	ofstream fout ("out.out");
	string s;
	int caso = 1;
	int T;
	fin >> T;
	for (; T > 0; T--)
	{
		fout << "Case #" << caso << ":";
		
		int n;
		fin >> n;
		double X = 0;
		vector<pair<pair<double,int>, double> > v (n);
		for (int i = 0; i < n; i++)
		{
			fin >> v[i].first.first;
			v[i].first.second = i, v[i].second = 0;
			X+=v[i].first.first;
		}
		sort(v.begin(),v.end());

		double sum = v[0].first.first;
		double perc = 100.0;
		for (int i = 1; i <= n; i++)
		{
			if (i == n)
			{
				double aux = perc/(double)i;
				for (int j = i-1; j >= 0; j--)
				{
					v[j].second+=aux;
				}
				break;
			}
			if (v[i].first.first == sum) continue;
			double diff = ((v[i].first.first-sum)/X)*100.0;
			if ((diff*(double)i)+EPS <= perc)
			{
				perc-=(diff*(double)i);
				for (int j = i-1; j >= 0; j--)
				{
					v[j].second+=diff;
				}
			}
			else
			{
				double aux = perc/(double)i;
				for (int j = i-1; j >= 0; j--)
				{
					v[j].second+=aux;
				}
				break;
			}
			sum = v[i].first.first;
		}
		
		sort(v.begin(),v.end(),func);

		fout << setprecision(6) << fixed << showpoint;
		for (int i = 0; i < n; i++)
		{
			fout << " " << v[i].second;
		}
		fout << endl;
		caso++;
	}
	
}
