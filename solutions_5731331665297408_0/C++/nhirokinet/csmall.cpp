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

	FOR(iteration,0,T){
		cout<<"Case #"<<(iteration+1)<<": ";

		int N;

		int M;
		cin>>N>>M;

		vector <string> zipcode;

		FOR(i,0,N){
			string tmp;
			cin>>tmp;
			zipcode.push_back(tmp);
		}

		int map[8][8];

		FOR(i,0,8)
			FOR(j,0,8)
			map[i][j]=0;

		FOR(i,0,M){
			int x,y;
			cin>>x>>y;
			map[x-1][y-1]=1;
			map[y-1][x-1]=1;
		}



		if(N==1){
			cout<<zipcode[0]<<endl;
			continue;
		}

		vector <string> zipcopy=zipcode;

		sort(ALL(zipcopy));

		int first;

		FOR(i,0,N){
			if(zipcode[i]==zipcopy[0])
				first=i;
		}
		
		string secondstr="z";
		int second=-1;

		FOR(i,0,N){
			if(map[first][i]==1){
				if(zipcode[i]<secondstr)
					secondstr=zipcode[i];
				second=i;
			}
		}



		vector <int> seq;

		seq.push_back(first);
		
		string ret="z";

		FOR(i,0,N){
			if(i!=first )
				seq.push_back(i);
		}

		do{
			vector <int> log;

			int visited[8];

			FOR(i,0,8)
				visited[i]=0;
			
			log.push_back(first);
			visited[first]=1;

			int fl=0;

			FOR(i,1,N){
				while(map[seq[i]][log[log.size()-1]]==0){
					if(log.size()==1){
						fl=1;
						break;
					}

					log.pop_back();
				}

				if(fl==1)
					break;

				log.push_back(seq[i]);
			}

			if(fl==1)
				continue;
			
			string cur="";

			FOR(i,0,N){
				cur+=zipcode[seq[i]];
			}

			if(cur<ret)
				ret=cur;



			

		}while(next_permutation(seq.begin()+1, seq.end()));

		cout<<ret;




		cout<<endl;
	}

}
