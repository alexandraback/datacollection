#include <iostream>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <vector>
using namespace std;

struct Node
{
	int index;
	vector<Node*> nextNode;
	set<int> from;
	int inNodeCount;

	void init()
	{
		inNodeCount = 0;
		nextNode.clear();
		from.clear();
	}
};

Node map_node[1100];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int testCase;
	cin >> testCase;
	for(int t=1; t<=testCase; ++t)
	{
		// inNode, index
		multimap<int, int> pq;
		int N, M, temp, grandChild = 1;
		cin >> N;
		for(int n=1; n<=N; ++n)
			map_node[n].init();

		for(int n=1; n<=N; ++n)
		{
			map_node[n].index = n;

			cin >> M;
			for(int m=0; m<M; ++m)
			{
				cin >> temp;
				map_node[n].nextNode.push_back( &map_node[temp] );
				map_node[n].from.insert(n);
				map_node[temp].inNodeCount++;
			}
		}

		for(int n=1; n<=N; ++n)
			pq.insert( make_pair(map_node[n].inNodeCount, n) );

		bool findflag = false;
		while( !pq.empty() )
		{
			if(findflag)
				break;
			int inCount = pq.begin()->first;
			int _index = pq.begin()->second;

			pq.erase( pq.begin() );

			for(int i=0; i<map_node[_index].nextNode.size(); ++i)
			{
				for(set<int>::iterator _itr = map_node[_index].from.begin(); 
					_itr != map_node[_index].from.end(); ++_itr )
				{
					if( map_node[_index].nextNode[i]->from.end() != map_node[_index].nextNode[i]->from.find( *_itr) )
					{
						findflag = true;
						break;
					}
					else
					{
						map_node[_index].nextNode[i]->from.insert( *_itr );
					}
				}
				if( findflag )
					break;

				vector< pair<int,int> > reinsert;
				for(multimap<int, int>::iterator _itr = pq.begin();
					_itr != pq.end();)
				{
					if( _itr->second == map_node[_index].nextNode[i]->index )
					{
						reinsert.push_back( make_pair((_itr->first)-1, _itr->second));
						multimap<int, int>::iterator _jtr = _itr;
						++_itr;
						pq.erase(_jtr);
						break;
					}
					else
						++_itr;
				}
				if( !reinsert.empty() )
					pq.insert( make_pair( reinsert[0].first, reinsert[0].second) );
			}
		}
		if( findflag )
			cout << "Case #" << t << ": Yes" << endl;
		else
			cout << "Case #" << t << ": No" << endl;
	}

	return 0;
}