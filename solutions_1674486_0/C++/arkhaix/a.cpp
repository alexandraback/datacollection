#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
 
using namespace std;
 
typedef vector<bool> VB; typedef vector<double> VD;
typedef vector<int> VI; typedef vector<string> VS;

typedef unsigned int uint;
typedef unsigned long long ull;

vector< vector<int> > inherits;

int main(void)
{
	string line;
	uint numTests;
	stringstream ss;

	getline(cin, line);
	ss << line;
	ss >> numTests;
	ss.clear();

	for(uint testCase=0; testCase < numTests; testCase++)
	{
		int numClasses = 0;
		getline(cin, line);
		ss << line;
		ss >> numClasses;
		ss.clear();

		inherits.clear();

		for(int nc=0;nc<numClasses;nc++)
		{
			int numParents = 0;
			getline(cin, line);
			ss << line;
			ss >> numParents;

			vector<int> parents;
			for(int np=0;np<numParents;np++)
			{
				int parent;
				ss >> parent;
				parent--;
				parents.push_back(parent);
			}
			ss.clear();

			inherits.push_back(parents);
		}

//		for(int i=0;i<inherits.size();i++) {
//			printf("[%d]: ", i);
//			for(int j=0;j<inherits[i].size();j++) {
//				printf("%d ", inherits[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");

		bool found = false;
		for(int nc=0;nc<numClasses;nc++)
		{
			bool visited[1001] = {false};
			queue<int> q;

			q.push(nc);
			visited[nc]=true;

			//printf("[%d] ", nc);
			while(!q.empty() && found==false)
			{
				int cur=q.front();
				q.pop();
				//printf("%d ", cur);
				for(int np=0;np<inherits[cur].size();np++)
				{
					int parent = inherits[cur][np];
					q.push(parent);
					//printf("%d ", parent);
					if(visited[parent] == true) {
						found=true;
						break;
					}
					visited[parent] = true;
				}
			}
				//printf("\n");
		}

		printf("Case #%d: ", testCase+1);
		if(found)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

