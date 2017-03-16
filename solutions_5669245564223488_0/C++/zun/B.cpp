#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool flag;
set<int> alpha[26];
string A[101];
long long int counter;
long long int mod;
long long int fact(long long int x) {
  long long int temp=1;
	while(x>1) {
	  temp*=x;
		x--;
		temp%=mod;
	}
	return temp;
}

long long int compute(int x) {
  if(alpha[x].size()==0) {
	  return 0;
	}
	bool left = false;
	char lefty,righty;
	bool right = false;
	for(set<int>::iterator it=alpha[x].begin(); it!=alpha[x].end(); it++) {
		int p = *it;
		int i=0;
					//cout<<A[p]<<endl;
		if(A[p][i]-97!=x) {
			if(left) {
				flag=false;
				return 0;
			}
			else {
				left = true;
				lefty = A[p][i];
				while(A[p][i]-97!=x) {
					i++;
				}
				while(A[p][i]-97==x) {
					if(i==A[p].size()-1) {
						i++;
						break;
					}
					i++;
				}
				if(i!=A[p].size()) {
				  if(alpha[x].size()!=1) {
						flag = false;
						return 0;
					}
					else {
						right = true;
						righty = A[p][i];
					}
				}
			}
		}
		else {
			while(A[p][i]-97==x) {
				if(i==A[p].size()-1) {
				  i++;
					break;
				}
				i++;
			}
			if(i!=A[p].size()) {
				if(right) {
					flag = false;
					return 0;
				}
				else {
					right = true;
					righty = A[p][i];
					for( ;i<A[p].size(); i++) {
						if(A[p][i]-97==x) {
								flag = false;
								return 0;
						}
					}
				}
			}
			//else cout<<"nothing is done"<<endl;
		}
	}
	if(left && right &&lefty==righty) {
	  flag = false;
		return 0;
	}
		long long int num = (alpha[x].size());
		num-=2;
		if(!left) {
		  num++;
			counter++;
		}
		if(!right) {
		  num++;
			counter++;
		}
		return num;
}
			

int main() {
  ifstream fin("B.in");
	ofstream fout("B.out");
	int t;
	mod = 1000000007;
	fin>>t;
	for( int tt=0; tt<t; tt++) {
		for(int i=0; i<26; i++) {
			alpha[i].clear();
		}
		flag = true;
		counter =0;
		int N;
		long long int ans[26];
		fin>>N;
		for(int i=0; i<N; i++) {
		  fin>>A[i];
			for( int j=0; j<A[i].size(); j++) {
			  alpha[A[i][j]-97].insert(i);
			}
		}
		for( int i=0; i<26; i++) {
			if(flag) {
				ans[i] = compute(i);
				ans[i] = fact(ans[i]);
				//cout<<i<<" "<<ans[i]<<endl;
			}
		}
		counter /=2;
		counter = fact(counter);
		for( int i=0; i<26; i++) {
		  counter*=ans[i];
			counter%=mod;
		}
		if(!flag)
		counter = 0;
		fout<<"Case #"<<tt+1<<": "<<counter<<endl;
	}
}