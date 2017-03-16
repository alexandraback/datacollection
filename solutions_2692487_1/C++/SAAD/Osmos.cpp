#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#define _for(i,n) for(long long i = 0; i<n; i++)
#define _fora(i,n) for(long long i = 1; i<=n; i++)
#define _forlor(i,n) for(long long i=n-1; i>=0; i--)
#define max(a,b) a<b?b:a
#define min(a,b) a>b?b:a

using namespace std;

int main(){
	freopen("in.in", "r", stdin);
	freopen("out.in", "w", stdout);

	long long tmp;
	long long T;
	cin>>T;
	_fora(t,T){
bda:
		long long A,N;
		cin>>A>>N;
		vector<long long> ens;
		_for(n,N){
			cin>>tmp;
			ens.push_back(tmp);
			sort(ens.begin(),ens.end());
		}
		if(A == 1){
			cout<<"Case #"<<t<<": "<<N<<endl;
			continue;
		}
		long long cmpt = 0;
		while(ens.size() > 1){
			tmp = ens[0];
			if(A>tmp){
				A+=tmp;
				ens.erase(ens.begin());
			}else{
				long long a = A,cmptsghira = 0;
				while(a<=tmp){
					cmptsghira++;
					a+=a-1;
				}
				if(cmptsghira<=N){
					cmpt+=cmptsghira;
					A=a;
				}else{
					cout<<"Case #"<<t<<": "<<(N+cmpt)<<endl;
					t++;
					goto bda;
				}
// 				ens.push_back(A-1);
// 				sort(ens.begin(),ens.end());
// 				ens.insert(ens.begin(), A-1);
// 				cmpt++;
			}
		}
		tmp = ens[0];
		if(A<=tmp)
			cmpt++;

		cout<<"Case #"<<t<<": "<<(min(cmpt,N))<<endl;
	}

	return 0;
}