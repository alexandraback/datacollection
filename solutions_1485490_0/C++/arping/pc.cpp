#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstdlib>
using namespace std;
class node{public:
	long long m_char;
	long long m_count;
};
long long LCS(int i,int j,vector<node>&a,vector<node>&b){
	if(i==-1 ||j==-1)
		return 0;
	if(a[i].m_char==b[j].m_char){
		long long& ac=a[i].m_count;
		long long& bc=b[j].m_count;
		long long c=min(ac,bc);
		if(ac>bc){
			ac-=c;	long long ans=LCS(i,j-1,a,b)+c;
			ac+=c;	return ans;
		}else if(ac<bc){
			bc-=c;  long long ans=LCS(i-1,j,a,b)+c;
			bc+=c;	return ans;
		}else 
			return LCS(i-1,j-1,a,b)+c;
	}else{
		long long i1j=LCS(i-1,j,a,b);
		long long ij1=LCS(i,j-1,a,b);
		return max(i1j,ij1);
	}
}
int main() {
	int ts;cin>>ts;
	for(int t=1;t<=ts;t++){
		int N,M;cin>>N>>M;
		vector<node> a(N);	for(int k=0;k<N;k++) cin>>a[k].m_count>>a[k].m_char;
		vector<node> b(M);	for(int k=0;k<M;k++) cin>>b[k].m_count>>b[k].m_char;
		long long ans=LCS(N-1,M-1,a,b);
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}