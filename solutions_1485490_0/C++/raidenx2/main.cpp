#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

long long solve(vector< pair<long long,int> > _nv, vector< pair<long long,int> > _mv, int _currn, int _currm)
{
	if(_currn == (int)_nv.size() || _currm == (int)_mv.size())
	{
		return 0;
	}

	if( _nv[_currn].second == _mv[_currm].second )
	{
		long long res = 0;
		res = solve(_nv, _mv, _currn+1, _currm+1) + min(_mv[_currm].first, _nv[_currn].first);
		
		if( _nv[_currn].first < _mv[_currm].first )
		{
			vector< pair<long long,int> > mvTemp (_mv);
			mvTemp[_currm].first -= _nv[_currn].first;
			res = max(solve(_nv, mvTemp, _currn+1, _currm) + _nv[_currn].first,res);
		}
		else if(_nv[_currn].first > _mv[_currm].first)
		{
			vector< pair<long long,int> > nvTemp (_nv);
			nvTemp[_currn].first -= _mv[_currm].first;
			res = max(solve(nvTemp, _mv, _currn, _currm+1) + _mv[_currm].first, res);
		}

		return res;
	}
	else
	{
		long long res = 0;
		res = max(solve(_nv, _mv, _currn+1, _currm), res);
		res = max(solve(_nv, _mv, _currn, _currm+1), res);
		return res;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
	int T;
	cin >> T;
	for(int cas = 1; cas <= T; ++cas)
	{
		int N, M;
		cin >> N >> M;
		vector< pair<long long,int> > nv;
		vector< pair<long long,int> > mv;
		for(int i = 0; i < N; ++i)
		{
			long long t1, t2;
			cin >> t1 >> t2;
			nv.push_back(make_pair(t1,t2));
		}

		for(int i = 0; i < M; ++i)
		{
			long long t1, t2;
			cin >> t1 >> t2;
			mv.push_back(make_pair(t1,t2));
		}

		long long res = solve(nv, mv, 0, 0);
		cout << "Case #" << cas << ": " << res << endl;
	}
	return 0;
}