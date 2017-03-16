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

int main(){
	int T;
	cin>>T;

	char multiple[128][128];

	FOR(i,0,128){
		multiple['1'][i]=i;
		multiple[i]['1']=i;
	}

	multiple['i']['i']='A';
	multiple['i']['j']='k';
	multiple['i']['k']='J';

	multiple['j']['i']='K';
	multiple['j']['j']='A';
	multiple['j']['k']='i';

	multiple['k']['i']='j';
	multiple['k']['j']='I';
	multiple['k']['k']='A';

	FOR(iteration,0,T){
		cout<<"Case #"<<(iteration+1)<<": ";

		int L,X;
		cin>>L>>X;

		//if(X>15)
		//	X=15;

		string str;

		cin>>str;

		int step=0;

		int cursign=1;
		char cur='1';

		FOR(it,0,X){
			FOR(j,0,str.length()){
				cur=multiple[cur][str[j]];

				if(cur>='A' && cur<='Z'){
					cursign=-cursign;

					if(cur=='A')
						cur='1';
					else
						cur+=32;
				}

				if(cursign==1){
					if(cur-'i'==step){
						step++;
						cur='1';
					}
				}
			}
		}

		if(step==3 && cur=='1' && cursign==1)
			cout<<"YES";
		else
			cout<<"NO";







		cout<<endl;
	}

}
