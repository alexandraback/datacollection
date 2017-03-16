#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

long int pow10(int a){
	int p=1;
	for(int i=0; i<a; i++)
		p *= 10;
	return p;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		string s;
		cin >> s;
		int m = s.length();
		int n[m];
		for(int j=0; j<m; j++)
			n[j] = s[j]-'0';
		if(m == 1){
			printf("Case #%d: %d\n",i+1,n[0]);
			continue;
		}
		long int ans = 0;
		if(n[m-1] == 0){
			n[m-1]--;
			for(int j=m-1; j>0; j--)
				if(n[j] < 0){
					n[j] = 9;
					n[j-1]--;
				}
			ans = 1;
		}
		for(int j=1; j<m; j++)
			ans += pow10(j-1)+9;
		int swap = 0;
		if(n[0] > 1){
			swap++;
			ans += n[0]-1;
		}
		for(int j=1; j<m-1; j++){
			if(n[j] == 0)
				continue;
			if(j < m-j-1){
				swap+=2;
				ans += n[j]*pow10(j);
			}else{
				ans += n[j]*pow10(m-j-1);
			}
		}
		ans += n[m-1];
		ans += swap;
		printf("Case #%d: %ld\n",i+1,ans);
	}
	return 0;
}
