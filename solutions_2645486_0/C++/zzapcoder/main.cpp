#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <map>
#include <list>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <fstream>

using namespace std;

#define ULL unsigned long long
#define ms1(m) memset((m),-1,sizeof((m)))
#define ms0(m) memset((m),0,sizeof((m)))
#define SORT(v) sort((v).begin(),(v).end())
#define CINFASTER cin.sync_with_stdio(false)
#define sz size()
#define pb(x) push_back(x)
#define mp(a,b) make_pair((a),(b))
#define all(x) (x).begin(),(x).end()

int imp [100] ;
int d[20][10000] ;
int e, r, n ;

int dp(int i, int j){
	int& ret = d[i][j] ;
	if(ret != -1) return ret ;

	if(i == n-1){
		return ret = imp[i] * j ;
	}

	for(int k=0;k<=j;++k){ // 지금 할 일[i] 에 에너지를 k 만큼 쓸겁니다. 다음 업무로 가면 r 만큼 충전됩니다. 다만 e 를 넘을 수는 없습니다.
		ret = max(ret , dp(i+1, min(e, j-k+r) ) + k*imp[i]) ;
	}
	return ret ;
}

//google codeJam~!
int main (){
	ifstream fin("B-small-attempt1.in");
	ofstream fout("output.txt");
	int tc; fin>> tc ;
	for(int k=0;k<tc; ++k){
		fin>>e>>r>>n ;
		ms1(d) ;
		for(int i=0;i<n;++i){
			fin>>imp[i] ;
		}
		fout<<"Case #"<<k+1<<": "<<dp(0, e) <<endl;
	}
	fin.close() ;
	fout.close();
	return 0;
}