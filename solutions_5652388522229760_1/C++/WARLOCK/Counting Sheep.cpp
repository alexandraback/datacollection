#include <bits/stdc++.h>

using namespace std;

inline void setH(int h[],long long n){
	while(n!=0){
		h[n%10]=1;
		n/=10;
	}
}
inline bool valid(int h[]){
	for(int i=0;i<10;i++)
		if(h[i] == 0)
			return true;
	return false;
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A.txt","w",stdout);
	int t = 1000000;
	long long n = 0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int h[10];
		memset(h,0,sizeof h);
		cout<<"Case #"<<i<<": ";
		if(n == 0){
			cout<<"INSOMNIA\n";
			continue;
		}
		long long k = 1;
		while(valid(h)){
			setH(h,n*k);
			k++;
		}
		cout<<(k-1)*n<<"\n";
	}
	fflush(stdout);
	return 0;
}