
#include "common.h"
struct MyLess
{
	bool operator() (const vector<int>& l, const vector<int>& r)
	{
		if (l.size() < r.size())
			return true;
		if (l.size() > r.size())
			return false;
		return memcmp(&l[0], &r[0], r.size() * sizeof(int)) < 0;
	}
};
set<vector<int>, MyLess> theSet;
CRITICAL_SECTION cs;
vector<vector<int>> theVec(1, vector<int>(1, 9));

struct PP
{
	inline char lowestValid(size_t index, bool beforeInc) const
	{
		if ((index == 0 && !beforeInc) || index == data.size() - 1)
			return '1';
		else 
			return '0';
	}
	inline char highestValid(size_t index, bool beforeInc) const
	{
		if (lowestValid(index, beforeInc) == '1')
			return '2';
		if (data.size() & 1 && index == data.size() / 2)
			return '2';
		return '1';
	}
	inline bool isValid(size_t index, char c, bool beforeInc) const
	{
		return c <= highestValid(index, beforeInc) && c >= lowestValid(index, beforeInc);
	}
	PP(char * src)
	{
		data.reserve(strlen(src) + 1);
		data.assign(src, src + strlen(src));
		Fix(data.size() - 1, false);
	}
	void Fix(int from, bool fromInc)
	{
		bool inc = false;
		for (Int i = from; i >= 0; i--)
		{
			char v = data[i];
			if (inc) {
				v++;
				inc = false;
			}
			if (!isValid(i, v, false))
			{
				inc = true;
				data[i] = lowestValid(i, true);
			}
			else
			{			
				data[i] = v;
				if (fromInc)
				{
					return;
				}
			}
		}
		if (inc)
		{
			data.insert(data.begin(), lowestValid(0, false));
		}
	}
	void MakeP()
	{
		for (Int i = 0; i < data.size() / 2; i++)
		{
			char & c = data[data.size() - i - 1];
			if (data[i] == c)
				continue;
			if (data[i] < c)
			{
				data[data.size() - i - 2]++;
				Fix(data.size() - i - 2, true);
			}
			data[data.size() - i - 1] = data[i];
		}
	}
	void Next()
	{
		data[data.size() - 1]++;
		Fix(data.size() - 1, true);
		MakeP();
	}
	string ToString() const
	{
		return string(&data[0], &data[0] + data.size());
	}
	bool HasPowPol()
	{
		int cnt1 = 0;
		for(int i = 0; i< data.size(); i++)
		{
			if (data[i] == '1')
				cnt1++;
		}
		if (cnt1 > 9)
			if ((cnt1 - 1) * (cnt1 - 1) > data.size() * 2)
				return false;
		if (bignum.empty()) 
			bignum.swap(vector<int>(data.size() * 2 - 1));
		else
			memset(&bignum[0], 0, bignum.size() * sizeof(int));
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == '0') 
				continue;
			int in = data[i] - '0';
			for (int j = 0; j < data.size(); j++)
			{
				if (data[j] == '0') 
					continue;
				int jn = data[j] - '0';
				bignum[i + j] += jn * in;
			}
		}
		bool inc = false;
		for (int i = bignum.size() - 1; i >= 0; i--)
		{
			int v = bignum[i];
			if (inc)
			{
				v++;
				inc = false;
			}
			if (v > 9)
			{
				inc = true;
				v = 0;
			}
			bignum[i] = v;
		}
		for (int i = bignum.size() - 1, f = 0; i > f; i--, f++)
		{
			if (bignum[i] != bignum[f])
				return false;
		}
		EnterCriticalSection(&cs);
		theVec.insert(theVec.end(), vector<int>())->swap(bignum);
		LeaveCriticalSection(&cs);
		return true;
	}
	vector<char> data;
	vector<int> bignum;
};

bool IsPolindrom(Int num)
{
	char str[32];
	sprintf(str, "%I64d", num);
	for (int l = strlen(str) - 1, f = 0; l > f; l--, f++)
	{
		if (str[l] != str[f])
			return false;
	}
	return true;
}

vector<int> FromString(const string& str)
{		
	vector<int> vval(str.size());
	for(int j = vval.size() - 1; j >= 0; j--)
	{
		vval[j] = str[j] - '0';
	}
	return vval;
}
string ToString(const vector<int>& vec)
{
	string res;
	for(int i =0; i< vec.size(); i++)
	{
		res.append(1, vec[i] + '0');
	}
	return res;
}

#define MID_THREADS_CNT 10
vector<pair<Int,Int>> fp;
void SovleC(char * input)
{
	InitializeCriticalSection(&cs);
	theVec.reserve(0x10000);
	DWORD begin = GetTickCount();
#pragma omp parallel for num_threads(MID_THREADS_CNT)
	for (int i = 1; i < MID_THREADS_CNT; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int x = (j & 1) ? i : (MID_THREADS_CNT*2) + 1 - i; 
			char * strn = "1";		
			string tmp;
			if (x != 1)
			{
				tmp.resize(x, '0');
				tmp[0] = '1';
				tmp[x - 1] = '1';
				strn = &tmp[0];
			}
			PP p(strn);
			while(p.data.size() == x)
			{
				if (p.HasPowPol())
				{	
				}
				p.Next();
			}
			fprintf(stderr, "[+%d] for %d, tid = %d\n",  (GetTickCount() - begin) / 1000, x, GetCurrentThreadId());
		}
	}

	fprintf(stderr, "done in [+%d] total = %x\n",  (GetTickCount() - begin) / 1000, theVec.size());
	theSet.swap(set<vector<int>, MyLess>(theVec.begin(), theVec.end()));
	fprintf(stderr, "done2 in [+%d] total = %x\n",  (GetTickCount() - begin) / 1000, theSet.size());

	Int n;
	READ(n), NL;
	for (Int i = 0; i < n; i++)
	{
		string from, to;
		READ(from), READ(to), NL;
		//int fromint, toint;
		//sscanf(from.c_str(), "%d", &fromint);
		//sscanf(to.c_str(), "%d", &toint);
		//vector<int> saved;
		//int realCount = 0;
		//for (int i = fromint; i <= toint; i++)
		//{
		//	if (IsPolindrom(i))
		//	{
		//		int sqri = sqrt((double)i);
		//		if (sqri * sqri == i && IsPolindrom(sqri))
		//		{
		//			realCount++;
		//			saved.push_back(i);
		//		}
		//	}
		//}
		set<vector<int>, MyLess>::iterator itFrom = theSet.lower_bound(FromString(from));
		set<vector<int>, MyLess>::iterator itTo = theSet.upper_bound(FromString(to));
		int dist = distance(itFrom, itTo);
		//if (dist != realCount)
		//{
		//	fprintf(stderr, "Case #%I64d: dist = %d, realCount = %d\n",  i + 1, dist, realCount);
		//	while (itFrom != itTo)
		//	{
		//		fprintf(stderr, "my %s\n", ToString(*itFrom).c_str());
		//		itFrom++;
		//	}
		//	for(int i = 0; i < saved.size(); i++)
		//	{
		//		fprintf(stderr, "saved %d %d^2\n", saved[i], (int)sqrt((double)saved[i]));
		//	}
		//}
		fprintf(stdout, "Case #%I64d: %d\n",  i + 1, dist);
	}
}