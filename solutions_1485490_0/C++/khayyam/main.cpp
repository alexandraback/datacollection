#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define LL __int64
#define MIN(a,b) (((a)<(b))?(a):(b))
int N,M;
vector<pair<LL, LL> > A;
vector<pair<LL, LL> > B;

LL solve(int i0,int j0, LL used){
	if(i0==N-1){
		LL sol=0;
		for(int j=j0;j<M;++j){
			if(B[j].second==A[i0].second){
				sol+=B[j].first;
			}
		}
		return MIN(sol, A[i0].first);
	}
	LL sol=solve(i0+1, j0, 0);
	LL current=0;
	for(int j=j0;j<M;++j){
		if(B[j].second==A[i0].second){
			if(current+B[j].first<A[i0].first){
				current+=B[j].first;
				LL opc=current+solve(i0+1,j+1,0);
				if(sol<opc){
					sol=opc;
				}
			}else{
				LL opc=A[i0].first+solve(i0+1,j,A[i0].first-current);
				if(sol<opc){
					sol=opc;
				}
				break;
			}
		}
	}
	return sol;
}

int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		cin>>N>>M;
		A.clear();
		B.clear();
		for(int i=0;i<N;++i){
			LL ai,Ai;
			cin>>ai>>Ai;
			A.push_back(make_pair(ai,Ai));
		}
		for(int j=0;j<M;++j){
			LL bi,Bi;
			cin>>bi>>Bi;
			B.push_back(make_pair(bi,Bi));
		}
		LL sol=solve(0,0,0);
		cout<<"Case #"<<c<<": "<<sol<<endl;
	}
	return 0;
}

