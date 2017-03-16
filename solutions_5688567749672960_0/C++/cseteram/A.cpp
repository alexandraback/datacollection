#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

long long reserve(long long a) {
	long long ret=0;

	while(a>0) {
		ret = ret*10 + a%10;
		a/=10;
	}

	return ret;
}

int main() {

	int T;

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	cin>>T;
	for(int t=1 ; t<=T ; t++) {
		long long N, n=0;
		cin>>N;

		vector<int> cnt(10*N,99999999);

		for(int i=0 ; i<10 ; i++) cnt[i]=i;
		for(int i=10 ; i<=N ; i++) {
			if(reserve(reserve(i)) == i && cnt[reserve(i)]<cnt[i-1])
				cnt[i] = cnt[reserve(i)] + 1;
			else cnt[i] = cnt[i-1] + 1;
		}

		cout<<"Case #"<<t<<": ";
		cout<<cnt[N];
		cout<<"\n";
	}

	return 0;
}