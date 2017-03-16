#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <assert.h>
#include <string>
#include <deque>
#include <algorithm>

using std::vector;
using std::map;
using std::set;
using std::string;
using std::deque;
using std::pair;

struct data_t
{
	pair<int,int>	prev;
	int				dir;
public:
	data_t(int tx = 0,int ty = 0,int td = 0):dir(td) { prev.first = tx;prev.second = ty; }
};

int main()
{
	static const size_t dirnum = 4;
	static const int dx[dirnum] = { 0,0,1,-1 };
	static const int dy[dirnum] = { 1,-1,0,0 };
	static const char dir[dirnum] = { 'N','S','E','W'};

	vector< vector<size_t> > steps(201,vector<size_t>(201,(size_t)(-1)));
	size_t count = 1;
	typedef std::pair<int,int> pair_t;
	map<pair_t,data_t> dest[501];dest[0][pair_t(0,0)] = data_t(0,0,0);
	steps[100][100] = 0;
	for(int istep = 1;istep <= 500 && count < 201*201;++istep)
	{
		const map<pair_t,data_t>& r = dest[istep-1];
		for(map<pair_t,data_t>::const_iterator it = r.begin();it != r.end();++it)
		{
			const pair_t& u = it->first;
			for(size_t i = 0;i < dirnum;++i)
			{
				int nx = u.first + dx[i]*istep;
				int ny = u.second + dy[i]*istep;
				dest[istep][pair_t(nx,ny)] = data_t(u.first,u.second,i);;
				if(nx > 100 || nx < -100) continue;
				if(ny > 100 || ny < -100) continue;
				if(steps[nx+100][ny+100] != (size_t)(-1)) continue;
				steps[nx+100][ny+100] = istep;
				++count;
			}
		}
		//printf("%d %d\n",istep,dest[istep].size());
	}
	//printf("aaaa\n");


	unsigned int nCases = 0;scanf("%d",&nCases);


	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int x = 0,y = 0;scanf("%d%d",&x,&y);
		int k = steps[x+100][y+100];
		pair_t p(x,y);
		string ret = "";
		for(;p.first != 0 || p.second != 0;--k)
		{
			const map<pair_t,data_t>::const_iterator itFind = dest[k].find(p);
			p = itFind->second.prev;
			ret.push_back(dir[itFind->second.dir]);
		}
		std::reverse(ret.begin(),ret.end());

		printf("Case #%u: %s\n",iCases,ret.c_str());
	}
	return 0;
}