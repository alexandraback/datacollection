#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>

#define FOR(i,a,b) for(i = a; i < b; ++i)

using namespace::std;

int main(){
	int T; cin>>T;
	int i; 
	FOR(i,0,T){
		long long A,N,j;
		
		int operation = 0;
		vector<long long> size;
		queue<long long> qu;
		cin>>A>>N;
		FOR(j,0,N){
			long long temp;
			cin>>temp;
			size.push_back(temp);
		}
		operation = 0;
		sort(size.begin(),size.end());
		for(j = 0; j < N; j++){
			if(A > size[j]){
				A += size[j];
			} else if ((A + A - 1) > size[j]){
				operation++;
				A += (A - 1) + size[j];
			} else {
				operation++;
				qu.push(size[j]);
				A += (A - 1);
				while(!qu.empty() && qu.front() < A ){
					A += qu.front();
					qu.pop();
				}
				
			}
			
		}
		cout<<"Case #"<<i+1<<": "<<operation<<endl;
		size.clear();
	}
	return 0;
}
