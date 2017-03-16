#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;

unsigned long long calc_counts(const vector<unsigned long long>& bcounts,const vector<unsigned int>& btypes,unsigned long long destcount,unsigned int desttype,size_t b,size_t e)
{
	unsigned long long ret = 0;
	for(size_t i = b;i < e && i < bcounts.size() && destcount;++i)
	{
		if(btypes[i] != desttype) continue;
		unsigned long long x = bcounts[i];
		if(x > destcount) x = destcount;
		destcount -= x;
		ret += x;
	}
	return ret;
}

bool calc_counts(const vector<unsigned long long>& bcounts,const vector<unsigned int>& btypes,unsigned long long destcount,unsigned int desttype,vector< vector<unsigned long long> >& result)
{
	size_t size = bcounts.size();
	result.clear();result.resize(size+1,vector<unsigned long long>(size+1,0));
	for(size_t b = 0;b <= size;++b)
	{
		for(size_t e = b + 1;e <= size;++e)
		{
			result[b][e] = calc_counts(bcounts,btypes,destcount,desttype,b,e);
			//printf("%d %d %I64u\n",b,e,result[b][e]);
		}
	}
	return true;
}

unsigned long long solve_1(const vector<unsigned long long>& bcounts,const vector<unsigned int>& btypes,const vector<unsigned long long>& acounts,const vector<unsigned int>& atypes)
{
	vector< vector< unsigned long long> > results;
	calc_counts(bcounts,btypes,acounts[0],atypes[0],results);
	return results[0][bcounts.size()];
}

unsigned long long solve_2(const vector<unsigned long long>& bcounts,const vector<unsigned int>& btypes,const vector<unsigned long long>& acounts,const vector<unsigned int>& atypes)
{
	vector< vector< unsigned long long> > results[2];
	calc_counts(bcounts,btypes,acounts[0],atypes[0],results[0]);
	calc_counts(bcounts,btypes,acounts[1],atypes[1],results[1]);

	size_t size = bcounts.size();
	unsigned long long ret = results[0][0][size];
	if(results[1][0][size] > ret) ret = results[1][0][size];

	for(size_t p = 0;p <= size;++p)
	{
		unsigned long long x = results[0][0][p] + results[1][p][size];
		if(x > ret) ret = x;
	}
	return ret;
}

unsigned long long solve_3(const vector<unsigned long long>& bcounts,const vector<unsigned int>& btypes,const vector<unsigned long long>& acounts,const vector<unsigned int>& atypes)
{
	vector< vector< unsigned long long> > results[3];
	calc_counts(bcounts,btypes,acounts[0],atypes[0],results[0]);
	calc_counts(bcounts,btypes,acounts[1],atypes[1],results[1]);
	calc_counts(bcounts,btypes,acounts[2],atypes[2],results[2]);


	size_t size = bcounts.size();
	unsigned long long ret = results[0][0][size];
	if(results[1][0][size] > ret) ret = results[1][0][size];

	// [0,p),[p,q),[q,size)
	for(size_t p = 0;p <= size;++p)
	{
		for(unsigned int q = p;q <= size;++q)
		{				
			unsigned long long x = results[0][0][p] + results[1][p][q] + results[2][q][size];
			if(x > ret) ret = x;
			//printf("%d %d %I64u\n",p,q,x);
		}
	}
	return ret;
}

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0,m = 0;scanf("%d%d",&n,&m);
		vector<unsigned int> atypes(n);
		vector<unsigned long long> acounts(n);
		for(unsigned int i = 0;i < n;++i) scanf("%I64d%d",&acounts[i],&atypes[i]);
		vector<unsigned long long> bcounts(m);
		vector<unsigned int> btypes(m);
		for(unsigned int i = 0;i < m;++i) scanf("%I64d%d",&bcounts[i],&btypes[i]);

		bool extra = false;
		if(2 == n)
		{
			if(atypes[0] == atypes[1])
			{
				n = 1;
				acounts[0] += acounts[1];
			}
		}
		else if(3 == n)
		{
			if(atypes[0] == atypes[1] && atypes[0] == atypes[2])
			{
				n = 1;
				acounts[0] += acounts[1] + acounts[2];
			}
			else if(atypes[0] == atypes[1])
			{
				n = 2;
				acounts[0] += acounts[1];
				atypes[1] = atypes[2];
				acounts[1] = acounts[2];
			}
			else if(atypes[1] == atypes[2])
			{
				n = 2;
				acounts[1] += acounts[2];
			}
			else if(atypes[0] == atypes[2])
			{
				extra = true;
			}
		}

		unsigned long long ans = 0;
		if(1 == n) ans = solve_1(bcounts,btypes,acounts,atypes);
		else if(2 == n) ans = solve_2(bcounts,btypes,acounts,atypes);
		else if(3 == n)
		{
			ans = solve_3(bcounts,btypes,acounts,atypes);
			if(extra)			// atypes[0] == atypes[2]
			{
				acounts[0] += acounts[2];
			}
			unsigned long long x = solve_1(bcounts,btypes,acounts,atypes);
			if(x > ans) ans = x;
		}

		printf("Case #%u: %I64u\n",iCases,ans);
	}
	return 0;
}