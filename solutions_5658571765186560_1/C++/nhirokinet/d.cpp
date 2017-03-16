// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

int judge(int X, int R, int C) {
	if(R>C){
		int tmp=R;
		R=C;
		C=tmp;
	}

	if(X>=7)
		return 0;

	if((R*C)%X)
		return 0;

	if(X==1)
		return 1;

	if(X==2)
		return 1;

	if(X==3){
		if(R>=2 && C>=2)
			return 1;
		else
			return 0;
	}

	if(X==4){
		if(R>=3 && C>=4)
			return 1;
		else
			return 0;
	}

	if(X==5){
		if(R>=3 && C>=5)
			return 1;
		else
			return 0;
	}

	if(X==6){
		if(R>=4 && C>=6)
			return 1;
		else
			return 0;
	}

	return 0;
	
}

int main(){
	int T;
	cin>>T;

	FOR(iteration,0,T){
		cout<<"Case #"<<(iteration+1)<<": ";
		int X,R,C;
		cin>>X>>R>>C;

		cout<<(judge(X,R,C)?"GABRIEL":"RICHARD");



		cout<<endl;
	}

}
