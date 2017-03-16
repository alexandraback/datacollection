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

#define LL unsigned long long
#define ms1(m) memset((m),-1,sizeof((m)))
#define ms0(m) memset((m),0,sizeof((m)))
#define SORT(v) sort((v).begin(),(v).end())
#define CINFASTER cin.sync_with_stdio(false)
#define sz size()
#define pb(x) push_back(x)
#define mp(a,b) make_pair((a),(b))
#define all(x) (x).begin(),(x).end()

LL r ;
LL howMuchPaint(LL n){
	return n*((2*r-3) + 2*(n+1)) ;
}

const LL sobig = 4000000000000000000ll;
//google codeJam~!
int main (){
	ifstream fin("A-large.in");
	ofstream fout("output.txt");
	int tc; fin>> tc ;
	for(int k=0;k<tc; ++k){
		LL t ;
		fin>> r >> t ;
		int magicNum = 100 ;
		LL hi=1000000000 , lo=0, mid ;
		if (r > 1e9){
			hi = sobig / (r/2)  ;
		}
		while(magicNum--){
			mid = (hi + lo)/2ll ;
			if( howMuchPaint(mid) > t ) hi = mid ;
			else lo = mid ;
		}
		fout<<"Case #"<<k+1<<": "<<mid << endl;
	}
	fin.close() ;
	fout.close();
	return 0;
}