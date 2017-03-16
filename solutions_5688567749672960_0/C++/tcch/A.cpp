#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int reve(int a){
	if(a%10==0) return a;
	int res = 0;
	while(a){
		res*=10;
		res+=(a%10);
		a/=10;
	}
	return res;
}

int main(){
	int T,n,L;
	freopen("A-small-attempt0.in.txt","r",stdin);
	freopen("out","w",stdout);
	cin>>T;
	int N = 1000001;
	vector<int> num(N);
	num[1] = 1;

	for(int i=2; i<N; i++){
		L = reve(i);
		if(L<i) num[i] = min(num[i-1]+1,num[L+1]);
		else num[i] = num[i-1]+1;
	}

	//for(int i=0; i<50; i++) cout<<reve(i)<<' ';

	for(int t=0; t<T; t++){
		printf("Case #%d: ", t+1);
		cin>>n;
		cout<<num[n]<<endl;
	}
	return 0;
}