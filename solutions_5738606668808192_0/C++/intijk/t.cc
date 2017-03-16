#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

vector<long long> primes;

void genPrimes(){
	int maxN=65537;
	vector<bool> check(maxN+1);
	int nPrime=0;
	for( int i = 2 ; i <= maxN ; ++i ){
		if(!check[ i ] )
			primes.push_back(i);
		for(int j=0;j<primes.size();++j){
			if( i*primes[ j ] > maxN )
				break;
			check[ i * primes[ j ] ] = 1;
			if( i % primes[ j ] == 0 ) break;
		}
	}
}
long long toNum(string &s, int base){
	long long res=0;
	for(int i=0;i<s.size();i++){
		res=res*base;
		if(s[i]=='1'){
			res+=1;
		}
	}
	return res;
}
void fits(int n, string& s){
	for(int p=0,i=s.size()-2;i>=1;i--,p++){
		s[i]=((n>>p) & 1) + '0';
	}
}
int main(int argc, const char *argv[])
{
	int T,N,J;
	cin>>T>>N>>J;
	string s(N,'0');
	s[0]=s[N-1]='1';

	genPrimes();
	cout<<"Case #1:"<<endl;
	
	int nfound=0;
	vector<long long> divisors;
	for(int i=0;i<(1<<(N-2));i++){
		fits(i,s);
		//cout<<"test "<< s<<endl;
		divisors.clear();
		
		bool legi=true;	
		for(int base=2;base<=10;base++){
			long long num=toNum(s, base);
			//cout<<"base "<<base<<" "<<num<<endl;
			int sqr=ceil(sqrt(num));
			bool found=false;
			for(auto p:primes){
				if(p<=sqr){
					if(num%p==0){
						divisors.push_back(p);	
						found=true;
						break;
					}
				}
			}
			if(!found){
				legi=false;
				break;
			}
		}
		if(legi){
			cout<<s;
			for(auto d:divisors){
				cout<<" "<<d;
			}	
			cout<<endl;
			if(++nfound>=J){
				break;
			}
		}	
	}

	return 0;
}

