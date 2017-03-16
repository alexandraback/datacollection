#include <stdio.h>
#include <vector>
#include <string>
#include <deque>
#include <map>

using std::vector;
using std::string;
using std::deque;
using std::map;

typedef std::pair<unsigned int,unsigned int> pair_t;
typedef std::pair<pair_t,unsigned int> truple_t;

void slove_small(unsigned int r,unsigned int c,map<truple_t,string>& ans)
{
	unsigned int size = r*c,maxmask = 1<<size;
	for(unsigned int imask = 0;imask < maxmask;++imask)
	{
		vector< vector<char> > board(r,vector<char>(c,'.'));
		size_t mine_count = 0;
		for(unsigned int ibit = 0;ibit < size;++ibit)
		{
			if(0 == (imask&(1<<ibit))) continue;
			board[ibit/c][ibit%c] = '*';
			++ mine_count;
		}

		vector< vector<char> > src_board = board;

		truple_t tp(pair_t(r,c),mine_count);
		if(ans.find(tp) != ans.end()) continue;

		static const size_t dir_num = 8;
		static const int dx[dir_num] = { -1,-1,-1,0,0,1,1,1 };
		static const int dy[dir_num] = { -1,0,1,-1,1,-1,0,1 };

		// count mine
		for(unsigned int i = 0;i < r;++i)
		{
			for(unsigned int k = 0;k < c;++k)
			{
				if(board[i][k] == '*') continue;

				size_t count = 0;
				for(unsigned int d = 0;d < dir_num;++d)
				{
					int nx = i + dx[d],ny = k + dy[d];
					if(nx < 0 || nx >= r) continue;
					if(ny < 0 || ny >= c) continue;
					count += (board[nx][ny] == '*');
				}
				board[i][k] = '0' + count;
				if(mine_count + 1 == size) { src_board[i][k] = 'c';board[i][k] = 'c'; }
			}
		}

		vector< vector<char> > result = board;
		deque<int> que;

		for(unsigned int i = 0;i < r && que.empty();++i)
		{
			for(unsigned int k = 0;k < c && que.empty();++k)
			{
				if(board[i][k] != '0') continue;
				que.push_back(i*c+k);
				result[i][k] = 'c';
				src_board[i][k] = 'c';
			}
		}

		for(;!que.empty();que.pop_front())
		{
			int u = que.front();
			int x = u/c,y = u%c;
			if(board[x][y] != '0') continue;

			for(unsigned int d = 0;d < dir_num;++d)
			{
				int nx = x + dx[d],ny = y + dy[d];
				if(nx < 0 || nx >= r) continue;
				if(ny < 0 || ny >= c) continue;
				if(result[nx][ny] == '*') continue;
				if(result[nx][ny] == 'c') continue;
				result[nx][ny] = 'c';
				que.push_back(nx*c+ny);
			}
		}

		bool all_ok = true;
		for(unsigned int i = 0;i < r && all_ok;++i)
		{
			for(unsigned int k = 0;k < c && all_ok;++k)
			{
				if(result[i][k] != '*' && 'c' != result[i][k]) all_ok = false;
			}
		}

		if(all_ok)
		{
			string s = "";
			for(unsigned int i = 0;i < r;++i)
			{
				for(unsigned int k = 0;k < c;++k) s.push_back(src_board[i][k]);
				s.push_back('\n');
			}
			ans[tp] = s;
		}
	}
}
int main()
{
	map<truple_t,string> ans;
	for(unsigned int r = 1;r <= 5;++r)
	{
		for(unsigned int c = 1;c <= 5;++c)
		{
			slove_small(r,c,ans);
		}
	}

	unsigned int nCases = 0;scanf("%d",&nCases);						// 1 <= nCases <= 100
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int r = 0,c = 0,m = 0;scanf("%d%d%d",&r,&c,&m);
		truple_t tp(pair_t(r,c),m);
		map<truple_t,string>::const_iterator it = ans.find(tp);
		if(it != ans.end()) printf("Case #%u:\n%s",iCases,it->second.c_str());
		else printf("Case #%u:\nImpossible\n",iCases);
	}
	return 0;
}