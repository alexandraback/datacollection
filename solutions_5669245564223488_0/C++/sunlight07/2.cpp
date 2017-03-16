#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cstdio>

using namespace std;

struct Car
{
	bool flag;
	string original;
	
	bool removeMiddleChars(unordered_set<char> &ss)
	{
		original = original.substr(0, unique(original.begin(), original.end()) - original.begin());
		ss.insert(original.front());
		if (original.length() == 1) return true;	
		ss.insert(original.back());
		if (original.length() == 2) return true;
		
		for (int k = 1; k < original.length() - 1; k++)
		{
			if (!ss.insert(original[k]).second)
			{
				return false;
			}
		}
		string ttt;
		ttt.push_back(original.front());
		ttt.push_back(original.back());
		original = ttt;
		return true;
	}
};

using namespace std;

const long long MAGIC = 1000000007ULL;

void fact(long long &p, int n)
{
	for (int k = 1; k <= n; k++)
	{
		p = (p * k) % MAGIC;
	}
}

int main()
{
	int T;
	scanf("%d\n", &T);
	Car cars[100];
	char p[1024];

	for (int t = 1; t <= T; t++)
	{
		int s;
		scanf("%d\n", &s);
		for (int k = 0; k < s; k++)
		{
			scanf("%s", &p);
			cars[k].original = p;
		}
		
		bool fail = false;
		unordered_set<char> ss;
		for (int k = 0; k < s; k++)
		{
			cars[k].flag = true;
			if (!cars[k].removeMiddleChars(ss))
			{
				fail = true;
				break;
			}
		}
		
		if (fail)
		{
			printf("Case #%d: 0\n", t);
			continue;
		}
		
		long long result = 1;
		unordered_map<char, int> mm;
		for (int k = 0; k < s; k++)
		{
			string &t = cars[k].original;
			if (t.length() == 1)
			{
				mm[t[0]]++;
				if (mm[t[0]] != 1)
				{
					cars[k].flag = false;
				}
			}
		}
		
		for (auto &p : mm)
		{
			fact(result, p.second);
		}
		
		unordered_map<char, Car*> fm;
		unordered_map<char, Car*> bm;
		
		fail = false;
		for (int k = 0; k < s; k++)
		{
			string &t = cars[k].original;
			if (t.length() == 2)
			{
				if (fm.count(t.front()) != 0)
				{
					fail = true;
					break;
				}
				fm[t.front()] = cars + k;
				
				if (bm.count(t.back()) != 0)
				{
					fail = true;
					break;
				}
				bm[t.back()] = cars + k;
			}
		}
		
		if (fail)
		{
			printf("Case #%d: 0\n", t);
			continue;
		}
		
		int circlenum = 0;
		for (int k = 0; k < s; k++)
		{
			if (!cars[k].flag) continue;
			string &t = cars[k].original;
			if (t.length() == 1)
			{
				char cc = t[0];
				if (fm.count(cc) == 0 && bm.count(cc) == 0)
				{
					circlenum++;
					cars[k].flag = false;
					continue;
				} else {
					if (bm.count(cc) != 0)
					{
						Car *c = bm[cc];
						c->flag = false;
						t = c->original;
						
						if (fm.count(cc) != 0)
						{
							c = fm[cc];
							c->flag = false;
							t[1] = c->original[1];
						}
					} else {
						Car *c = fm[cc];
						c->flag = false;
						t = c->original;
					}
				}
			}
		}
		
		/*for (int k = 0; k < s; k++)
		{
			if (!cars[k].flag) continue;
			string &t = cars[k].original;
			cout << t << endl;
		}
		cout << "------" << circlenum << " " << result << endl;*/
		
		fm.clear();
		bm.clear();
		for (int k = 0; k < s; k++)
		{
			if (!cars[k].flag) continue;
			assert(cars[k].original.length() == 2);
			fm[cars[k].original[0]] = cars + k;
			bm[cars[k].original[1]] = cars + k;
		}
		
		for (int k = 0; k < s; k++)
		{
			if (!cars[k].flag) continue;
			
			Car *c = cars + k;
			char cc = c->original[0];
			if (bm.count(cc) != 0) continue;
			int size = 1;
			
			while (true)
			{
				c->flag = false;
				if (c->original[1] == cc)
				{
					result = result * (long long)size % MAGIC;
					break;
				} else {
					char ccc = c->original[1];
					if (fm.count(ccc) == 0)
					{
						break;
					} else {
						c = fm[ccc];
						size++;
					}
				}
			}
			
			circlenum++;
		}
		
		fact(result, circlenum);
		printf("Case #%d: %lld\n", t, result);
	}
	return 0;
}
