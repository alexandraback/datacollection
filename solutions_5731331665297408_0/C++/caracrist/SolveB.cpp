#include "stdafx.h"

vector<string> codes;
map<string, Int> locs;
multimap<Int, Int> fls;
bool Best(vector<Int> &path, Int curLoc, Int flights)
{
	if (path.size() == codes.size())
		return true;
	if (flights == 0)
		return false;
	multimap<Int, Int>::_Pairii tgts = fls.equal_range(curLoc);
	set<string> cop;
	for (multimap<Int, Int>::iterator it = tgts.first; it != tgts.second; it++)
	{
		cop.insert(codes[it->second]);
	}
	for (set<string>::iterator it = cop.begin(); it != cop.end(); it++)
	{
		if (find(path.begin(), path.end(), locs[*it]) != path.end())
			continue;
		path.push_back(locs[*it]);
		if (Best(path, path.back(), flights-1))
			return true;
		path.pop_back();
	}
	if (path[0] == curLoc)
		return false;
	vector<Int>::iterator ind = find(path.begin(), path.end(), curLoc);
	return Best(path, *--ind, flights);
}

void SovleB(char * input)
{	
	TRACE("started...");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Int N,M; READ(N);READ(M);NL;
		locs.clear();
		codes.clear();
		codes.resize(N);
		for (Int j = 0; j < N; j++)
		{
			READ(codes[j]);NL;
			locs[codes[j]] = j;
		}
		fls.clear();
		for (Int j = 0; j < M; j++)
		{
			Int from, to;
			READ(from);READ(to);NL;
			fls.insert(make_pair(from-1, to-1));
			fls.insert(make_pair(to-1, from-1));
		}
		vector<Int> path;
		path.push_back(min_element(&codes[0],&codes[0] + N) - &codes[0]);
		Best(path, path.back(), M);
		string best;
		for (Int j= 0; j<path.size(); j++)
		{
			best+= codes[path[j]];
		}
		PRINT("Case #%I64d: %s\n", i + 1, best.c_str());
	}
	TRACE("ended.");
}