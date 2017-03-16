#include <bits/stdc++.h>
using namespace std;
set <int> s;
void reset(){
	s.clear();
}

void add (long long int x){
	while (x){
		s.insert(x%10);
		x/=10;
	}
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	for (int p=1; p<=t; p++) {
		reset();
		int n;
		cin>>n;
		if (n==0){
			cout<<"Case #"<<p<<": INSOMNIA"<<endl;
			continue;
		}
		long long int cur=0;
		while (1){
			cur+=(long long int) n;
			add (cur);
			if (s.size()==10){
				cout<<"Case #"<<p<<": "<<cur<<endl;
				break;
			}
		}
	}
	
	return 0;
}