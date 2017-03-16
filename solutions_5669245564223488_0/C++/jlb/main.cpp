#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <iterator>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <random>
#include <limits>
#include <cmath>

using namespace std;
#define FOR(i,n) for(size_t i=0;i<(size_t)(n);i++)
#define REP(i,n,m) for(size_t i=(size_t)(n);i<(size_t)(m);i++)
#define REPR(i,n,m) for(size_t i=(size_t)(n);i>(size_t)(m);i--)
#define MF(i,val) memset(i,val,sizeof(i))
#define MP(a,b) make_pair((a),(b))
typedef  pair<int,int> ipair;
//typedef __int64 int64;
typedef long long int64;
typedef unsigned long long uint64;
template<class T> T min_val(T val,T&minVal){return minVal=min(val,minVal);}
template<class T> T max_str(T val,T&maxVal){return maxVal=max(val,maxVal);}
typedef pair<uint64,uint64> lpair;


uint64 gcd(uint64 a,uint64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}

const int MAX_N=101;
const int MAX_M='z'-'a'+1;
const uint64 mod=1000000007;
vector<char> strs[MAX_N];
vector<int> strIndexs[MAX_M];
vector<int> strIndexsPre[MAX_M];
vector<int> strIndexsSuff[MAX_M];
vector<int> strIndexsIn[MAX_M];
bool masks[MAX_M];
int colors[MAX_M];
vector<int> nodes[MAX_M];
uint64 tables[MAX_N];

void init(){
	tables[0]=1;
	REP(i,1,MAX_N){
		tables[i]=(i*tables[i-1])%mod;
	}
}

void simplify(string& tmp,int index){
	vector<char>& vec=strs[index];
	vec.clear();
	vec.push_back(tmp[0]);
	FOR(i,tmp.size()-1){
		if(tmp[i]!=tmp[i+1]){
			vec.push_back(tmp[i+1]);
		}
	}
}

int dfs(int root,int& nextColor){
	vector<int>& nexts=nodes[root];
	masks[root]=false;
	if(nexts.empty()){
		nextColor++;
		colors[root]=nextColor;
		return nextColor;
	}
	if(!masks[nexts[0]]){
		colors[root]=colors[nexts[0]];
		return colors[root];
	}else{
		colors[root]=dfs(nexts[0],nextColor);
		return colors[root];
	}
}

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	std::ios::sync_with_stdio(false);
	int TC,ans;
	cin>>TC;
	init();
	FOR(tc,TC){
		int N;
		cin>>N;
		string tmp;
		bool flag=true;
		MF(masks,true);
		MF(colors,-1);
		FOR(i,MAX_M){
			strIndexs[i].clear();
			strIndexsPre[i].clear();
			strIndexsSuff[i].clear();
			strIndexsIn[i].clear();
			nodes[i].clear();
		}
		FOR(i,N){
			cin>>tmp;
			simplify(tmp,i);
			if(flag){
				vector<char>& str=strs[i];
				if(str.size()==1){
					strIndexs[str[0]-'a'].push_back(i);
				}else{
					if(str.size()>2)
					REP(j,1,str.size()-1){
						strIndexsIn[str[j]-'a'].push_back(i);
					}
					if(str.back()!=str[0]){
						strIndexsPre[str[0]-'a'].push_back(i);
						strIndexsSuff[str.back()-'a'].push_back(i);
						nodes[str[0]-'a'].push_back(str.back()-'a');
					}else{
						flag=false;
					}

				}
			}
		}

		FOR(i,MAX_M){
			if(strIndexsPre[i].size()>1||
				strIndexsSuff[i].size()>1||
				strIndexsIn[i].size()>1||
				(strIndexsIn[i].size()==1&&(strIndexsPre[i].size()+strIndexsSuff[i].size()+strIndexs[i].size()!=0))){
				flag=false;
				break;
			}
		}

		if(!flag){
			cout<<"Case #"<<tc+1<<": 0"<<endl;
		}else{			
			int nextColor=-1;
			FOR(i,MAX_M){
				if(masks[i]&&(strIndexs[i].size()+strIndexsPre[i].size()+strIndexsSuff[i].size()!=0)){
					dfs(i,nextColor);
				}				
			}
			uint64 val=tables[nextColor+1];
			FOR(i,MAX_M){
				if(strIndexs[i].size()>1)
					val=(val*tables[strIndexs[i].size()])%mod;
			}
			cout<<"Case #"<<tc+1<<": "<<val<<endl;
		}

		
	}
	return 0;
}