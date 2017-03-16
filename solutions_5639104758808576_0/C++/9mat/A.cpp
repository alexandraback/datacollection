#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define FOR(i,n) for(int i = 0, n_ = (n); i < n_; i++)
#define ITER(it,v) for(auto it = (v).begin(); it != (v).end(); ++it)


using namespace std;


int main(){
	int T, Smax;
	string S;

	cin>>T;

	FOR(icase, T){
		cin>>Smax>>S;
		vector<int> a(Smax+1);

		int invite = 0;

		FOR(i,Smax+1) a[i] = S[i] - '0';
		for(int i = 1; i<Smax+1; i++) {
			if(a[i-1] < i){
				invite += i-a[i-1];
				a[i] += i;
			}
			else a[i] += a[i-1];
		}

		cout<<"Case #"<<icase+1<<": "<<invite<<endl;
	}
}