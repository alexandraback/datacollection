#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <string>

using namespace std;

int n, m;
vector<vector<int>> route;
vector<int> state;
vector<int> returnAddress;

set<int> accessible;
vector<int> destinations;
vector<int> returnNo;

void explore(int a){
	//cout << "exploring" << a << endl;
	for (int i = 0; i < route[a].size(); i++){
		int dest = route[a][i];
		if (state[dest] == 0 && accessible.count(dest)==0){
			accessible.insert(dest);
			explore(dest);
		}
		else if (state[dest] > 0  && accessible.count(dest) == 0 && returnAddress[a]==dest){
			if (state[dest]==0)
				accessible.insert(dest);
			explore(dest);
		}
	}
	
}

int countUnexplored(){
	int count = 0;
	for (int i = 0; i < n;i++)
		if (state[i] == 0)
			count++;
	return count;
}

void addDestinations(int a, int depth){
	for (int i = 0; i < route[a].size(); i++){
		if (state[route[a][i]] == 0){
			destinations.push_back(route[a][i]);
			returnNo.push_back(depth);
		}
		//cout << zip[route[current][i]] << endl;
	}
	//now check if allowed to return
	if (returnAddress[a] != -2){
		accessible.clear();
		explore(returnAddress[a]);
		//cout << "accessible if returned:" << accessible.size() << endl;
		int unexplored = countUnexplored();
		//cout << "unexplored: " << unexplored << endl;
		if (accessible.size() == unexplored){
			//only then are we allowed to return
			cout << "allowed to return if wished" << endl;
			addDestinations(returnAddress[a],depth+1);
		}
	}
}

int main() {
	ofstream fout("lottery.out");
	ifstream fin("lottery.in");

	int t;
	fin >> t;

	for (int caseNo = 1; caseNo <= t; caseNo++){
		fout << "Case #" << caseNo << ": ";
		fin >> n >> m;
		
		vector<int> zip;
		route.clear(); state.clear(); returnAddress.clear();
		
		for (int i = 0; i < n; i++){
			int in;
			fin >> in;
			zip.push_back(in);
			route.emplace_back();
			state.push_back(0);
			returnAddress.push_back(-1);
		}

		for (int i = 0; i < m; i++){
			int a, b;
			fin >> a >> b;
			route[a - 1].push_back(b - 1);
			route[b - 1].push_back(a - 1);
		}

		//find starting point
		int lowest = 0;
		for (int i = 0; i < n; i++){
			if (zip[i] < zip[lowest]){
				lowest = i;
			}
		}
		cout << "starting " << zip[lowest] << endl;
		fout << zip[lowest];
		state[lowest] = 2;
		returnAddress[lowest] = -2;//no return address for starting place

		int current = lowest;
		int visited = 1;
		while (visited<n)
		{
			//make list of possible destinations
			destinations.clear();
			returnNo.clear();
			addDestinations(current,0);			

			//and if so then add those destinations too and etc

			//pick best destination and go there

			int bestValue = 9999999, bestDest = -1, destIndex;
			for (int i = 0; i < destinations.size(); i++){
				if (zip[destinations[i]] < bestValue){
					bestValue = zip[destinations[i]];
					bestDest = destinations[i];
					destIndex = i;
				}
			}
			if (bestDest == -1){
				cout << "wrong turn" << endl;
				return 1;
			}
			cout << "best destination:" << zip[bestDest] << " with " << returnNo[destIndex] << " returns" << endl;
			//now go there
			fout << zip[bestDest];

			for (int i = 0; i < returnNo[destIndex]; i++){
				state[current] = 2;
				current = returnAddress[current];
			}

			returnAddress[bestDest] = current;
			state[bestDest] = 1;
			current = bestDest;
			visited++;

		}

		cout << endl;
		fout << endl;
	}
	return 0;
}