#include<iostream>
#include<vector>

using namespace std;

int calc(vector<int> N,int spec) {
	int n=9;
	while(!N[n]) n--;
	int nmax=n;
	if(spec>9) return n;
	for(int j=1;j<=nmax/2;j++) {
		N[nmax]--;
		N[j]++;
		N[nmax-j]++;	
		int n2=calc(N,spec+1)+1;
		n=n2<n?n2:n;
		N[nmax]++;
		N[j]--;
		N[nmax-j]--;
	}
	return n;
}

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=1; n<=nCases; n++) {
		
		vector<int> N(10,0);
		int D,P;
		cin>>D;
		for(int i=0;i<D;i++) {
			cin>>P;
			N[P]++;
		}
		int min=calc(N,0);
		
		
		cout<<"Case #"<<n<<": "<<min<<endl;
	}

	return 0;
}
