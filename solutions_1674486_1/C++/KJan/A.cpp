
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

vector<int> con[1001];
map<int,bool> visited;
//map<int,bool> started;

bool travel(int n) {

	for (int i = 0; i<con[n].size(); i++) {
		if (visited[con[n].at(i)]) {
			return true;
		}
		visited[con[n].at(i)]=true;
		
		/*
		if (started[con[n].at(i)]) {
			return false;
		}
		*/
		
		if (travel(con[n].at(i))) {
			return true;
		}
		
	}
	return false;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	
	for (int t = 1; t<=T; t++) {
		int N;
		cin >> N;
		
		for (int n = 1; n<=N; n++) {
			con[n].clear();
		}
		
		for (int n = 1; n<=N; n++) {
			int M;
			cin >> M;
			for (int m = 1; m<=M; m++) {
				int temp;
				cin >> temp;
				//cout << temp << " ";
				con[n].push_back(temp);
			}
		}
		/*
		for (int n = 1; n<=N; n++) {
			cout << n << ":\n";
			for(int m = 1; m<=con[n].size(); m++) {
				cout << con[n].at(m-1) << " ";
			}
			cout << endl;
		}
		*/
		
		visited.clear();
		//started.clear();
		
		for (int i = 1; i<=N; i++) {
			visited[i]=false;
			//started[i]=false;
		}
		
		bool diam = false;
		
		for (int i = 1; i<=N; i++) {
			visited.clear();
			//if (!visited[i]) {
				//started[i] = true;
				if (travel(i)) {
					diam = true;
					break;
				}
			//}
		}
		
		cout << "Case #" << t << ": ";
		if (diam) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		
	}
	
}
