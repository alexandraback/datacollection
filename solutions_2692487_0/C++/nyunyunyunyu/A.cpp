#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int T,o,A,N,i,j,k,mote[111],ans,now;

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>T;
	while (T--){
		o++;
		cin>>A>>N;
		for (i = 1;i <= N;i++)
			cin>>mote[i];
		if (A==1){
			cout<<"Case #"<<o<<": "<<N<<endl;
			continue;
		}
		sort(mote+1,mote+N+1);
		for (i = 1;mote[i] < A;i++)A+=mote[i];
		for (ans= 1<< 30,now = 0;i <= N;i++){
			ans = min(ans, now+N-i+1);
			while (A <= mote[i]){
				now++;
				A += A-1;
			}
			A+=mote[i];
		}
		ans=min(ans, now);
		cout<<"Case #"<<o<<": "<<ans<<endl;
	}
	return 0;
}
