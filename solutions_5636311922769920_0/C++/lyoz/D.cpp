#include <bits/stdc++.h>
using namespace std;

void solve_small(int k,int c,int s)
{
	assert(s==k);
	for(int i=0;i<s;i++){
		long long p=0;
		for(int j=0;j<c;j++)
			p=p*k+i;
		cout<<p+1<<(i<s-1?' ':'\n');
	}
}

int main()
{
	int T; cin>>T;
	for(int _case=1;_case<=T;_case++){
		cout<<"Case #"<<_case<<": ";
		int k,c,s; cin>>k>>c>>s;
		if(s<k){
			cout<<"give up"<<endl;
			continue;
		}
		solve_small(k,c,s);
	}
}
