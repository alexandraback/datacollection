#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;


bool explore(int node, map<int, set<int>* >* node_inherits, set<int>* reached) {
	map<int,set<int>* >::iterator found = node_inherits->find(node);
	set<int>* inherits = found->second;
	for(set<int>::iterator it = inherits->begin(); 
			it != inherits->end(); it++) {
		if(reached->find((*it)) != reached->end()) {
			return true;
		}
		reached->insert((*it));
	/*	cout << "reached nodes [";
		for(set<int>::iterator rit = reached->begin(); rit != reached->end(); rit++) {
			cout << (*rit);
		}
		cout << "]" << endl;*/
		bool ret = explore((*it), node_inherits, reached);
		if(ret) {
			return ret;
		}
	}
	return false;
}


int main(int argc, char** argv) {
	int N;
	cin >> N;
	/*char strN[1024];
	cin.getline(strN, 1024);
	N = atoi(strN);*/
	for(int iN=1; iN <= N; iN++) {
		int L;
		cin >> L;
		map<int,set<int>* >* clazzes = new map<int,set<int>* >();
		for(int iL=1; iL<=L; iL++) {
			set<int>* inherits = new set<int>();
			int I;
			cin >> I;
			for(int iI=0; iI<I; iI++) {
				int C;
				cin >> C;
				inherits->insert(C);
			}
			clazzes->insert( pair<int,set<int>*>(iL, inherits));
		}

		pid_t p = fork();
		if(p == 0) {
			bool ret = false;
			for(int iL=1; iL<=L; iL++) {
				set<int>* reached = new set<int>();
				ret = explore(iL, clazzes, reached);
				if(ret) {
					ret = true;
					break;
				}
			}
			string result;
			if(ret) {
				result = "Yes";
			} else {
				result = "No";
			}
			cout << "Case #" << iN << ": " << result << endl;
			exit(1);
		} else {
			waitpid(p, NULL, NULL);
		}
	}
	exit(1);
}
