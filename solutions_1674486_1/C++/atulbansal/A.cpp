#include "../../jam.h"

class node {
  public:
   node() { 
      parents.clear();
   }
   vector<int> parents;
};

bool search(vector<node> &nodes, vector<int> &visited, int i) {
  bool ret = false;
  int N = nodes.size();

  // cout << "at node " << i << "\n";

  int M = nodes[i].parents.size();
   for(int j=0;j<M;j++) {
       if(visited[nodes[i].parents[j]]) { return true; }
       else {visited[nodes[i].parents[j]] = 1;
          if (search(nodes,visited,nodes[i].parents[j])) { return true;}
       }
   }
   return false;
}

void solve(int casenum) {
   int ret = 0;
   int N;
   in >> N;
   vector<node> nodes(N);
   for(int i=0;i<N;i++) {
      int M;
      in >> M;
      int t;
      for(int j=0;j<M;j++) {
         in >> t;
         nodes[i].parents.pb(t-1);
      }
   }

   bool found = 0;

   for (int i=0;i<N;i++) {
       vector<int> visited(N,0);
       visited[i] = 1;
       // search from node i
       found = search(nodes,visited,i);

       if (found) {
          out << "Case #" << casenum << ": " << "Yes" << endl;
          return;
       }

   }

   out << "Case #" << casenum << ": " << "No" << endl;
}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("A-large.in");
	out.open("output.txt");
	int T;
	in >> T;

	for (int i = 0; i < T; i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
