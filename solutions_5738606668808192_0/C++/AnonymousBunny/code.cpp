#include <bits/stdc++.h>
using namespace std;
int a[25];

long long int two[35];
set <long long int> s;

void init(){
	two[0]= 1LL;
	for (int i=1; i<35; i++) two[i]= 2LL*two[i-1];
}

void getrand (){
	a[1]=  a[16]=1;
	for (int i=2; i<=15; i++) a[i]= 0;
	int sz=0;
	vector <int> v;
	for (int i=2; i<=15; i++){
		if (i%2) v.push_back(i);
		else{
			a[i]= rand()%2;
			sz+=a[i];
		}
	}
	random_shuffle(v.begin(), v.end());
	for (int i=0; i<sz; i++) {
		a[v[i]]=1;
	}
	int c1=0, c2=0;
	for (int i=1; i<=16; i++){
		if (i%2) c1+=a[i];
		else c2+=a[i];
	}
	long long int res=0LL;
	for (int i=1; i<=16; i++) res+=two[i]*a[i];
	if (!s.count(res)){
		for (int i=1; i<=16; i++) cout<<a[i];
		cout<<" ";
		for (int i=2; i<=10; i++) cout<<i+1<<" ";
		cout<<endl;
		s.insert(res);
	}
}



int main() {
	// your code goes here
	srand(time(0));
	init();
	cout<<"Case #1:";
	cout<<endl;
	while (s.size()<50) getrand();

	return 0;
}
