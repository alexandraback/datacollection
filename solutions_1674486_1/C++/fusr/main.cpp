#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <string>

using namespace std;

bool 
	solve (ifstream &in, ofstream &out) 
{
	int node_count;
	in >> node_count;

	/*vector <vector <bool>> graph;
	vector <bool> line; line.resize (node_count);
	graph.resize (node_count, line);

	int neighbour_count;
	int neighbour;
	for (int i = 1; i <= node_count; ++i) {
		in >> neighbour_count;
		for (int n = 1; n <= neighbour_count; ++n) {
			in >> neighbour;
			graph [i][n] = true;
		}
	}*/

	// list of parents for each node
	vector <vector <int>> graph;
	graph.resize (node_count, vector <int> ());

	// list of nodes without a parent
	set <int> top;


	int parent_count;
	int parent;
	for (int node = 0; node < node_count; ++node) {
		in >> parent_count;

		if (parent_count == 0)
			top.insert (node);

		for (int p = 0; p < parent_count; ++p) {
			in >> parent; 
			// numbered from 1
			parent--;
			graph [parent].push_back (node);
		}
	}

	// list of visited nodes while traversing down from top
	// if we reach some node twice, there's a diamond
		
	for (auto start = top.begin (); start != top.end (); ++start) {
		queue <int> next;
		next.push ((*start));

		vector <bool> visited;
		visited.resize (node_count, false);
		
		while (!next.empty ()) {
			int node = next.front ();
			next.pop ();

			//cout << node+1 << ":" << endl;
			//out << node+1 << ":" << endl; 
			for (auto child = graph [node].begin (); child != graph [node].end(); ++child) {				
				//cout << "  " << (*child)+1 << endl;
				//out << "  " << (*child)+1 << endl;

				next.push ((*child));

				if (visited [(*child)]) {
					//cout << "diamond by " << (*child)+1 << endl;
					//out << "diamond by " << (*child)+1 << endl;
					return true;
				}

				visited [(*child)] = true;
	
			}
		}
	}

	return false;
}

int 
	main () 
{
	ifstream in = ifstream ("in.txt");
	ofstream out = ofstream ("out.txt");

	int case_count;

	in >> case_count;

	for (int i = 1; i <= case_count; ++i) {
		if (solve (in, out)) {
			cout << "Case #" << i << ": Yes" << endl;
			out << "Case #" << i << ": Yes" << endl; 
		} else {
			cout << "Case #" << i << ": No" << endl;
			out << "Case #" << i << ": No" << endl; 
		}
	}


	in.close ();
	out.close ();

	system ("pause");
}