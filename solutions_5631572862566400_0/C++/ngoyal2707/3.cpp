
// Author: ngoyal2707

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define FORALL(i,a,b)               for(decltype(a) i=a;i<b;i++)
#define FORALLR(i,a,b)               for(decltype(a) i=a;i>=b;i--)
#define FOREACH(v, c)               for( decltype( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define FOREACHR(v, c)               for( decltype( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define PRINT1(x) cout<<"Passed Argument is:  "<<x<<"\n";
#define PRINT2(x,y) cout<<"1st value:  "<<x<<"\t2st value:  "<<y<<"\n";
#define PRINT3(x,y,z) cout<<"1st value:  "<<x<<"\t2st value:  "<<y<<"\t3st value:  "<<z<<"\n";
#define PRINT4(x,y,z,w) cout<<"1st value:  "<<x<<"\t2st value:  "<<y<<"\t3st value:  "<<z<<"\t4th value:  "<<w<<"\n";
#define PRINTEACH(v) FOREACH(it,v){ cout<<*it<<"\t"; } cout<<"\n";
#define PRINTEACH2(v) FOREACH(it,v){ FOREACH(it1,it){ cout<<*it1<<"\t"; } cout<<"\n"};
#define ALL(a)                      a.begin(), a.end()
#define IN(a,b)                     ( (a).find(b) != (a).end())
#define SIZE(a)                       ((int)(a.size()))
#define PRESENT(v,c)				((v).find(c)!=(v).end())
#define FIND(v,c)					v.find(c)-v.begin()
// #define make_pair MP

using namespace std;
typedef long long int LL;
typedef long int L;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<string> vs;
typedef vector<long> vl;
typedef vector<vector<long>> vvl;
typedef vector<long long int> vll;
typedef vector<vector<long long int>> vvll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<LL,LL>> vpll;

int largestCircle(vi & best, int N){
	vi visited(N,0);
	int result = -1;
	FORALL(i,0,N){
		if(!visited[i]){
			vi thisPath(N,0);
			visited[i]=1;
			thisPath[i]=1;

			int friendNode = best[i];
			while(!thisPath[friendNode] && !visited[friendNode]){
				thisPath[friendNode] =1;
				friendNode = best[friendNode];
			}

			if(thisPath[friendNode]==1){
				int circleLength = 1;
				int start = friendNode;
				friendNode = best[friendNode];
				while(friendNode != start){
					circleLength++;
					friendNode = best[friendNode];
				}
				result=max(result, circleLength);
			}
		}
	}
	// PRINT1(result)
	return result;
}
int dfs(vvi &undir, int N, int index, int skip){
	int len=1;
	int maxLen = 0;
	FORALL(i,0, SIZE(undir[index])){
		if(undir[index][i]!=skip){
			maxLen= max(maxLen,dfs(undir, N,undir[index][i], skip));
		}
	}
	return len + maxLen;
}
int getPairSum(vvi &undir, int N, int one, int two){
	// int len1 = 0;
	int len1 = dfs(undir, N, one, two);
	int len2 = dfs(undir, N, two, one);
	return len2+len1;
}
int main(){
	int T;
	cin>>T;
	int test_case = 1;
	while(T--){
		int N;
		cin>>N;
		vi best(N,-1);
		vvi undir(N,vi());
		vpi pair_edges;
		FORALL(i,0,N){
			cin>>best[i];
			best[i]--;

			if(best[best[i]]==i){
				pair_edges.push_back(make_pair(i, best[i]));
			}
			undir[best[i]].push_back(i);
		}


		int result= largestCircle(best, N);
		int pairSum = 0;
		FOREACH(it, pair_edges){
			// PRINT2(it->first, it->second)
			int result2 = 0;
			result2 = getPairSum(undir, N, it->first, it->second);
			pairSum += result2;
		}
		// PRINT2(result,pairSum)
		result = max(result, pairSum);
		cout<<"Case #"<<test_case<<": "<<result<<"\n";
		test_case++;
	}
}
