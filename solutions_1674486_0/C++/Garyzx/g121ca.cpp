#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

int main(){
	int numCases;
	ifstream fin("g121ca.in");
	ofstream fout("g121ca.out");
	fin>>numCases;
	for(int caseNum=0; caseNum<numCases; caseNum++){
		int length;
		fin>>length;
		vector<int> children[1000];
		for(int n=0; n<length; n++){
			int m;
			fin>>m;
			for(int i=0; i<m; i++){
				int a;
				fin>>a;
				children[n].push_back(a-1);
			}
		}
		bool found=false;
		for(int n=0; n<length && !found; n++){
			bitset<1000> visited;
			visited[n]=true;
			queue<int> que;
			que.push(n);
			while(!que.empty() && !found){
				int m=que.front();
				que.pop();
				for(unsigned int i=0; i<children[m].size(); i++){
					if(!visited[children[m][i]]){
						visited[children[m][i]]=true;
						que.push(children[m][i]);
					}
					else{
						found=true;
						break;
					}
				}
			}
		}
		fout<<"Case #"<<caseNum+1<<": "<<(found?"Yes":"No")<<endl;
	}
	return 0;
}
