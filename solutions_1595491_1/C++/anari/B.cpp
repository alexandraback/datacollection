#include <iostream>
#include <algorithm>
using namespace std;
int m[31][2];
int *dyn=new int[101], *tdyn=new int[101];
int main(){
	for (int i=0;i<=30;++i)
		m[i][0]=m[i][1]=-1;
	for (int i=0;i<=10;++i)
		for (int j=0;j<=10;++j)
			for (int k=0;k<=10;++k){
				int diff=max(max(i,j),k)-min(min(i,j),k);
				if (diff>2)
					continue;
				int t=i+j+k;
				int b=((diff==2)?1:0);
				m[t][b]=max(m[t][b], max(max(i,j),k));
			}
	int tnum;cin>>tnum;int tcou=0;
	while (tnum--){
		int n;cin>>n;
		int s;cin>>s;
		int p;cin>>p;
		for (int i=0;i<=s;++i)
			dyn[i]=-n-1;
		dyn[0]=0;
		for (int i=0;i<n;++i){
			int t;
			cin>>t;
			swap(dyn,tdyn);
			for (int j=0;j<=s;++j){
				dyn[j]=tdyn[j] + ((m[t][0] >= p) ? 1 : 0);
				if (j>0)
					dyn[j]=max(dyn[j], tdyn[j-1] + ((m[t][1] >= p) ? 1 : 0));
			}
		}
		cout<<"Case #"<<++tcou<<": "<<dyn[s]<<endl;
	}
	return 0;
}
