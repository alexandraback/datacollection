#include<iostream>
using namespace std;

int solve() {
	int a,b,k;
	cin>>a>>b>>k;
	int lkm = 0;
	for(int i=0;i<a;i++) {
		for(int j=0;j<b;j++) {
			if ((i&j)<k) {
				lkm++;
			}
		}
	}
	return lkm;
}

int main() {
	int a;
	cin>>a;
	for(int i=0;i<a;i++) {
		cout<<"Case #"<<(i+1)<<": "<<solve()<<endl;
	}
}
