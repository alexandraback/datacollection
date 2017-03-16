#include <iostream>
#include <queue>  
#include <vector>   
#include <set>
#include <utility>
#include <math.h>       /* atan */
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
#define foreach(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846 
long double diff = 1e-10;

//if circle return true
bool DFS(unordered_map<int, int> &mapping, int cur, vector<int> &path, \
	unordered_set<int> &unvisited, unordered_set<int> &visited, \
	unordered_set<int> &flag, unordered_map<int, int> &status){
	
	int next = mapping[cur];
	bool retV = false; 
	if(flag.count(next) > 0){
		//detected a loop, return
		retV = true;
		path.push_back(next);
		if(path[path.size()-3] == next){
			status[next] = false;
		}
		else
			status[next] = true;
		status[cur] = status[next];
		return retV;
	}
	
	if(visited.count(next) > 0){
		status[cur] = status[next];
		return false;
	}
	
	//cout<<"path push "<<next<<endl;
	flag.insert(next);
	visited.insert(next);
	unvisited.erase(next);
	path.push_back(next);
	retV = DFS(mapping, next, path, unvisited, visited, flag, status);
	
	flag.erase(next);
	status[cur] = status[next]; 
	return retV;
}

int DFS_new(int start, int avoid, unordered_map<int, unordered_set<int>> &reverse_mapping, \
	unordered_set<int> &visited_again){
	visited_again.insert(start);
	int max_depth = 0;
	if(reverse_mapping.find(start) == reverse_mapping.end()){
		return 1; 
	}
	for(auto it = reverse_mapping[start].begin(); it!=reverse_mapping[start].end(); it++){
		if(*it == avoid)
			continue;
		int max_depth1 = DFS_new(*it, avoid, reverse_mapping, visited_again);
		max_depth = max(max_depth, max_depth1);
	}
	return max_depth+1;
}
int main(int argc, char** argv) {
	int T;
	cin>>T;
	foreach(itest, T){
		int N;
		cin>>N;
		vector<int> input(N, 0);
		unordered_map<int, int> mapping;
		for(int i=0; i<N; i++){
			cin>>input[i];
			mapping[i+1] = input[i];
		}
		
		unordered_set<int> unvisited;
		for(int i=0; i<N; i++)
			unvisited.insert(i+1);
			
		unordered_set<int> visited;
		//visit mapping, prune all the nodes outside of len>=3 circle. 
		unordered_set<int> flag;
		vector<int> path;
		
		//key is id, val is loop size. if it is true, means loop size is larger than 2. 
		unordered_map<int, int> status;
		
		int max_len_larger_3_cycle = 0;
		while(unvisited.empty() == false){
			auto it = unvisited.begin();
			int start = *it;
			unvisited.erase(start);
			visited.insert(start);
			path.push_back(start);
			flag.insert(start);
			bool retV = DFS(mapping, start, path, unvisited, visited, flag, status);
			
			//now we have a path, and
			if(retV){
				int cycle_end = path[path.size() - 1];
				if(status[cycle_end]){ //cycle size larger than 2. 
					int len = path.size()-1;
					for(int i=0; i<path.size(); i++){
						if(path[i] != cycle_end){
							mapping.erase(path[i]);
							len --;
						}
						else
							break;
					}
					max_len_larger_3_cycle = max(max_len_larger_3_cycle, len);
					for(auto item: path)
						mapping.erase(item);
				}
				//else, loop size is 2. good. 
			}
			else{
				//there is no loop
				if(status[start]) {//cycle size greater than 2 but no loop
					for(auto item: path)
						mapping.erase(item);
				}
				//else, llop size is 2, good. 
			}
			path.clear();
			flag.clear();
		}
		
		int result = max_len_larger_3_cycle;
		
		//now we have all the size 2 loops. 
		unordered_map<int, unordered_set<int>> reverse_mapping;		
		for(auto it=mapping.begin(); it!=mapping.end(); it++){
			reverse_mapping[it->second].insert(it->first);
		}

		if(reverse_mapping.size()>0)
			result = max(2, max_len_larger_3_cycle);
		
		unordered_set<int> visited_again;
		for(auto it = reverse_mapping.begin(); it!= reverse_mapping.end(); it++){
			if(visited_again.count(it->first)>0)
				continue;
			if(it->second.size()>1){
				int firstC = it->first;
				int secondC = 0;
				for(auto it1 = it->second.begin(); it1 != it->second.end(); it1++){
					secondC = *it1; 
					if(reverse_mapping.find(secondC) != reverse_mapping.end() && \
						reverse_mapping[secondC].find(firstC) != reverse_mapping[secondC].end()){
						break;		
					}	
				}
				//now we have firstC and secondC. 
				int DFS1 = DFS_new(firstC, secondC, reverse_mapping, visited_again);
				int DFS2 = DFS_new(secondC, firstC, reverse_mapping, visited_again);
				if(DFS1 + DFS2> result)
					result = DFS1 + DFS2;
			}
			
		}
		cout<<"Case #"<<itest+1<<": "<<result<<endl;
	}
	return 0;
}
