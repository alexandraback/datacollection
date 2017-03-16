#include <bits/stdc++.h>
using namespace std;
#define forup(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
long AA[100000];
map<int ,int > Arr;

long func() {
	int x = 5;
	return 0;
}

int main(){
int T;
cin>>T;
forup(caseT,T){
int n;
Arr.clear();
for(int i=0; i<1000; i++) {
	AA[i] = i*i;
	func();
}
vector<int>tempArr;
cin>>n;
forup(i,2*n-1){
	forup(j,n){
			int x;
			cin>>x;
			Arr[x]++;
	}
}
for(auto i:Arr){
	if(i.S%2==1){
		tempArr.push_back(i.F);
	}
}
for(int i=0; i<1000; i++) AA[i] = i*i;
sort(tempArr.begin(), tempArr.end());
cout<<"Case #"<<caseT+1<<": ";

for(auto i:tempArr)cout<<i<<" ";cout<<"\n";
}

return 0;
}