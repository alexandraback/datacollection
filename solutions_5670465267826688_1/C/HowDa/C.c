#include<iostream>
using namespace std;
int main() {
	int testcases, temp;
	cin>>testcases;
	temp=testcases;
	while(testcases--) {
		int D=0,P[2000];
		cin>>D;
		for(int i=0;i<D;i++) {
			cin>>P[i];
		}
		int ans=0;
		for(int i=0;i<D;i++) {
			if(P[i] > ans)
				ans=P[i];
		}
		int Z=2;
		while(Z<ans) {
			int total=0;
			for(int i=0;i<D;i++) {
				total+=((P[i]-1)/Z);
			}
			total+=Z;
			ans=min(ans, total);
			Z++;
		}
		cout<<"Case #"<<temp-testcases<<": "<<ans<<endl;
	}
	return 0;
}
int min(int a, int b) {
	if (a<b)
		return a;
	else
		return b;
}
