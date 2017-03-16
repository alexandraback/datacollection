#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>


#define FOR(i,N) for(int i=0, n_=(N); i<n_; i++)

using namespace std;

long long reverse(long long N){
	long long r = 0;
	while(N>0){
		r *= 10;
		r += (N%10);
		N /= 10;
	}

	return r;
}


long long pow10[16], countpow10[16];
long long ten = 10;

long long process(long long N){
	if(N%10 == 0) return process(N-1) + 1;

	int k;
	for(k = 0; k < 15; k++) if(pow10[k] > N) break;

	long long count = countpow10[k-1];

	count += N % pow10[(k+1)/2];

		//cout<<k<<" "<<N/pow10[(k+1)/2]<<" "<<pow10[k-1-(k+1)/2]<<endl;
	if(k>1 && N/pow10[(k+1)/2] != pow10[k-1-(k+1)/2]) 
		count += reverse(N/pow10[(k+1)/2]);

	return count;

}

long long process2(long long N){
	vector<bool> mark(2000000, true);
	queue<pair<long long, long long> > q;

	if(N==1)
		return 1;

	q.push(make_pair((long long)1,(long long)1));
	mark[1] = false;

	while(!q.empty()){
		pair<long long, long long> a = q.front();
		q.pop();
		if(mark[a.first+1]){
			if(a.first+1 == N) return a.second + 1;
			mark[a.first+1] =false;
			q.push(make_pair(a.first+1, a.second + 1));
		}
		long long r = reverse(a.first);
		if(mark[r]){
			if(r == N) return a.second + 1;
			mark[r] = false;
			q.push(make_pair(r, a.second+1));
		}
	}

	return -1;
}


int main(){
	int T,k;
	long long N;
	cin>>T;


	pow10[0]=1;
	FOR(i,15) pow10[i+1] = pow10[i]*ten;

	countpow10[0] = 0;
	countpow10[1] = 10;
	for(k = 2; k < 16; k++) countpow10[k] = countpow10[k-1] + pow10[(k+1)/2] + pow10[k-(k+1)/2] - 1;


	FOR(t,T){
		cin>>N;

		cout<<"Case #"<<t+1<<": "<<process(N)<<endl;
	}

	return 0;
}