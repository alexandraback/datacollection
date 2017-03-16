#include "common.h"

typedef pair<Int, Int> pairT;
typedef pair<Int, Int> keyT;
namespace std
{
	template<>
	struct less<pair<Int, Int>>
	{
		bool operator()(const keyT &l, const keyT &r) const
		{
			if (l.first < r.first)
				return true;
			if (l.first > r.first)
				return false;
			if (l.second < r.second)
				return true;
			return false;
		}
	};
}


map<keyT, pairT> prevs;

void InitMap()
{
	//To(1,0, firsts[0]);
	//To(0,1, firsts[1]);
	//To(-1,0, firsts[2]);
	//To(0,-1, firsts[3]);
	//prevs[firsts[0]] = make_pair(0,0);
	//prevs[firsts[1]] = make_pair(0,0);
	//prevs[firsts[2]] = make_pair(0,0);
	//prevs[firsts[3]] = make_pair(0,0);
	keyT keys[4];
	vector<pairT> nexts(1, make_pair(0,0));
	int jump = 1;
	while (jump <= 500)
	{
		vector<pairT> newNexts;
		newNexts.reserve(nexts.size() * 4);
		for (int i = 0; i < nexts.size(); i++)
		{
			keys[0] = make_pair(nexts[i].first + jump, nexts[i].second);
			keys[1] = make_pair(nexts[i].first, nexts[i].second + jump);
			keys[2] = make_pair(nexts[i].first - jump, nexts[i].second);
			keys[3] = make_pair(nexts[i].first, nexts[i].second - jump);
			for (int j = 0; j < 4; j++)
			{
				if (keys[j].first < 0)
				{
					keys[j] = make_pair(keys[j].second, -keys[j].first);					
				}
				if (keys[j].second < 0)
				{
					keys[j] = make_pair(-keys[j].second, keys[j].first);
				}
				pairT & p = prevs[keys[j]];
				if (p.first == 0 && p.second == 0)
				{
					p = nexts[i];
					newNexts.push_back(keys[j]);
				}
			}
		}
		swap(nexts, newNexts);
		jump++;
	}
}

string GetPath(int x, int y)
{
	keyT p(x,y);
	string result;
	result.reserve(500);
	while(p.first != 0 || p.second != 0)
	{
		keyT k = p;
		pair<int, int> prev = prevs[k];
		int pX = prev.first, pY = prev.second;
		if (pX != x)
		{
			if (pX < x) 
				result += "E";
			else
				result += "W";
		}
		else
		{
			if (pY < y)
				result += "S";
			else
				result += "N";
		}
		p = prev;
	}
	reverse(result.begin(), result.end());
	return result;
}

void SovleB(char * input)
{	
	//InitMap();
	fprintf(stderr, __FUNCTION__ " started...\n");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Int x,y;
		READ(x), READ(y), NL;
		string res;
		res.reserve((abs(x) + abs(y)) * 2);
		if (x > 0)
		{
			for (Int i = 0; i < x; i++)
				res.append("WE");
		}
		else
		{
			for (Int i = 0; i < -x; i++)
				res.append("EW");
		}
		if (y > 0)
		{
			for (Int i = 0; i < y; i++)
				res.append("SN");
		}
		else
		{
			for (Int i = 0; i < -y; i++)
				res.append("NS");
		}
		fprintf(stdout, "Case #%I64d: %s\n", i + 1, res.c_str());
	}
	fprintf(stderr, "\n" __FUNCTION__ " ended.\n");
}