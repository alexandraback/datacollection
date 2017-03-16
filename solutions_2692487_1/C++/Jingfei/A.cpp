#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int mote[105];

int main(){
	int T;
	scanf("%d",&T);
	for(int Case=1; Case<=T; Case++){
		int A,N;
		scanf("%d%d",&A,&N);
		for(int i=0; i<N; i++) scanf("%d",&mote[i]);
		sort(mote,mote+N);
		int tmp=A;
		int ans1=0, ans2=0, Ans=1e9;
		for(int i=0; i<N; i++){
			if(mote[i]<tmp) tmp+=mote[i];
			else{
				ans2=N-i;
				ans1++;
				tmp+=(tmp-1);
				if(tmp-1==0){
					i++;
				}
				i--;
				Ans=min(Ans,ans2+ans1-1);
			}
			ans2=N-i;
			Ans=min(Ans,ans2+ans1-1);
		}
		if(Ans==1e9) Ans=0;
		printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}
