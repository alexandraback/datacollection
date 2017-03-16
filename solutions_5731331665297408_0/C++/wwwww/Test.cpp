#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int> > pikachu;

struct flight
{
	bool operator ==(flight other)
	{
		return (fst == other.fst) && (snd == other.snd);
	}

	int fst;
	int snd;
};

void generatePerms(vector<int> v, int start, int n)
{  
	if (start == n - 1) 
	{
		pikachu.push_back(v);
	}
	else 
	{
		for (int i = start; i < n; i++) 
		{
			int tmp = v[i];
			v[i] = v[start];
			v[start] = tmp;
			generatePerms(v, start + 1, n);
			v[start] = v[i];
			v[i] = tmp;
		}
	}
}

bool checkGraph(vector<flight> g, vector<int> path)
{
	vector<flight> backedges;
	for (int i = 0; i < path.size() - 1; i++)
	{
		flight f;
		f.fst = path[i]; f.snd = path[i+1];
		flight rev;
		rev.fst = path[i+1]; rev.snd = path[i];
		if (find(g.begin(), g.end(), f) != g.end())
		{
			backedges.push_back(rev);
		}
		else if (find(g.begin(), g.end(), rev) != g.end())
		{
			backedges.push_back(f);
		}
		else //try backedges
		{
			bool found = false;
			int cur = path[i];
			for (int k = 0; k < backedges.size(); k++)
			{
				if (backedges[k].fst == cur)
				{
					cur = backedges[k].fst;
					found = true;
					break;
				}
			}
			while (found)
			{
				flight f; f.fst = cur; f.snd = path[i+1];
				flight rev; rev.fst = path[i+1]; rev.snd = cur;
				if (find(g.begin(), g.end(), f) != g.end())
				{
					backedges.push_back(rev);
					break;
				}
				else if (find(g.begin(), g.end(), rev) != g.end())
				{
					backedges.push_back(f);
					break;
				}
				else
				{
					found = false;
					for (int k = 0; k < backedges.size(); k++)
					{
						if (backedges[k].fst == cur)
						{
							cur = backedges[k].snd;
							found = true;
							break;
						}
					}
				}
			}
			if (!found)
				return false;
		}
	}
	return true;
}

int main()
{
	int ncases;
	cin >> ncases;

	for (int i = 1; i <= ncases; i++)
	{
		int M; int N;
		cin >> M >> N;
		vector<int> zips;
		vector<flight> poss;
		for (int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;
			zips.push_back(temp);
		}
		for (int j = 0; j < N; j++)
		{
			flight f;
			cin >> f.fst >> f.snd;
			f.fst--; f.snd--;
			poss.push_back(f);
		}

		string best = "zzzzz";
		vector<int> v;
		for (int j = 0; j < M; j++)
		{
			best = best + "zzzzz";
			v.push_back(j);
		}

		generatePerms(v, 0, M);
		for (int k = 0; k < pikachu.size(); k++)
		{
			string route = "";
			for (int kk = 0; kk < M; kk++)
			{
				stringstream ss;
				ss << zips[ pikachu[k][kk] ];
				route = route + ss.str();
			}
			if (route < best && checkGraph(poss, pikachu[k]))
			{
				best = route;
			}
		}
		cout << "Case #" << i << ": " << best << "\n";
		pikachu.clear();
	}
}
