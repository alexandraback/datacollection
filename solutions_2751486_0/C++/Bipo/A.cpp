#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){

	//freopen("A/in.txt","r",stdin);
	//freopen("A/out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		string str;
		int n,L,cnt=0;
		cin >> str >> n;

		L = str.size();
		int *ind = new int[L+1];
		ind[L]=L;

		for(int i=L-1;i>=0;i--){
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
				cnt=0;
				ind[i]=ind[i+1];
			}else{
				if(cnt != n) cnt++;
				 if(cnt == n){
					 ind[i]=i;
				 }else{
					 ind[i]=ind[i+1];
				 }
			}
		}

		long long int sum=0;
		for(int i=0;i<=L-n;i++){
			if(ind[i]<L)
			sum += L-(ind[i]+n) + 1;
		}

		printf("Case #%d: %lld\n",t,sum);
		delete ind;
	}
}

