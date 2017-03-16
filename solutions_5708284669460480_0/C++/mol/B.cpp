#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int pow(int a, int b){
	int ret = 1;
	for(int i=0; i<b; i++)
		ret *= a;
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0; t<T; t++){
		int K,L,S;
		scanf("%d%d%d",&K,&L,&S);
		string keys;
		cin >> keys;
		string target;
		cin >> target;
		int a[S];
		for(int i=0; i<S; i++)
			a[i] = 0;
		int max_banana = 0;
		double exp_banana = 0;
		for(int kk=0; kk<pow(K,S); kk++){
			string s;
			for(int i=0; i<S; i++)
				s += keys[a[i]];
			int banana = 0;
			for(int i=0; i<S-L+1; i++)
				if(s.substr(i,L) == target)
					banana++;
			if(banana > max_banana)
				max_banana = banana;
			exp_banana += (double)banana/pow(K,S);
			a[S-1]++;
			int j=S-1;
			while(a[j] >= K){
				a[j] = 0;
				a[j-1]++;
				j--;
			}
		}
		printf("Case #%d: %lf\n",t+1,(double)max_banana-exp_banana);
	}
	return 0;
}
