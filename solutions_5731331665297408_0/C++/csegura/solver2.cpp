#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

bool solved = false;
string solution;

bool checkSolution(vector<int> &cities, vector < vector < int > > &connections){
	stack<int> stack;
	stack.push(cities[0]);
	int nextIndex = 1;
	while((stack.size() && (nextIndex != cities.size()))){
		if (connections[stack.top()][cities[nextIndex]]){
			stack.push(cities[nextIndex]);
			nextIndex++;
		} else {
			stack.pop();
		}
	}
	return (nextIndex == cities.size());
}

int main(){
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		int n;//cities
		cin >> n;
		int m;//numero de viajes bidireccionales
		cin >> m;
		vector<string> postalCodes;
		for (int i = 0; i < n; i++){
			string code;
			cin >> code;
			postalCodes.push_back(code);
		}
		vector < vector<int> > connections(postalCodes.size(), vector<int>(postalCodes.size(), 0));

		for (int i = 0; i < m; i++){
			int from, to;
			cin >> from >> to;
			from--;
			to--;
			connections[from][to] = 1;
			connections[to][from] = 1;
		}
		vector<int> cities;
		for (int i = 0; i < n; i++){
			cities.push_back(i);
		}
		bool solved = false;
		string solution;
		do {
			/*cout << "Prueba" << endl;
			for (int i = 0; i < cities.size(); i++){
				cout << cities[i] << " ";
			}*/
			if (checkSolution(cities, connections)){
				//cout << "Encuentra" << endl;
				//Crate solution
				string tmp;
				for (int i = 0; i <cities.size(); i++){
					tmp = tmp + postalCodes[cities[i]];
				}
				if ((!solved) || (tmp < solution)){
					solution = tmp;
					solved = true;
				}
			}
		} while(next_permutation(cities.begin(), cities.end()));
		cout << "Case #" << (test+1) << ": " << solution << endl;
	}
}
