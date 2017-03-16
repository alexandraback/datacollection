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

#define FOR(I,A,B) for(long long I = (A); I < (B); ++I)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

long long iabs(long long in){
	if(in<0)
		return -in;
	return in;
}

long long decide(char digit, int def){
	if(digit=='?')
		return def;
	return digit-'0';
}

int main(){
	long long T;
	cin>>T;
	FOR(iter,0,T){
		string c_judge,j_judge;
		cin>>c_judge>>j_judge;

		long long upperbound=1;
		FOR(i,0,c_judge.length()){
			upperbound*=10;
		}

		vector <long long> c_ret_arr;
		vector <long long> j_ret_arr;

		c_ret_arr.push_back(0);
		j_ret_arr.push_back(0);

		long long currentdigi=upperbound;

		FOR(i,0,c_judge.length()){
			vector <long long> c_nextcands;
			vector <long long> j_nextcands;

			currentdigi/=10;

			FOR(candid,0,c_ret_arr.size()){
				long long c_ret=c_ret_arr[candid];
				long long j_ret=j_ret_arr[candid];

				if (c_ret>j_ret){
					c_ret+=currentdigi*decide(c_judge[i],0);
					j_ret+=currentdigi*decide(j_judge[i],9);
					c_nextcands.push_back(c_ret);
					j_nextcands.push_back(j_ret);
					continue;
				}

				if (c_ret<j_ret){
					c_ret+=currentdigi*decide(c_judge[i],9);
					j_ret+=currentdigi*decide(j_judge[i],0);
					c_nextcands.push_back(c_ret);
					j_nextcands.push_back(j_ret);
					continue;
				}

				if(c_judge[i]!='?' && j_judge[i]!='?'){
					c_ret+=currentdigi*decide(c_judge[i],0);
					j_ret+=currentdigi*decide(j_judge[i],0);
					c_nextcands.push_back(c_ret);
					j_nextcands.push_back(j_ret);
					continue;
				}

				if(c_judge[i]=='?' && j_judge[i]=='?'){
					c_nextcands.push_back(c_ret);
					j_nextcands.push_back(j_ret);

					c_nextcands.push_back(c_ret+currentdigi);
					j_nextcands.push_back(j_ret);

					c_nextcands.push_back(c_ret);
					j_nextcands.push_back(j_ret+currentdigi);
					continue;
				}

				if(c_judge[i]=='?' && j_judge[i]!='?'){
					int j_decided=j_judge[i]-'0';
					int j_decided_add=j_judge[i]-'0'+1;
					int j_decided_sub=j_judge[i]-'0'-1;

					if(j_decided_add>9)
						j_decided_add=9;

					if(j_decided_sub<0)
						j_decided_sub=0;

					c_nextcands.push_back(c_ret+j_decided_add*currentdigi);
					j_nextcands.push_back(j_ret+j_decided*currentdigi);

					c_nextcands.push_back(c_ret+j_decided*currentdigi);
					j_nextcands.push_back(j_ret+j_decided*currentdigi);

					c_nextcands.push_back(c_ret+j_decided_sub*currentdigi);
					j_nextcands.push_back(j_ret+j_decided*currentdigi);
					continue;
				}
				if(j_judge[i]=='?' && c_judge[i]!='?'){
					int c_decided=c_judge[i]-'0';
					int c_decided_add=c_judge[i]-'0'+1;
					int c_decided_sub=c_judge[i]-'0'-1;

					if(c_decided_add>9)
						c_decided_add=9;

					if(c_decided_sub<0)
						c_decided_sub=0;

					c_nextcands.push_back(c_ret+c_decided*currentdigi);
					j_nextcands.push_back(j_ret+c_decided_add*currentdigi);

					c_nextcands.push_back(c_ret+c_decided*currentdigi);
					j_nextcands.push_back(j_ret+c_decided*currentdigi);

					c_nextcands.push_back(c_ret+c_decided*currentdigi);
					j_nextcands.push_back(j_ret+c_decided_sub*currentdigi);
					continue;
				}


			}

			c_ret_arr=c_nextcands;
			j_ret_arr=j_nextcands;
		}

		long long c_actual=c_ret_arr[0];
		long long j_actual=j_ret_arr[0];

		FOR(i,0,c_ret_arr.size()){
			if(iabs(c_actual-j_actual)>iabs(c_ret_arr[i]-j_ret_arr[i])){
				c_actual=c_ret_arr[i];
				j_actual=j_ret_arr[i];
			}
			if(iabs(c_actual-j_actual)==iabs(c_ret_arr[i]-j_ret_arr[i]) && c_actual>c_ret_arr[i]){
				c_actual=c_ret_arr[i];
				j_actual=j_ret_arr[i];
			}
			if(iabs(c_actual-j_actual)==iabs(c_ret_arr[i]-j_ret_arr[i]) && c_actual==c_ret_arr[i] && j_actual>j_ret_arr[i]){
				c_actual=c_ret_arr[i];
				j_actual=j_ret_arr[i];
			}
		}


		
		cout<<"Case #"<<iter+1<<": ";

		long long digi=upperbound;
		FOR(i,0,c_judge.length()){
			cout<<(c_actual%digi)/(digi/10);
			digi/=10;
		}
		cout<<' ';
		digi=upperbound;
		FOR(i,0,j_judge.length()){
			cout<<(j_actual%digi)/(digi/10);
			digi/=10;
		}

		cout<<endl;
	}
}
