#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Interval {
	Interval() {}
	Interval(int beg, int end) : beg(beg),end(end) {}

	int beg;
	int end;

	inline bool operator<(const Interval& iv) const
	{
		if(beg < iv.beg)
			return true;
		else if(beg == iv.beg)
			return end < iv.end;
		return false;
	}
};

vector<Interval> nSizedIvs;
set<Interval> seenIvs;

inline bool isConsonant(const char& ch)
{
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return false;
	return true;
}

void getIntervals(const string& str, const int& substrSize)
{
	int nbCons = 0;
	for(int pos=0; pos < substrSize; pos++)
		if(isConsonant(str[pos]))
			nbCons++;
	
	if(nbCons == substrSize)
		nSizedIvs.push_back(Interval(0,substrSize-1));

	for(size_t pos=1; pos <= str.size() - substrSize; pos++)
	{
		if(isConsonant(str[pos-1]))
			nbCons--;
		if(isConsonant(str[pos+substrSize-1]))
			nbCons++;

		if(nbCons == substrSize)
			nSizedIvs.push_back(Interval(pos, pos + substrSize - 1));
	}
}

int solveTest(const string& str, const int& substrSize)
{
	getIntervals(str, substrSize);
	int nbIvs=0;

	for(size_t iv=0; iv < nSizedIvs.size(); iv++)
	{
		for(int lBound = nSizedIvs[iv].beg; lBound >= 0; lBound--)
		{
			for(int rBound = nSizedIvs[iv].end; rBound < (int)str.size(); rBound++)
			{
				Interval curIv(lBound, rBound);
				if(seenIvs.find(curIv) != seenIvs.end())
					break;
				seenIvs.insert(curIv);
				nbIvs++;
			}
		}
	}

	nSizedIvs.erase(nSizedIvs.begin(), nSizedIvs.end());
	seenIvs.clear();
	return nbIvs;
}

int main(void)
{
	cin.sync_with_stdio(false);

	int nbTests;
	cin >> nbTests;

	for(int prob=0; prob < nbTests; prob++)
	{
		string str;
		int substrSize;
		
		cin >> str >> substrSize;

		cout << "Case #" << prob+1 << ": " << solveTest(str,substrSize) << "\n";
	}
	
	return 0;
}

