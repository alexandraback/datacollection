/* CodeJam 2014
 * Round 1B
 * Problem C
 * intrepid
 */
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <numeric>
#include <memory>
#include <limits>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

const int SENTINAL = numeric_limits<int>::max();

default_random_engine generator(system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distribution(1,100);
auto myRand = bind(distribution, generator);

typedef set<int> NodeSet;
struct Node
{
	int value;
	NodeSet toVisit;
};

typedef map<int, Node> NodeMap;

bool isVisitable(NodeMap& nodeMap, int from, int to)
{
	NodeSet cur_con = nodeMap[from].toVisit;
	NodeSet to_test = cur_con;
	bool have_more = true;
	while ( cur_con.count(to) == 0 && have_more )
	{
		have_more = false;
		NodeSet new_test;
		NodeSet::iterator it = new_test.begin();
		for ( int pos : to_test )
		{
			NodeSet& new_pos = nodeMap[pos].toVisit;
			NodeSet new_con;
			set_difference(new_pos.begin(), new_pos.end(), cur_con.begin(), cur_con.end(), inserter(new_test, it));
		}
		to_test = new_test;
		if ( ! to_test.empty() )
		{
			have_more = true;
			cur_con.insert(to_test.begin(), to_test.end());
		}
	}
	return cur_con.count(to) > 0;
}

void visit(NodeMap& nodeMap, NodeSet& ret_con, int from, int to)
{
	NodeSet& old_con = nodeMap[from].toVisit;
	NodeSet& dest_con = nodeMap[to].toVisit;
	
	// Update ret_con
	ret_con.insert(old_con.begin(), old_con.end());
	NodeSet new_ret_con;
	set_difference(ret_con.begin(), ret_con.end(), dest_con.begin(), dest_con.end(), inserter(new_ret_con, new_ret_con.begin()));
	ret_con = move(new_ret_con);
	ret_con.erase(to);
	
	// Update all lists
	for (pair<const int,Node>& node : nodeMap )
		node.second.toVisit.erase(to);
	
	// Output the node we just left
	cout << from;
}

bool doTest()
{
	int N, M;
	cin >> N >> M;
	NodeMap nodes;
	if ( !cin.good() ) return false;
	int value;
	vector<int> values(N);
	for (int i=0; i<N; ++i)
	{
		cin >> value;
		values[i] = value;
		nodes[value] = Node();
	}
	for (int i=0; i<M; ++i)
	{
		int c1, c2;
		cin >> c1 >> c2;
		if (!cin.good()) return false;
		int v1 = values[c1-1];
		int v2 = values[c2-1];
		nodes[v1].toVisit.insert(v2);
		nodes[v2].toVisit.insert(v1);
	}
	
	int curNode = nodes.begin()->first;
	assert( curNode != 0 );
	// Update all lists
	for (pair<const int,Node>& node : nodes )
		node.second.toVisit.erase(curNode);
	
	NodeSet retNodes;
	while ( true )
	{
		int nextNode = SENTINAL;
		int nextRet = SENTINAL;
		NodeSet& cur_con = nodes[curNode].toVisit;
		if ( ! cur_con.empty() )
			nextNode = *cur_con.begin();
		if ( ! retNodes.empty() )
			nextRet = *retNodes.begin();
		if ( nextRet < nextNode )
		{
			// Check if all my cons are still visitable by return route
			bool visitable = true;
			for ( int con : cur_con )
			{
				if ( !isVisitable(nodes, nextRet, con) )
				{
					visitable = false;
					break;
				}
			}
			if ( visitable )
				nextNode = nextRet;
		}
		else if ( nextNode == SENTINAL )
		{
			break;
		}
		
		visit(nodes, retNodes, curNode, nextNode);
		curNode = nextNode;
	}
	
	// Print last node
	cout << curNode;
	
	return true;
}

int main(int /*argc*/, char **/*argv[]*/)
{
	cout << scientific << setprecision(7);
	int runs;
	cin >> runs;
	if ( ! cin.good() )
	{
		cerr << "Error reading runs!\n" << endl;
		return 0;
	}
	for (int run=1; run <= runs; ++run) {
		cout << "Case #" << run << ": ";
		
		if ( !doTest() )
		{
			cerr << "Test case failed!" << endl;
			break;
		}
		
		cout << "\n";
	}
	if ( !cin.good() ) cerr << "Error reading!\n" << endl;
	
	return 0;
}
