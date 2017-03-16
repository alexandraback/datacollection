#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;


static const int INF = 1<<28; 
bool usedA[10];
bool usedB[10];

void dfs(const int &N,const vector<int> &A,const vector<int> &B,int depth,int star,int cost,int &res){
	if(res<=cost)return;
	if(depth==2*N){
		res = min(cost,res);
	}
	else{
		REP(i,N){
			if(!usedB[i] && star>=B[i]){
				usedB[i] = true;
				if(!usedA[i]){
					usedA[i] = true;
					dfs(N,A,B,depth+2,star+2,cost+1,res);
					usedA[i] = false;
				}
				else{
					dfs(N,A,B,depth+1,star+1,cost+1,res);
				}
				usedB[i] = false;
			}
			else if(!usedA[i] && star>=A[i]){
				usedA[i] = true;
				dfs(N,A,B,depth+1,star+1,cost+1,res);
				usedA[i] = false;
			}

		}
	}
}

int popcount(int bit){
	return (bit?(bit&1)+popcount(bit>>1):0);
}

int small(int N,vector<int> A,vector<int> B){
	int res = INF;
	for(int bit=0 ; bit<(1<<N) ; bit++){
		vector<pair<int,int> > route;
		REP(i,N){
			if(bit>>i&1){
				route.push_back(make_pair(A[i],-1));
				route.push_back(make_pair(B[i],-1));
			}else{
				route.push_back(make_pair(B[i],-2));
			}
		}
		sort(ALL(route));
		int star = 0;
		bool ok = true;
		REP(i,route.size()){
			if(route[i].first<=star)star -= route[i].second;
			else{
				ok = false;
				break;
			}
		}
		if(ok)res = min(res,N+popcount(bit));
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int c=1 ; c<=T ; c++){
		int N;
		scanf("%d",&N);
		vector<int> A(N);
		vector<int> B(N);
		REP(i,N)scanf("%d%d",&A[i],&B[i]);
		int ans = small(N,A,B);
		printf("Case #%d: ",c);
		if(ans==INF)printf("Too Bad\n");
		else printf("%d\n",ans);
	}
	return 0;
}
