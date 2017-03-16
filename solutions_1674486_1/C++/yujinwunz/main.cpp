#include <fstream>
#include <vector>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");

int cases, classes, inherits, a;
vector <int> inherit[1001];
bool isRoot[1001], seen[1001];

bool bfs(int node){
	//returns true if diamond.
	if(seen[node]) return true;
	seen[node] = true;
	for(int i = 0; i < inherit[node].size(); i++){
		if(bfs(inherit[node][i])) return true;
	}
	return false;
}

int main(){
	in>>cases;
	for(int i = 1; i <= cases; i++){
		//init.
		for(int j = 0; j <= 1000; j++){
			inherit[j].clear();
			isRoot[j] = true;
			seen[j] = false;
		}

		//input
		in>>classes;
		for(int j = 1; j <= classes; j++){
			in>>inherits;
			for(int k = 0; k < inherits; k++){
				in>>a;
				inherit[j].push_back(a);
				isRoot[a] = false;
			}
		}
		//process.
		int numroots = 0;
		bool result = false;
		for(int j = 1; j <= classes; j++){
			if(isRoot[j]){
				for(int k = 1; k <= 1000; k++) seen[k] = false;
				if(bfs(j)) result = true;
				numroots++;
			}
		}
		//output;
		out<<"Case #"<<i<<": "<<(result?"Yes\n":"No\n");

	}
}