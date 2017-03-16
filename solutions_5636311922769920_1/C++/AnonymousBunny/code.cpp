#include <bits/stdc++.h>
using namespace std;


long long int k, c, s;
long long int pw[101];
set <long long int> pres;
void init(){
	pres.clear();
	pw[0]= 1LL;
	for (int i=1; i<=100; i++) pw[i]= k*pw[i-1];
}

long long int comp (vector <int> v) {
	reverse(v.begin(), v.end());
	long long int res=0LL;
	for (int i=0; i<v.size(); i++) res+=v[i]*pw[i];
	return res;
}

int uu;

void doit(){
	cin>>k>>c>>s;
	init();
	if (c*s<k){
		cout<<"Case #"<<uu<<": IMPOSSIBLE"<<endl;
		return;
	}
	int cur=0;
	for (int i=0; i<s; i++){
		vector <int> v;
		for (int j=0; j<c; j++){
			v.push_back(cur);
			cur++;
			if (cur>=k) cur= k-1;
		}
		long long int qq= comp(v);
		pres.insert(qq);
	}
	for (int i=0; i<100000; i++){
		if (pres.size()==s) break;
		if (pres.count(i)) continue;
		pres.insert(i);
	}
	cout<<"Case #"<<uu<<": ";
	for (set <long long int>::iterator it= pres.begin(); it!=pres.end(); it++) cout<<*it<<" ";
	cout<<endl;


}





int main() {
	// your code goes here
	int t;
	cin>>t;
	for (uu=1; uu<=t; uu++) doit();
	return 0;
}
