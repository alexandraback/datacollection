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
#include <windows.h>
using namespace std;

#define ll long long
#define ms1(m) memset((m),-1,sizeof((m)))
#define ms0(m) memset((m),0,sizeof((m)))
#define SORT(v) sort((v).begin(),(v).end())
#define CINFASTER cin.sync_with_stdio(false)
#define sz size()
#define pb(x) push_back(x)
#define mp(a,b) make_pair((a),(b))
#define all(x) (x).begin(),(x).end()

const ll MAX = 1e16 ;
int n,x,y ;

double lower , upper ;

double d [101][203][203] ;
double dp(int s, int l, int r, int dn){ // dn: 쌓은 갯수
	double& ret = d[s][l][r] ;
	if(ret >= 0) return ret ;

	if(dn == n) { // 타겟블럭을 갖고있는지 확인해서 1.0 or 0.0 return ;
		if(x == 0){
			if(s-1 >= y/2) return ret = 1.0 ;
			return ret = 0.0 ;
		}
		int ds = abs(x) + y ;
		if(s*2 > ds) return ret = 1.0 ;
		if(s*2 < ds) return ret = 0.0 ;
		//s*2 == ds.
		//x 가 마이너스면 l 에서, 플러스면 r 에서 찾게 하자.
		if(x < 0){
			if(l > y) return ret = 1.0 ;
			else return ret = 0.0;
		}
		// x>0
		if(r > y) return ret  =1.0 ;
		return ret=0.0;
	}

	//답정.
	if(s*2 == l && s*2 ==r)
		return ret = dp(s+1, 0, 0, dn+1);
	if(s*2 == l)
		return ret = dp(s, l, r+1, dn+1);
	if(s*2 == r)
		return ret = dp(s, l+1, r, dn+1);

	return ret = 0.5*dp(s,l+1,r,dn+1) + 0.5*dp(s,l,r+1,dn+1) ;
}

//google codeJam~!
int main (){
	ifstream fin("B-small-attempt1.in");
	ofstream fout("output.txt");
	int tc; fin>> tc ;

	

	for(int k=0;k<tc; ++k){
		fin>>n>>x>>y ;
		ms1(d) ;
		fout<<"Case #"<<k+1<<": "<<dp(1,0,0,1)<< endl ;
	}

	fin.close() ;
	fout.close();
	return 0;
}