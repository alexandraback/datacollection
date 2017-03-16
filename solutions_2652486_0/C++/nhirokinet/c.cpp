// {{{ Boilerplate Code <--------------------------------------------------
//
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}

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

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

// }}}

int main(){
	int T;

	cin>>T;

	FOR(wholecount,1,T+1){
		cout<<"Case #"<<wholecount<<": \n";
		int R,N,M,K;

		cin>>R>>N>>M>>K;

		FOR(actualwholecount,0,R){
			vector <int> products(K);

			FOR(i,0,K)
				cin>>products[i];

			int max2=0;
			int max3=0;
			int max5=0;
			int max7=0;

			int sum2=0;
			int sum3=0;
			int sum5=0;
			int sum7=0;

			FOR(i,0,K){
				int div2=0;

				int tmp=products[i];
				while(tmp>0 && tmp%2==0){
					tmp/=2;
					div2++;
				}

				sum2+=div2;
				if(max2<div2 && div2>0)
					max2=div2;
			}
			FOR(i,0,K){
				int div3=0;

				int tmp=products[i];
				while(tmp>0 && tmp%3==0){
					tmp/=3;
					div3++;
				}

				sum3+=div3;
				if(max3<div3 && div3>0)
					max3=div3;
			}
			FOR(i,0,K){
				int div5=0;

				int tmp=products[i];
				while(tmp>0 && tmp%5==0){
					tmp/=5;
					div5++;
				}

				sum5+=div5;
				if(max5<div5 && div5>0)
					max5=div5;
			}
			FOR(i,0,K){
				int div7=0;

				int tmp=products[i];
				while(tmp>0 && tmp%7==0){
					tmp/=7;
					div7++;
				}

				sum7+=div7;
				if(max7<div7 && div7>0)
					max7=div7;
			}

			vector<int> ans;

			FOR(i,0,max5)
				ans.push_back(5);
			FOR(i,0,max7)
				ans.push_back(7);

			if(M<=5){
				FOR(i,0,max3){
					ans.push_back(3);
				}
				int anssizetmp=N-ans.size();
				FOR(i,0,max2-anssizetmp)
					ans.push_back(4);
				while(ans.size()<N)
					ans.push_back(2);


			}else if(M==8){
				FOR(i,0,max3){
					ans.push_back(i%2==0?3:6);
				}
				if(max2>=3)
					ans.push_back(8);
				else if(max2>=2)
					ans.push_back(4);
				while(ans.size()<N)
					ans.push_back(2);


			}

			FOR(i,0,ans.size()){
				cout<<ans[i];
			}
			cout<<"\n";
			


		}
	}
}
