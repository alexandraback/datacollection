#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque> 
#include<ext/numeric>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<tr1/unordered_map>
#include<tr1/unordered_set>
#include<utility>
#include<vector>
using namespace std;

const string RD="Draw", RI="Game has not completed", RX="X won",RO="O won";
vector<string> A(4);
string ret;

void f(bool&d, bool&u){	
	for (int i=0;i<5;++i){
		int x=0,y=0,t=0;
		for (int j=0;j<4;++j){
			if (A[i==4?j:i][j]=='X') ++x;
			else if (A[i==4?j:i][j]=='O') ++y;
			else if (A[i==4?j:i][j]=='T') ++t;
			else d=1;
		}
		if (x==4||x>2&&t){ret=RX;u=1;goto hell;}
		if (y==4||y>2&&t){ret=RO;u=1;goto hell;}
	}
	hell:;
}

int main(){
	int ncases; cin>>ncases;
	for (int kase=1;kase<=ncases;++kase){
		for (int i=0;i<4;++i) cin>>A[i];
		bool d=0,u=0;
		for (int k=0;k<2;++k){
			f(d,u);
			for (int i=0;i<4;++i) for (int j=i;j<4;++j) swap(A[i][j],A[j][i]);			
			for (int i=0;i<2;++i) for (int j=0;j<4;++j) swap(A[i][j],A[3-i][j]);			
		}
		if (!u){
			ret=RD;
			if (d) ret=RI;
		}
		cout<<"Case #"<<kase<<": "<<ret<<endl;
	}
	return 0;
}